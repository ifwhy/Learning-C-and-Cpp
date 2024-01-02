#include "game.hpp"

int main() {
    srand(time(0));

    sf::RenderWindow app(sf::VideoMode(W, H), "Konsep Pemrograman - Asteroids!");

    app.setFramerateLimit(60);

    sf::Image icon;
    icon.loadFromFile("images/icon.png");
    app.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Highscore di awal game
    loadHighscore();

    // Load Texture
    sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
    t1.loadFromFile("images/spaceship.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");
    t8.loadFromFile("images/backgroundAwal.png");
    t9.loadFromFile("images/gameover.png");
    t10.loadFromFile("images/health.png");
    t11.loadFromFile("images/ammo.png");

    t1.setSmooth(true);
    t2.setSmooth(true);
    t8.setSmooth(true);
    t9.setSmooth(true);
    t10.setSmooth(true);
    t11.setSmooth(true);

    // Membuat Sprites
    sf::Sprite background(t2);
    sf::Sprite backgroundMenu(t8);
    sf::Sprite backgroundGameOver(t9);

    // Load Animasi
    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
    Animation sHealthItem(t10, 0, 0, 32, 32, 1, 0.2);
    Animation sAmmoItem(t11, 0, 0, 32, 32, 1, 0.2);

    // Membuat daftar Entity 
    list<Entity*> entities;

    // Menginisiasi Asteroids
    for (int i = 0; i < 15; i++) {
        Asteroids* a = new Asteroids();
        a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);
        entities.push_back(a);
    }

    // Menginisiasi Player
    player* p = new player();
    p->settings(sPlayer, 200, 200, 0, 20);
    entities.push_back(p);

    // Load Musik dan Sound Efek
    // sf::Music music;
    // if (!music.openFromFile("music/music.ogg")) return -1;
    // music.setLoop(true);
    // music.setVolume(50);
    // music.play();

    // sf::SoundBuffer shootBuffer, explosionBuffer;

    // if (!shootBuffer.loadFromFile("music/efek_tembakan.wav")) return -1;
    // if (!explosionBuffer.loadFromFile("music/efek_ledakan.wav")) return -1;

    // sf::Sound shootSound(shootBuffer);
    // sf::Sound explosionSound(explosionBuffer);

    // Load Font dan Teks
    sf::Font font;
    font.loadFromFile("font/Font_Asteroid.ttf");
    sf::Text scoreText, lifeText, levelText, ammoText, highscoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 0);

    lifeText.setFont(font);
    lifeText.setCharacterSize(40);
    lifeText.setFillColor(sf::Color::White);
    lifeText.setPosition(10, 40);

    levelText.setFont(font);
    levelText.setCharacterSize(40);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 80);

    ammoText.setFont(font);
    ammoText.setCharacterSize(40);
    ammoText.setFillColor(sf::Color::White);
    ammoText.setPosition(10, 120);

    highscoreText.setFont(font);
    highscoreText.setCharacterSize(30);
    highscoreText.setFillColor(sf::Color::White);
    highscoreText.setPosition(900, 10);

    // Variabel Game
    int score = 0;
    int life = 5;
    int level = 1;
    int ammo = 100;
    const int MAX_AMMO = 200;

    bool gameOver = false;
    bool showMenu = true;

    // Menu Loop
    while (showMenu) {
        sf::Event event;
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                app.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Enter) {
                    showMenu = false;
                }
        }

        app.draw(backgroundMenu);
        app.display();
    }

    // Main Game Loop
    label:
    while (app.isOpen() && !showMenu) {
        sf::Event event;
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                app.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Space) {
                    if (ammo > 0) {
                        bullet* b = new bullet();
                        b->settings(sBullet, p->x, p->y, p->angle, 10);
                        entities.push_back(b);
                        ammo--;

                        // shootSound.play();
                    }
                }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p->angle += 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  p->angle -= 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p->thrust = true;
        else p->thrust = false;

        for (auto a : entities)
            for (auto b : entities) {
                if (a->name == "Asteroids" && b->name == "bullet")
                    if (isCollide(a, b)) {
                        a->life = false;
                        b->life = false;

                        score++;

                        if (score % 20 == 0) {
                            level++;
                            life++;
                        }

                        Entity* e = new Entity();
                        e->settings(sExplosion, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);

                        for (int i = 0; i < 2; i++) {
                            if (a->R == 15) continue;
                            Entity* e = new Asteroids();
                            e->settings(sRock_small, a->x, a->y, rand() % 360, 15);
                            entities.push_back(e);
                        }

                        // explosionSound.play();
                    }

                if (a->name == "player" && b->name == "Asteroids")
                    if (isCollide(a, b)) {
                        b->life = false;

                        life--;

                        Entity* e = new Entity();
                        e->settings(sExplosion_ship, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);

                        p->settings(sPlayer, W / 2, H / 2, 0, 20);
                        p->dx = 0; p->dy = 0;
                    }

                if (a->name == "HealthItem" && a->life)
                    if (isCollide(p, a)) {
                        a->life = false;
                        life++;
                    }

                if (a->name == "AmmoItem" && a->life)
                    if (isCollide(p, a)) {
                        a->life = false;
                        ammo += 50;
                        if (ammo > MAX_AMMO) ammo = MAX_AMMO;
                    }
            }

        scoreText.setString("Score : " + to_string(score));
        lifeText.setString("Life  : " + to_string(life));
        levelText.setString("Level : " + to_string(level));
        ammoText.setString("Ammo  : " + to_string(ammo));
        highscoreText.setString("Highscore: " + to_string(highscore));

        if (p->thrust)  p->anim = sPlayer_go;
        else   p->anim = sPlayer;

        for (auto e : entities)
            if (e->name == "explosion")
                if (e->anim.isEnd()) e->life = 0;

        if (rand() % (100 + rand() % 5) == 0) {
            Asteroids* a = new Asteroids();
            a->settings(sRock, 0, rand() % H, rand() % 360, 25);
            entities.push_back(a);
        }

        if (rand() % (1000 + rand() % 5) == 0) {
            HealthItem* h = new HealthItem();
            h->settings(sHealthItem, rand() % W, rand() % H, rand() % 360, 15);
            entities.push_back(h);
        }

        if (rand() % (500 + rand() % 5) == 0) {
            AmmoItem* ai = new AmmoItem();
            ai->settings(sAmmoItem, rand() % W, rand() % H, rand() % 360, 15);
            entities.push_back(ai);
        }

        for (auto i = entities.begin(); i != entities.end();) {
            Entity* e = *i;

            e->update();
            e->anim.update();

            if (e->life == false) { i = entities.erase(i); delete e; }
            else i++;

            app.draw(background);
            app.draw(levelText);
            app.draw(scoreText);
            app.draw(lifeText);
            app.draw(ammoText);
            app.draw(highscoreText);
        }

        for (auto i : entities) i->draw(app);

        if (life <= 0) {
            gameOver = true;
            // music.stop();
            app.draw(backgroundGameOver);
            scoreText.setCharacterSize(45);
            scoreText.setString(to_string(score));
            scoreText.setPosition(W / 2 + 60, H / 2 + 68);
            app.draw(scoreText);

            sf::Text gameOverHighscoreText;
            gameOverHighscoreText.setFont(font);
            gameOverHighscoreText.setCharacterSize(30);
            gameOverHighscoreText.setFillColor(sf::Color::White);
            gameOverHighscoreText.setPosition(W / 2 - 100, H / 2 + 120);
            gameOverHighscoreText.setString("Highscore: " + to_string(highscore));
            app.draw(gameOverHighscoreText);

            // Cek apakah score saat ini lebih besar dari highscore
            if (score >= highscore) {
                highscore = score;
                // Menyimpan highscore
                saveHighscore(highscore);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                score = 0;
                life = 5;  
                ammo = 100;  

                scoreText.setString("Score: " + to_string(score));
                scoreText.setPosition(10, 0);

                p->settings(sPlayer, W / 2, H / 2, 0, 20);
                entities.clear();
                entities.push_back(p);

                for (int i = 0; i < 15; i++) {
                    Asteroids* a = new Asteroids();
                    a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);
                    entities.push_back(a);
                }

                gameOver = false;
                showMenu = false;
                goto label;
                // music.play();
            }
        }
        app.display();
    }
    
    app.close();
    return 0;
}
