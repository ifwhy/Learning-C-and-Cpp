#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<array>
#include<map>
#include<vector>
#include<list>
#include "Menu.hpp"
using namespace std;

class CRUD : Menu {
    private:
        // Struct untuk menyimpan data sementara
        struct Mahasiswa {
            string nama;
            string nim;
            string prodi;
            string fakultas;
        } mhs;

        // Tree
        struct Node {
            Mahasiswa nodeMhs;
            vector<Node*> children;

            // Constructor untuk Node 
            Node(string nim, string nama, string prodi, string fakultas){
                this->nodeMhs.nim = nim;
                this->nodeMhs.nama = nama;
                this->nodeMhs.prodi = prodi;
                this->nodeMhs.fakultas =fakultas;
            }
        };

        // Berbagai container untuk menampung data mahasiswa
        map<string, Mahasiswa> mahasiswa;
        set<string> nimMhs;
        queue<Mahasiswa> students;
        queue<Mahasiswa> queMhs;
        queue<Mahasiswa> dataMhs;
        vector<Mahasiswa> student;
        vector<Mahasiswa> listMhs;
        stack<Mahasiswa> dataMahasiswa;
        array<Mahasiswa, 1> arrMhs;
        Node* treeMhs;

    private:
        // Getter untuk mendapatkan jumlah mahasiswa
        int getMhs(){
            return this->students.size();
        }

        // Getter untuk mendapatkan nim mahasiswa
        set<string> getNim(){
            ifstream file("./DB/db.txt");
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string nim, nama, prodi, fakultas, angkatan;
                getline(ss, nim, ',');
                getline(ss, nama, ',');
                getline(ss, prodi, ',');
                getline(ss, fakultas, ',');
                getline(ss, angkatan, ',');
                
                this->nimMhs.insert(nim);
            }
            return this->nimMhs;
        }

        // Fungsi untuk memvalidasi NIM
        bool isNIMValid(Mahasiswa mhs){
            bool validasi = false;
            // Panjang NIM harus 8 dan karakter pertama harus kapital
            if(mhs.nim.length() == 8 && isupper(mhs.nim[0])){
                validasi = true;
            } 

            // 7 Karakter berikutnya harus angka
            for(int i = 1; i < mhs.nim.length(); i++){
                if(!isdigit(mhs.nim[i])){
                    validasi = false;
                    break;    
                }
            }

            return !validasi;
        }

        // Mengecek apakah database kosong atau tidak
        bool isDBKosong(){
            // Membaca data dari database
            ifstream coba("./DB/db.txt");
            string trial1, trial;
            while(getline(coba, trial1)){
                trial += trial1;
            };
            coba.close();

            return (trial.length() == 0) ? true : false;
        }

        // Membuat node baru
        Node* create(string nim, string nama, string prodi, string fakultas){
            Node node(nim, nama, prodi, fakultas);
            return new Node(node);
        }

        // Membaca preOrder (Hanya untuk keperluan debugging)
        void preOrder(Node* data){
            if(data == nullptr){
                return;
            }

            cout << data->nodeMhs.nama << " " << data->nodeMhs.nim << " " << data->nodeMhs.prodi << " " << data->nodeMhs.fakultas << endl;
            for(Node* child : data->children){
                preOrder(child);
            }
        }

    public:
// =================== Menambahkan Data Mahasiswa =================== //
        void addDataMhs(){
            system(CLEAR_CONSOLE);
            cout << "______________________________________________" << endl;
            cout << "        MENAMBAHKAN DATA MAHASISWA" << endl;
            cout << "______________________________________________" << endl;

            // Mengambil data mahasiswa dari user
            cout << "Masukkan Data Mahasiswa" << endl;
            cout << "Nama             : ";
            cin.ignore();
            getline(cin, this->mhs.nama);
            cout << "NIM              : ";
            cin >> this->mhs.nim;
            cout << "Program Studi    : ";
            cin.ignore();
            getline(cin, this->mhs.prodi);
            cout << "Fakultas         : ";
            getline(cin, this->mhs.fakultas);
            
            // Assignment ke set
            this->getNim();

            // Pengondisian jika NIM tidak valid
            if(this->isNIMValid(this->mhs)){
                cout << "______________________________________________" << endl;
                this->SetConsoleColor(RED, BLACK);
                cout << "Format NIM salah!" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                cout << "______________________________________________" << endl;

            // Pengondisian jika NIM terjadi duplikasi
            } else if(this->nimMhs.count(this->mhs.nim)){
                cout << "___________________________________________________" << endl;
                this->SetConsoleColor(RED, BLACK);
                cout << "Mahasiswa dengan NIM " << this->mhs.nim << " sudah ada di database" << endl;
                cout << "\tNIM Tidak Diberbolehkan Terduplikasi" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                cout << "___________________________________________________" << endl;
            
            // Pengondisian jika data akan diinputkan ke db
            } else {
                // Assignment ke map
                mahasiswa[this->mhs.nim] = mhs;

                // Menulis data ke database
                string data = mahasiswa[this->mhs.nim].nim + "," + mahasiswa[this->mhs.nim].nama + "," + mahasiswa[this->mhs.nim].prodi + "," + mahasiswa[this->mhs.nim].fakultas;

                ofstream file("./DB/db.txt", ios::app);
                file << data << endl;
                file.close();

                // Menampilkan Data Mahasiswa yang baru diinput
                cout << "______________________________________________" << endl;
                cout << endl << "Data Mahasiswa : " << endl;
                this->hiasan(90);
                this->SetConsoleColor(BLACK, WHITE);
                cout << setw(30) << left << "            Nama";
                cout << setw(15) << left << "     NIM";
                cout << setw(25) << left << "   Program Studi";
                cout << setw(20) << left << "   Fakultas" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                for(auto const& student : mahasiswa){
                    cout << "   ";
                    cout << setw(30) << left << this->mhs.nama;
                    cout << setw(15) << left << this->mhs.nim;
                    cout << setw(25) << left << this->mhs.prodi;
                    cout << setw(20) << left << this->mhs.fakultas << endl;
                    break;
                    mahasiswa.erase(student.first);
                }
                this->hiasan(90);
                this->SetConsoleColor(GREEN, BLACK);
                cout << "Status : Data Mahasiswa Di Atas Berhasil Ditambahkan" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                cout << endl;
            }
        }

// =================== Menampilkan Data Mahasiswa =================== //
        void showDataMhs(){
            cout << "______________________________________________" << endl;
            cout << "               DATA MAHASISWA" << endl;
            cout << "______________________________________________" << endl;

            // Database akan dibaca jika tidak kosong
            if(!this->isDBKosong()){
                
                for(int i = 1; i < this->students.size(); i++){
                    this->students.pop();
                }

                ifstream file("./DB/db.txt");
                string line;
                while (getline(file, line)) {
                    stringstream ss(line);
                    string nim, nama, prodi, fakultas, angkatan;
                    getline(ss, nim, ',');
                    getline(ss, nama, ',');
                    getline(ss, prodi, ',');
                    getline(ss, fakultas, ',');
                    getline(ss, angkatan, ',');
                    
                    // Assignment ke struct Mahasiswa (mhs)
                    this->mhs.nama = nama;
                    this->mhs.nim = nim;
                    this->mhs.prodi = prodi;
                    this->mhs.fakultas = fakultas;

                    // Assignment ke map
                    this->students.push(this->mhs);
                }

                // Displaying
                int nomorMhs = 1;
                cout << "Banyak Mahasiswa : " << this->getMhs() << endl;
                this->hiasan(95);
                this->SetConsoleColor(BLACK, WHITE);
                cout << "     ";
                cout << setw(3) << left << "No.";
                cout << setw(30) << left << "            Nama";
                cout << setw(15) << left << "     NIM";
                cout << setw(25) << left << "   Program Studi";
                cout << setw(17) << left << "   Fakultas" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                // this->hiasan(95);
                
                this->SetConsoleColor(BLUE, BLACK);
                while(!this->students.empty()){
                    cout << "      ";
                    cout << nomorMhs << ".   ";
                    cout << setw(30) << left << this->students.front().nama;
                    cout << setw(15) << left << this->students.front().nim;
                    cout << setw(25) << left << this->students.front().prodi;
                    cout << setw(20) << left << this->students.front().fakultas << endl;
                    nomorMhs++;
                    this->students.pop();
                }

                this->SetConsoleColor(WHITE, BLACK);
                this->hiasan(95);
                cout << endl;

                // Menutup file database
                file.close();

            } else {
                this->SetConsoleColor(RED, BLACK);
                cout << "Database Masih Kosong!" << endl;
                cout << "Tambahkan Data Terlebih Dahulu" << endl;
                this->SetConsoleColor(WHITE, BLACK);
            }
        }

// =================== Menghapus Data Mahasiswa =================== //
        void deleteDataMhs(){
            if(this->isDBKosong()){
                this->SetConsoleColor(RED, BLACK);
                cout << "Database Masih Kosong!" << endl; 
                cout << "Tambahkan Data Terlebih Dahulu" << endl; 
                this->SetConsoleColor(WHITE, BLACK);
            }

            system(CLEAR_CONSOLE);
            cout << "______________________________________________" << endl;
            cout << "           MENGHAPUS DATA MAHASISWA" << endl;

            int deleteNum;
            this->showDataMhs();
            cout << "Nomor mahasiswa yang akan dihapus : ";
            cin >> deleteNum;

            // Membaca Data dari Database
            ifstream file("./DB/db.txt");
            string line;

            int repeat = 1;
            while (getline(file, line)) {
                stringstream ss(line);
                string nim, nama, prodi, fakultas, angkatan;
                getline(ss, nim, ',');
                getline(ss, nama, ',');
                getline(ss, prodi, ',');
                getline(ss, fakultas, ',');
                getline(ss, angkatan, ',');
                
                // Assignment ke struct Mahasiswa (mhs)
                this->mhs.nama = nama;
                this->mhs.nim = nim;
                this->mhs.prodi = prodi;
                this->mhs.fakultas = fakultas;

                // Assignment ke map atau list
                (repeat == deleteNum) ? this->student.push_back(this->mhs) : this->dataMhs.push(this->mhs);
                repeat++;
            }

            if(deleteNum <= repeat - 1){
                // Menampilkan Data Mahasiswa yang Akan Dihapus
                cout << endl << "Data Mahasiswa yang Akan Dihapus" << endl;
                this->hiasan(95);
                this->SetConsoleColor(BLACK, WHITE);
                cout << setw(30) << left << "            Nama";
                cout << setw(15) << left << "      NIM";
                cout << setw(25) << left << "    Program Studi";
                cout << setw(25) << left << "    Fakultas" << endl;
                this->SetConsoleColor(WHITE, BLACK);

                cout << "    ";
                cout << setw(30) << left << this->student[0].nama;
                cout << setw(15) << left << this->student[0].nim;
                cout << setw(25) << left << this->student[0].prodi;
                cout << setw(20) << left << this->student[0].fakultas << endl;
                this->student.erase(this->student.begin() + 1); // Menghapus list
                this->hiasan(95);
                
                // Memberikan konfirmasi menghapus data mahasiswa
                char confirm;
                this->SetConsoleColor(YELLOW, BLACK);
                cout << "Apakah Anda yakin menghapus data ini? (y/n) : ";
                cin >> confirm;
                this->SetConsoleColor(WHITE, BLACK);

                if(confirm == 'y' || confirm == 'Y'){
                    // Menghapus NIM mahasiswa yg dihapus dari set
                    this->nimMhs.erase(this->student[0].nim);

                    // Menulis ke database
                    ofstream file("./DB/db.txt", ios::trunc);
                    int nomorMhs = 1;
                    string data;
                    while(!this->dataMhs.empty()){
                        data += this->dataMhs.front().nim + "," + this->dataMhs.front().nama + "," + this->dataMhs.front().prodi + "," + this->dataMhs.front().fakultas + "\n";
                        this->dataMhs.pop();
                    }
                    
                    file << data;
                    this->SetConsoleColor(GREEN, BLACK);
                    cout << "Data Mahasiswa Tersebut Berhasil Dihapus" << endl;
                    this->SetConsoleColor(WHITE, BLACK);
                    this->hiasan(95);
                } else {
                    cout << "Data Mahasiswa Tersebut Tidak Dihapus" << endl;
                    this->hiasan(95);
                }
            } else {
                // Hapus queue yang dibaca sebelumnya
                for(int i = 1; i <= this->dataMhs.size(); i++){
                    this->dataMhs.pop();
                }

                // Memberikan Notice salah
                this->hiasan(95);
                this->SetConsoleColor(RED, BLACK);
                cout << "Masukan Anda Salah!" << endl;
                cout << "Data Mahasiswa Tidak Ada" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                this->hiasan(95);
            }
        }

// =================== Memperbarui Data Mahasiswa =================== //
        void updateDataMhs(){
            if(this->isDBKosong()){
                this->SetConsoleColor(RED, BLACK);
                cout << "Database Masih Kosong!" << endl;
                cout << "Tambahkan Data Terlebih Dahulu" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                this->hiasan(95);
                return;
            }

            system(CLEAR_CONSOLE);
            cout << "______________________________________________" << endl;
            cout << "         MEMPERBARUI DATA MAHASISWA" << endl;
            
            int updateNum;
            this->showDataMhs();
            ifstream bacaDB("./DB/db.txt");
            string baris;
            while (getline(bacaDB, baris)) {
                stringstream ss(baris);
                string nim, nama, prodi, fakultas, angkatan;
                getline(ss, nim, ',');
                getline(ss, nama, ',');
                getline(ss, prodi, ',');
                getline(ss, fakultas, ',');
                getline(ss, angkatan, ',');
                
                // Assignment ke struct Mahasiswa (mhs)
                this->mhs.nama = nama;
                this->mhs.nim = nim;
                this->mhs.prodi = prodi;
                this->mhs.fakultas = fakultas;

                // Assignment ke map
                this->queMhs.push(this->mhs);
            }
            this->SetConsoleColor(YELLOW, BLACK);
            cout << "Nomor mahasiswa yang akan diperbarui : ";
            cin >> updateNum;
            this->SetConsoleColor(WHITE, BLACK);

            // Membersihkan console
            system(CLEAR_CONSOLE);

            // Membaca Data dari Database
            ifstream file("./DB/db.txt");
            string line;

            // Menghapus set
            this->nimMhs.clear();

            // Membaca data dari database
            int repeat = 1;
            this->treeMhs = this->create("X0023000", "Dummy", "Dummy", "Dummy");
            while (getline(file, line)) {
                stringstream ss(line);
                string nim, nama, prodi, fakultas, angkatan;
                getline(ss, nim, ',');
                getline(ss, nama, ',');
                getline(ss, prodi, ',');
                getline(ss, fakultas, ',');
                getline(ss, angkatan, ',');

                // Menambahkan NIM ke set
                this->nimMhs.insert(nim);
                
                // Assignment ke struct Mahasiswa (mhs)
                this->mhs.nama = nama;
                this->mhs.nim = nim;
                this->mhs.prodi = prodi;
                this->mhs.fakultas = fakultas;

                // Assignment ke tree atau stack
                (repeat == updateNum) ? this->treeMhs->children.push_back(this->create(nim, nama, prodi, fakultas)) : this->dataMhs.push(this->mhs);
                repeat++;
            }
            
            if(updateNum <= repeat - 1){
                // Menampilkan Data Mahasiswa yang Akan Diperbarui
                cout << endl << "Data Mahasiswa yang Akan Diperbarui" << endl;
                this->hiasan(95);
                this->SetConsoleColor(BLACK, WHITE);
                cout << setw(30) << left << "            Nama";
                cout << setw(15) << left << "      NIM";
                cout << setw(30) << left << "    Program Studi";
                cout << setw(20) << left << "    Fakultas" << endl;
                this->SetConsoleColor(WHITE, BLACK);

                cout << "    ";
                cout << setw(30) << left << this->treeMhs->children[0]->nodeMhs.nama;
                cout << setw(15) << left << this->treeMhs->children[0]->nodeMhs.nim;
                cout << setw(30) << left << this->treeMhs->children[0]->nodeMhs.prodi;
                cout << setw(20) << left << this->treeMhs->children[0]->nodeMhs.fakultas << endl;
                this->hiasan(95);
                
                // Memberikan konfirmasi memperbarui data mahasiswa
                char confirm;
                this->SetConsoleColor(YELLOW, BLACK);
                cout << "Apakah Anda yakin memperbarui data ini? (y/n) : ";
                cin >> confirm;
                this->SetConsoleColor(WHITE, BLACK);

                if(confirm == 'y' || confirm == 'Y'){
                    cout << endl << "Masukkan Data Mahasiswa Terbaru" << endl;
                    cout << "Nama             : ";
                    cin.ignore();
                    getline(cin, this->mhs.nama);
                    cout << "NIM              : ";
                    cin >> this->mhs.nim;
                    cout << "Program Studi    : ";
                    cin.ignore();
                    getline(cin, this->mhs.prodi);
                    cout << "Fakultas         : ";
                    getline(cin, this->mhs.fakultas);

                    // Assignment ke tree
                    this->treeMhs->children.push_back(this->create(this->mhs.nim, this->mhs.nama, this->mhs.prodi, this->mhs.fakultas));

                    // Membersihkan console
                    system(CLEAR_CONSOLE);
                    
                    // Assignment ke set untuk validasi duplikasi NIM
                    this->getNim();

                    // Hapus NIM mahasiswa yang akan diupdate dari set
                    this->nimMhs.erase(this->treeMhs->children[0]->nodeMhs.nim);

                    // Validasi untuk NIM
                    if(this->isNIMValid(this->mhs)) {
                        this->hiasan(95);
                        this->SetConsoleColor(RED, BLACK);
                        cout << "Format NIM Tidak Valid!" << endl;
                        this->SetConsoleColor(WHITE, BLACK);
                        this->hiasan(95);

                    // Validasi untuk NIM jika terjadi duplikasi
                    } else if(this->nimMhs.count(this->mhs.nim)){
                        cout << "___________________________________________________" << endl;
                        this->SetConsoleColor(RED, BLACK);
                        cout << "Mahasiswa dengan NIM " << this->mhs.nim << " sudah ada di database" << endl;
                        cout << "\tNIM Tidak Diberbolehkan Terduplikasi" << endl;
                        this->SetConsoleColor(WHITE, BLACK);
                        cout << "___________________________________________________" << endl;
                    
                    // Pengondisian jika data akan diinputkan ke db
                    } else {
                        // Menampilkan Data Mahasiswa yang Akan Diperbarui
                        cout << endl << "Data Mahasiswa Sebelum Diperbarui" << endl;
                        this->hiasan(95);
                        this->SetConsoleColor(BLACK, WHITE);
                        cout << setw(30) << left << "            Nama";
                        cout << setw(15) << left << "      NIM";
                        cout << setw(30) << left << "    Program Studi";
                        cout << setw(20) << left << "    Fakultas" << endl;
                        this->SetConsoleColor(WHITE, BLACK);

                        cout << "    ";
                        cout << setw(30) << left << this->treeMhs->children[0]->nodeMhs.nama;
                        cout << setw(15) << left << this->treeMhs->children[0]->nodeMhs.nim;
                        cout << setw(30) << left << this->treeMhs->children[0]->nodeMhs.prodi;
                        cout << setw(20) << left << this->treeMhs->children[0]->nodeMhs.fakultas << endl;

                        // Menampilkan Data Mahasiswa Terbaru
                        cout << endl << "Data Mahasiswa Setelah Diperbarui" << endl;
                        this->hiasan(95);
                        this->SetConsoleColor(BLACK, WHITE);
                        cout << setw(30) << left << "            Nama";
                        cout << setw(15) << left << "      NIM";
                        cout << setw(30) << left << "    Program Studi";
                        cout << setw(20) << left << "    Fakultas" << endl;
                        this->SetConsoleColor(WHITE, BLACK);

                        cout << "    ";
                        cout << setw(30) << left << this->treeMhs->children[1]->nodeMhs.nama;
                        cout << setw(15) << left << this->treeMhs->children[1]->nodeMhs.nim;
                        cout << setw(30) << left << this->treeMhs->children[1]->nodeMhs.prodi;
                        cout << setw(20) << left << this->treeMhs->children[1]->nodeMhs.fakultas << endl;
                        this->hiasan(95);

                        // Menulis data ke database
                        int posisi = 1;
                        while(posisi <= this->queMhs.size()){
                            if(posisi == updateNum){
                                mhs.nim = this->treeMhs->children[1]->nodeMhs.nim;
                                mhs.nama = this->treeMhs->children[1]->nodeMhs.nama;
                                mhs.prodi = this->treeMhs->children[1]->nodeMhs.prodi;
                                mhs.fakultas = this->treeMhs->children[1]->nodeMhs.fakultas;

                                listMhs.push_back(mhs);
                                delete this->treeMhs;
                            } else {
                                mhs.nim = this->dataMhs.front().nim;
                                mhs.nama = this->dataMhs.front().nama;
                                mhs.prodi = this->dataMhs.front().prodi;
                                mhs.fakultas = this->dataMhs.front().fakultas;
                                listMhs.push_back(mhs);
                                this->dataMhs.pop();
                            }
                            posisi++;
                        }

                        // Delete QueMHS
                        while(!this->queMhs.empty()){
                            this->queMhs.pop();
                        }

                        ofstream file("./DB/db.txt", ios::out);
                        string data = "";
                        for(int i = 0; i < listMhs.size(); i++){
                            data += listMhs[i].nim + "," + listMhs[i].nama + "," + listMhs[i].prodi + "," + listMhs[i].fakultas + "\n";  
                        }
                        file << data;
                        file.close();

                        // Delete ListMhs
                        this->listMhs.clear();

                        this->SetConsoleColor(GREEN, BLACK);
                        cout << "Data Mahasiswa Berhasil Diperbarui" << endl;
                        this->SetConsoleColor(WHITE, BLACK);
                        this->hiasan(95);

                    } 

                } else {
                    cout << "Data Mahasiswa Tersebut Tidak Diperbarui" << endl;
                    this->hiasan(95);
                }
            } else {
                // Hapus queue yang dibaca sebelumnya
                for(int i = 1; i <= this->dataMhs.size(); i++){
                    this->dataMhs.pop();
                }

                // Memberikan Notice salah
                this->hiasan(95);
                this->SetConsoleColor(RED, BLACK);
                cout << "Masukan Anda Salah!" << endl;
                cout << "Data Mahasiswa Tidak Ada" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                this->hiasan(95);
            }

        }

// =================== Mengubah Urutan Data Mahasiswa =================== //
        void changeOrderData(){
            system(CLEAR_CONSOLE);
            cout << "______________________________________________" << endl;
            cout << "       MENGUBAH URUTAN DATA MAHASISWA" << endl;
            cout << "______________________________________________" << endl;

            if(this->isDBKosong()){
                this->SetConsoleColor(RED, BLACK);
                cout << "Database Masih Kosong!" << endl;
                cout << "Tambahkan Data Terlebih Dahulu" << endl;
                this->SetConsoleColor(WHITE, BLACK);
                return;

            }
        }
};