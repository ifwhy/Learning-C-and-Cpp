#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <utility>
#include <queue>
#include <limits>
#include "./Menu.hpp" 
using namespace std;

enum faculty {
    FATISDA,
    FP,
    FKIP,
    FK,
    FPsi,
    FMIPA,
    FT,
    FISIP,
    FEB,
    FIB,
    SV
};

faculty stringToFaculty(const string& str) {
    if (str == "FATISDA") return FATISDA;
    else if (str == "FP") return FP;
    else if (str == "FKIP") return FKIP;
    else if (str == "FK") return FK;
    else if (str == "FPsi") return FPsi;
    else if (str == "FMIPA") return FMIPA;
    else if (str == "FT") return FT;
    else if (str == "FISIP") return FISIP;
    else if (str == "FEB") return FEB;
    else if (str == "FIB") return FIB;
    else if (str == "SV") return SV;
    else return FATISDA;
}

string facultyToString(int f) {
    switch (f) {
        case FATISDA: return "FATISDA";
        case FP: return "FP";
        case FKIP: return "FKIP";
        case FK: return "FK";
        case FPsi: return "FPsi";
        case FMIPA: return "FMIPA";
        case FT: return "FT";
        case FISIP: return "FISIP";
        case FEB: return "FEB";
        case FIB: return "FIB";
        case SV: return "SV";
        default: return "FATISDA";
    }
}

class Edge {
    public:
        int u, v, weight;
        Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class Graph {
    private:
        int V; // Jumlah simpul (fakultas)
        vector<Edge> edges; // Vektor untuk menyimpan semua tepi graf

    public:
        Graph(int V) : V(V) {}

        // Menambahkan tepi ke graf
        void addEdge(int u, int v, int weight) {
            edges.push_back(Edge(u, v, weight));
        }

        // Fungsi bantuan untuk mencari subset dari sebuah elemen i (Path Compression)
        int find(vector<int>& parent, int i) {
            if (parent[i] == -1)
                return i;
            return find(parent, parent[i]);
        }

        // Fungsi gabung dua subset menjadi satu subset (Union by Rank)
        void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
            int xroot = find(parent, x);
            int yroot = find(parent, y);

            if (rank[xroot] < rank[yroot])
                parent[xroot] = yroot;
            else if (rank[xroot] > rank[yroot])
                parent[yroot] = xroot;
            else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
        }

        // Implementasi quicksort untuk sorting tepi berdasarkan bobotnya
        void quicksort(vector<Edge>& arr, int low, int high) {
            if (low < high) {
                // Partition index
                int pi = partition(arr, low, high);

                // Recursively sort elements before partition and after partition
                quicksort(arr, low, pi - 1);
                quicksort(arr, pi + 1, high);
            }
        }

        int partition(vector<Edge>& arr, int low, int high) {
            int pivot = arr[high].weight;
            int i = (low - 1); // Index of smaller element

            for (int j = low; j <= high - 1; j++) {
                // If current element is smaller than or equal to pivot
                if (arr[j].weight <= pivot) {
                    i++; // Increment index of smaller element
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            return (i + 1);
        }

        // Implementasi algoritma Kruskal untuk mencari MST
        vector<Edge> KruskalMST() {
            vector<Edge> result; // Akan menyimpan MST hasilnya
            int e = 0; // Indeks dari tepi yang akan ditambahkan ke MST hasilnya
            int i = 0; // Indeks dari tepi yang sedang dipertimbangkan

            // Urutkan semua tepi berdasarkan bobotnya dengan quicksort
            quicksort(edges, 0, edges.size() - 1);

            // Vektor untuk menyimpan subset
            vector<int> parent(V, -1);
            vector<int> rank(V, 0);

            // Ada V-1 tepi dalam MST
            while (e < V - 1 && i < edges.size()) {
                Edge next_edge = edges[i++];
                int x = find(parent, next_edge.u);
                int y = find(parent, next_edge.v);

                // Jika menyatukan kedua u dan v tidak akan membentuk siklus
                if (x != y) {
                    result.push_back(next_edge);
                    Union(parent, rank, x, y);
                    e++;
                }
            }

            return result;
        }

    private:
        void readData(){
            ifstream file("./DB/db-faculty.txt");
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string fakultas1, fakultas2, weightStr;
                getline(ss, fakultas1, ',');
                getline(ss, fakultas2, ',');
                getline(ss, weightStr, ',');

                this->addEdge(stringToFaculty(fakultas1), stringToFaculty(fakultas2), stoi(weightStr));
            }
        }

        // MEncetak Fakultas
        void printFaculty() {
            this->SetConsoleColor(BLUE, BLACK);
            cout << "1. FATISDA" << endl;
            cout << "2. FP" << endl;
            cout << "3. FKIP" << endl;
            cout << "4. FK" << endl;
            cout << "5. FPsi" << endl;
            cout << "6. FMIPA" << endl;
            cout << "7. FT" << endl;
            cout << "8. FISIP" << endl;
            cout << "9. FEB" << endl;
            cout << "10. FIB" << endl;
            cout << "11. SV" << endl;
            this->SetConsoleColor(WHITE, BLACK);
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

        // Implementasi algoritma Djikstra untuk mencari jalur terpendek dari simpul awal ke semua simpul lainnya
        vector<int> Dijkstra(int src) {
            // Inisialisasi vektor jarak dengan nilai tak terhingga (infinitas)
            vector<int> dist(V, numeric_limits<int>::max());

            // Priority queue untuk memilih simpul dengan jarak terpendek yang belum diproses
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            // Masukkan simpul awal ke dalam priority queue dan atur jaraknya menjadi 0
            pq.push(make_pair(0, src));
            dist[src] = 0;

            while (!pq.empty()) {
                // Ambil simpul dengan jarak terpendek yang belum diproses
                int u = pq.top().second;
                pq.pop();

                // Periksa semua tepi yang terhubung dari u
                for (const Edge& edge : edges) {
                    int v = (edge.u == u) ? edge.v : (edge.v == u) ? edge.u : -1;
                    if (v != -1) {
                        // Update jarak jika ditemukan jarak yang lebih pendek ke v melalui u
                        if (dist[v] > dist[u] + edge.weight) {
                            dist[v] = dist[u] + edge.weight;
                            pq.push(make_pair(dist[v], v));
                        }
                    }
                }
            }

            return dist;
        }

    public:
        // Metode untuk menampilkan jalur terpendek dari satu fakultas ke fakultas lainnya
        void printDjikstra() {
            system(CLEAR_CONSOLE);
            this->readData();
            int from;
            cout << "JARAK FAKULTAS TERDEKAT" << endl ;
            this->hiasan(49);
            this->printFaculty();
            this->hiasan(49);
            cout << "Masukkan Fakultas Asal : ";
            cin >> from;
            system(CLEAR_CONSOLE);

            cout << "Fakultas Asal : " << facultyToString(from - 1) << endl;
            vector<int> dist = this->Dijkstra(from - 1);

            this->SetConsoleColor(BLACK, WHITE);
            cout << "     ";
            cout << setw(3) << left << "No.";
            cout << setw(10) << left << "   Asal";
            cout << setw(10) << left << "   Tujuan";
            cout << setw(15) << left << "   Jarak (m)" << endl;
            this->SetConsoleColor(WHITE, BLACK);

            int nomorMhs = 1;
            this->SetConsoleColor(BLUE, BLACK);
            for(int i = 0; i < V; i++){
                if (i != from - 1) {
                    cout << "     ";
                    cout << setw(6) << left << nomorMhs;
                    cout << setw(10) << left << facultyToString(from - 1);
                    cout << setw(12) << left << facultyToString(i);
                    cout << setw(8) << left << dist[i] << endl;

                    nomorMhs++;
                }
            }
            this->hiasan(49);
            this->SetConsoleColor(WHITE, BLACK);
        }

        // Metode untuk menampilkan data graf
        // This method is for debugging purpose
        void printGraph() {
            this->readData();
            system(CLEAR_CONSOLE);
            cout << "GRAF SELURUH FAKULTAS" << endl;
            this->hiasan(49);
            cout << endl;
            this->SetConsoleColor(BLACK, WHITE);
            cout << "     ";
            cout << setw(3) << left << "No.";
            cout << setw(10) << left << "   Fakultas 1";
            cout << setw(10) << left << "   Fakultas 2";
            cout << setw(15) << left << "   Jarak (m)" << endl;
            this->SetConsoleColor(WHITE, BLACK);

            int nomorMhs = 1;
            this->SetConsoleColor(BLUE, BLACK);
            for (const Edge& edge : edges) {
                cout << "     ";
                cout << setw(8) << left << nomorMhs;
                cout << setw(12) << left << facultyToString(edge.u);
                cout << setw(14) << left << facultyToString(edge.v);
                cout << setw(10) << left << edge.weight << endl;

                nomorMhs++;
            }
            this->hiasan(49);
            this->SetConsoleColor(WHITE, BLACK);
        }

        // Menampilkan MST
        void printKruskalMST(){
            system(CLEAR_CONSOLE);
            this->readData();
            vector<Edge> result = this->KruskalMST();

            // Cetak tepi hasilnya
            cout << "KUNJUNGI SELURUH FAKULTAS " << endl;
            this->hiasan(49);
            this->SetConsoleColor(BLACK, WHITE);
            cout << "      ";
            cout << setw(3) << left << "No.";
            cout << setw(10) << left << "   Fakultas 1";
            cout << setw(10) << left << "   Fakultas 2";
            cout << setw(15) << left << "   Jarak (m)" << endl;
            this->SetConsoleColor(WHITE, BLACK);

            int nomorMhs = 1;
            this->SetConsoleColor(BLUE, BLACK);
            for (int i = 0; i < result.size(); i++){
                cout << "     ";
                cout << setw(8) << left << nomorMhs;
                cout << setw(12) << left << facultyToString(result[i].u);
                cout << setw(14) << left << facultyToString(result[i].v);
                cout << setw(10) << left << result[i].weight << endl;

                nomorMhs++;
            }
            this->SetConsoleColor(WHITE, BLACK);
            this->hiasan(49);
        }
};
