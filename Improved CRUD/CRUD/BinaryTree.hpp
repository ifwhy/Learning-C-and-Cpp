#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include <windows.h>
#include "./Menu.hpp"

using namespace std;

class BinaryTree {
    private:
        struct Mahasiswa {
            string nama;
            string nim;
            string prodi;
            string fakultas;
        } mhs;

        // Struktur Node untuk tree
        struct Node {
            Mahasiswa nodeMhs;
            Node* left;
            Node* right;

            // Constructor untuk Node
            Node(string nim, string nama, string prodi, string fakultas)
                : left(nullptr), right(nullptr) {
                this->nodeMhs.nim = nim;
                this->nodeMhs.nama = nama;
                this->nodeMhs.prodi = prodi;
                this->nodeMhs.fakultas = fakultas;
            }
        };

        Node* root;

        // Membuat node baru
        Node* create(string nim, string nama, string prodi, string fakultas) {
            return new Node(nim, nama, prodi, fakultas);
        }

        // Fungsi untuk menambahkan node ke dalam tree berdasarkan NIM
        Node* insertRecByNIM(Node* node, Node* newNode) {
            if (node == nullptr) {
                return newNode;
            }

            if (newNode->nodeMhs.nim < node->nodeMhs.nim) {
                node->left = insertRecByNIM(node->left, newNode);
            } else {
                node->right = insertRecByNIM(node->right, newNode);
            }

            return node;
        }

        // Fungsi untuk menambahkan node ke dalam tree berdasarkan Nama
        Node* insertRecByNama(Node* node, Node* newNode) {
            if (node == nullptr) {
                return newNode;
            }
            if (newNode->nodeMhs.nama < node->nodeMhs.nama) {
                node->left = insertRecByNama(node->left, newNode);
            } else {
                node->right = insertRecByNama(node->right, newNode);
            }
            return node;
        }

        // Mengecek apakah database kosong atau tidak
        bool isDBKosong(){
            // Membaca data dari database
            ifstream coba("./DB/db-mhs.txt");
            string trial1, trial;
            while(getline(coba, trial1)){
                trial += trial1;
            };
            coba.close();

            return (trial.length() == 0) ? true : false;
        }

        // Fungsi rekursif untuk menampilkan tree secara inorder
        void inOrderTraversal(Node* node) {
            if (node == nullptr) {
                return;
            }

            inOrderTraversal(node->left);
            cout << "Nama       : " << node->nodeMhs.nama << endl; 
            cout << "NIM        : " << node->nodeMhs.nim << endl;
            cout << "Prodi      : " << node->nodeMhs.prodi << endl;
            cout << "Fakultas   : " << node->nodeMhs.fakultas << endl << endl;;
            inOrderTraversal(node->right);
        }

        // BST berdasarkan NIM
        Node* searchRecByNIM(Node* node, const string& nim) {
            if (node == nullptr || node->nodeMhs.nim == nim) {
                return node;
            }
            if (nim < node->nodeMhs.nim) {
                return this->searchRecByNIM(node->left, nim);
            } else {
                return this->searchRecByNIM(node->right, nim);
            }
        }

        // BST berdasarkan Nama
        Node* searchRecByNama(Node* node, const string& nama) {
            if (node == nullptr || node->nodeMhs.nama == nama) {
                return node;
            }
            if (nama < node->nodeMhs.nama) {
                return searchRecByNama(node->left, nama);
            } else {
                return searchRecByNama(node->right, nama);
            }
        }

        // Mengganti warna console
        void SetConsoleColor(ConsoleColor text, ConsoleColor background) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, (background << 4) | text);
        }

        // Hiasan ____
        void hiasan(int n){
            for(int i = 0; i < n; i++){
                    cout << "_";
                }
            cout << endl;
        }

    public:
        BinaryTree() : root(nullptr) {}

        // Membaca data dari database dan memasukkannya ke dalam tree
        void readData() {
            if(!this->isDBKosong()){
                ifstream file("./DB/db-mhs.txt");
                string line;
                while (getline(file, line)) {
                    stringstream ss(line);
                    string nim, nama, prodi, fakultas;
                    getline(ss, nim, ',');
                    getline(ss, nama, ',');
                    getline(ss, prodi, ',');
                    getline(ss, fakultas, ',');

                    // Membuat node baru dengan data yang dibaca
                    Node* newNode = this->create(nim, nama, prodi, fakultas);

                    // Menambahkan node ke dalam tree
                    root = this->insertRecByNIM(root, newNode);
                }
            }
        }

        // Menampilkan semua data mahasiswa (Only for debugging purpose)
        void displayAll() {
            this->readData();
            this->inOrderTraversal(root);
        }

        void showSearchByNim(string &nim) {
            this->readData();
            Node* result = this->searchRecByNIM(root, nim);
            if (result != nullptr) {
                cout << "Mahasiswa ditemukan!\n";

                cout << "Data Mahasiswa : " << endl;
                this->hiasan(90);
                this->SetConsoleColor(BLACK, WHITE);
                cout << setw(30) << left << "            Nama";
                cout << setw(15) << left << "     NIM";
                cout << setw(25) << left << "   Program Studi";
                cout << setw(20) << left << "   Fakultas" << endl;
                this->SetConsoleColor(WHITE, BLACK);

                this->SetConsoleColor(BLUE, BLACK);
                cout << "   ";
                cout << setw(30) << left << result->nodeMhs.nama;
                cout << setw(15) << left << result->nodeMhs.nim;
                cout << setw(25) << left << result->nodeMhs.prodi;
                cout << setw(20) << left << result->nodeMhs.fakultas << endl;
                this->SetConsoleColor(WHITE, BLACK);
            } else {
                this->SetConsoleColor(RED, BLACK);
                cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
                this->SetConsoleColor(WHITE, BLACK);
            }
        }

        void showSearchByNama(string &nama) {
            this->readData();
            Node* result = this->searchRecByNama(root, nama);
            if (result != nullptr) {
                cout << "Mahasiswa ditemukan!\n";

                cout << "Data Mahasiswa : " << endl;
                this->hiasan(90);
                this->SetConsoleColor(BLACK, WHITE);
                cout << setw(30) << left << "            Nama";
                cout << setw(15) << left << "     NIM";
                cout << setw(25) << left << "   Program Studi";
                cout << setw(20) << left << "   Fakultas" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                
                this->SetConsoleColor(BLUE, BLACK);
                cout << "   ";
                cout << setw(30) << left << result->nodeMhs.nama;
                cout << setw(15) << left << result->nodeMhs.nim;
                cout << setw(25) << left << result->nodeMhs.prodi;
                cout << setw(20) << left << result->nodeMhs.fakultas << endl;
                this->SetConsoleColor(WHITE, BLACK);
            } else {
                this->SetConsoleColor(RED, BLACK);
                cout << "Mahasiswa dengan nama " << nama << " tidak ditemukan.\n";
                this->SetConsoleColor(WHITE, BLACK);
            }
        }
};