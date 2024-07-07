#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

// Preprosesor untuk keperluan membersihkan console agar menyesuaikan ke OS
#if defined(__WIN32)
    #define CLEAR_CONSOLE "cls"
#elif defined(__linux__)
    #define CLEAR_CONSOLE "clear"
#elif defined(__APPLE__)
    #define CLEAR_CONSOLE "clear"
#endif

// Konstanta warna
enum ConsoleColor {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    WHITE,
};

// Enum untuk mempermudah pengondisian menu utama
enum mainMenu {
    CREATE_DATA = 1, 
    READ_DATA, 
    UPDATE_DATA,
    DELETE_DATA, 
    SEARCH_DATA,
    VISIT_FACULTY,
    EXIT
};

class Menu {
    private:
        int pilihan; // pilihan menu dari user
        bool isRepeat = true;
        char back;

        // Menampilkan menu
        void printMenu(){
            cout << "______________________________________________" << endl;
            this->SetConsoleColor(BLUE, BLACK);
            cout << "    PROGRAM MANAJEMEN DATA KAMPUS UNS" << endl;
            cout << "       Created By : Ivan Wahyu Nugroho" << endl;
            this->SetConsoleColor(WHITE, BLACK);
            cout << "______________________________________________" << endl;
            cout << "Menu Utama : " << endl;
            cout << "1. Menambahkan Data Mahasiswa" << endl;
            cout << "2. Menampilkan Data Mahasiswa" << endl;
            cout << "3. Memperbarui Data Mahasiswa" << endl;
            cout << "4. Menghapus Data Mahasiswa" << endl;
            cout << "5. Mencari Data Mahasiswa" << endl;
            cout << "6. Kunjungan Fakultas" << endl;
            cout << "7. Keluar" << endl;
            cout << "______________________________________________" << endl;
            cout << "Masukkan Pilihan Anda : ";
        }

        // Setter untuk pilihan
        void setPilihan(int pilihan){
            this->pilihan = pilihan;
        }

    public:
        // Getter untuk pilihan
        int getPilihan(){
            return this->pilihan;
        }

        // Getter untuk attribut isRepeat
        bool getIsLoop(){
            return this->isRepeat;
        }

        // Setter untuk attribut isRepeat
        void setIsLoop(bool newIsLoop){
            this->isRepeat = newIsLoop;
        }

        // Menampilkan menu
        void showMenu(){
            this->printMenu();
            cin >> pilihan;
            this->setPilihan(pilihan);
        }

        // Memberikan footer pada akhiran program
        void showThanks(){
            system(CLEAR_CONSOLE);
            cout << "______________________________________________" << endl;
            this->SetConsoleColor(BLUE, BLACK);
            cout << " TERIMA KASIH TELAH  MENGGUNAKAN PROGRAM KAMI" << endl;
            this->SetConsoleColor(WHITE, BLACK);
            cout << "______________________________________________" << endl << endl;
        }

        // Memberikan pilihan ke user untuk kembali ke menu atau keluar
        void backTo(){
            cout << "Kembali ke Menu? (y/n) : ";
            cin >> back;

            // Memberikan pengembalian ke menu atau tidak
            (back == 'y' || back == 'Y') ? this->setIsLoop(true) : this->setIsLoop(false);

            // Jika kembali ke menu, maka console akan dibersihkan
            (this->getIsLoop()) ? system(CLEAR_CONSOLE) : system(""); 
        }

        // Mengganti warna console
        void SetConsoleColor(ConsoleColor text, ConsoleColor background) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, (background << 4) | text);
        }
        
        // Menghandle pilihan yang tidak dikenali
        void showWrongChoice(){
            system(CLEAR_CONSOLE);
            this->SetConsoleColor(RED, BLACK);
			cout << "             Masukan Anda Salah!" << endl;
			cout << "      Program Diakhiri dalam 3 Detik";
            for(int i = 1; i <= 3; i++){
                Sleep(1200);
                cout << "...";
            }
            Sleep(300);
            cout << endl;
            this->SetConsoleColor(WHITE, BLACK);
        }

    protected:
        // Hiasan ____
        void hiasan(int n){
            for(int i = 0; i < n; i++){
                    cout << "_";
                }
            cout << endl;
        }
};
