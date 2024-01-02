#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <math.h>
#include <time.h>
#include <list>
#include <fstream>

using namespace sf;
using namespace std;

const int W = 1200;
const int H = 800;
float DEGTORAD = 0.017453f;

class Animation {
public:
    float Frame, speed;
    Sprite sprite;
    vector<IntRect> frames;

    Animation() {}
    Animation(Texture& t, int x, int y, int w, int h, int count, float Speed) {
        Frame = 0;
        speed = Speed;

        for (int i = 0; i < count; i++)
            frames.push_back(IntRect(x + i * w, y, w, h));

        sprite.setTexture(t);
        sprite.setOrigin(w / 2, h / 2);
        sprite.setTextureRect(frames[0]);
    }

    void update() {
        Frame += speed;
        int n = frames.size();
        if (Frame >= n) Frame -= n;
        if (n > 0) sprite.setTextureRect(frames[int(Frame)]);
    }

    bool isEnd() {
        return Frame + speed >= frames.size();
    }
};

class Entity {
public:
    float x, y, dx, dy, R, angle;
    bool life;
    std::string name;
    Animation anim;

    Entity() {
        life = 1;
    }

    void settings(Animation& a, int X, int Y, float Angle = 0, int radius = 1) {
        anim = a;
        x = X;
        y = Y;
        angle = Angle;
        R = radius;
    }

    virtual void update() {};

    void draw(RenderWindow& app) {
        anim.sprite.setPosition(x, y);
        anim.sprite.setRotation(angle + 90);
        app.draw(anim.sprite);

        CircleShape circle(R);
        circle.setFillColor(Color(255, 0, 0, 170));
        circle.setPosition(x, y);
        circle.setOrigin(R, R);
        //app.draw(circle);
    }

    virtual ~Entity() {};
};


class Asteroids : public Entity {
public:
    Asteroids() {
        dx = rand() % 6 - 4;
        dy = rand() % 6 - 4;
        name = "Asteroids";
    }

    void update() {
        x += dx;
        y += dy;

        if (x > W) x = 0;  if (x < 0) x = W;
        if (y > H) y = 0;  if (y < 0) y = H;
    }
};


class bullet : public Entity {
public:
    bullet() {
        name = "bullet";
    }

    void  update() {
        dx = cos(angle * DEGTORAD) * 6;
        dy = sin(angle * DEGTORAD) * 6;
        // angle+=rand()%7-3;  /*try this*/
        x += dx;
        y += dy;
        if (x > W || x<0 || y>H || y < 0) life = 0;
    }
};


class player : public Entity {
public:
    bool thrust;

    player() {
        name = "player";
    }

    void update() {
        if (thrust) {
            dx += cos(angle * DEGTORAD) * 0.2;
            dy += sin(angle * DEGTORAD) * 0.2;
        }
        else {
            dx *= 0.99;
            dy *= 0.99;
        }

        int maxSpeed = 15;
        float speed = sqrt(dx * dx + dy * dy);
        if (speed > maxSpeed) {
            dx *= maxSpeed / speed;
            dy *= maxSpeed / speed;
        }

        x += dx;
        y += dy;

        if (x > W) x = 0; if (x < 0) x = W;
        if (y > H) y = 0; if (y < 0) y = H;
    }

};

class HealthItem : public Entity {
public:
    HealthItem() {
        name = "HealthItem";
    }

    void update() {
        x += dx;
        y += dy;

        if (x > W) x = 0; if (x < 0) x = W;
        if (y > H) y = 0; if (y < 0) y = H;
    }
};

class AmmoItem : public Entity {
public:
    AmmoItem() {
        name = "AmmoItem";
    }

    void update() {
        x += dx;
        y += dy;

        if (x > W) x = 0; if (x < 0) x = W;
        if (y > H) y = 0; if (y < 0) y = H;
    }
};

int highscore = 0;

void loadHighscore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highscore;
        file.close();
    }
}

void saveHighscore(int currentScore) {
    if (currentScore > highscore) {
        highscore = currentScore;
        std::ofstream file("highscore.txt");
        if (file.is_open()) {
            file << highscore;
            file.close();
        }
    }
}

bool isCollide(Entity* a, Entity* b) {
    return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->R + b->R) * (a->R + b->R);
}