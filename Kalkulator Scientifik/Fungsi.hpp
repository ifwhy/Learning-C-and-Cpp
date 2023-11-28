#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Daftar Konstanta
#define PI 3.1415926 // Konstanta pi
#define E 2.71828182845 // Bilangan Euler
const double logE = 0.434294; // Konstanta log(e)


// Deklarasi variabel global
int pilihUtama, pilihKedua, pilihKetiga; // variabel pilihan atau ulang
bool ulang = false;
bool* ulangPtr = &ulang;
double sum = 0;
char operasiMatdas[][100] = {"1. Perkalian", "2. Pembagian", "3. Penjumlahan", "4. Pengurangan", "5. Akar Kuadrat", "6. Akar Pangkat Tiga", "7. e^x", "8. Eksponensial", "9. Faktorial", "10. Permutasi", "11. Kombinasi"};
char trigon[][100] = {"1. sin()", "2. cos()", "3. tan()", "4. csc()", "5. sec()", "6. cot()", "7. asin()", "8. acos()", "9. atan()"};
char statistik[][100] = {"1. Rata-Rata", "2. Median", "3. Modus", "4. Standar Deviasi Populasi dan Variansinya", "5. Standar Deviasi Sampel dan Variansinya", "6. Desil", "7. Persentil", "8. Simpangan Rata-Rata", "9. Data Min, Max, dan Range", "10. Regresi dan Korelasi"};

// Semua fungsi

// Fungsi untuk tanya user apakah perlu menghitung lagi atau tidak
void tanyaUser(){
    char* tanya = (char *)malloc(sizeof(char));
    if (tanya == NULL){
        printf("Gagal mengalokasikan memori\n"); 
        exit(1);
    }

    printf("\n_____________________________________________________\n");
    printf("    Apakah Anda perlu menghitung lagi? (y/n) : ");
    scanf("%s", tanya);

    if(*tanya == 'y'){
        *ulangPtr = true; 
    } else if (*tanya == 'n'){
        *ulangPtr = false;
    } else {
        printf("\t\tMasukan Anda Salah\n");
        *ulangPtr = false;
    }
}

// fungsi untuk memberikan pilihan menu kepada user
void pilihanMenu(int* x){
    printf("PILIH \t\t\t: ");
    scanf("%d", &*x);
}

// fungsi untuk menghitung faktorial
int Faktorial(int n){
    if(n == 0 || n == 1){
        return 1;
    } else {
        return n*Faktorial(n-1);
    }
}
// fungsi untuk menghitung permutasi
int Permutasi(int n, int x){
    int hasilPermutasi = Faktorial(n)/Faktorial(n-x);
    return hasilPermutasi;
}

// fungsi untuk menghitung kombinasi
int Kombinasi(int n, int x){
    int hasilKombinasi = Faktorial(n)/(Faktorial(n-x)*Faktorial(x));
    return hasilKombinasi;
}

// fungsi untuk mengonversi satuan sudut dari derajat ke radian
double degreeToRad(double n){
    double rad = n*PI/180;
    return rad;
}

// fungsi untuk mengonversi satuan sudut dari radian ke derajat
double radToDegree(double n){
    double degree = n*180/PI;
    return degree;
}


// fungsi untuk menghitung standar deviasi populasi
double standarDevPop(double data[], int n){
    double average, sumSquare = 0, stDev;
    for(int i = 0; i <= n; i++){
        sum += data[i];
    }
    average = sum/n;
    for(int i = 0; i < n; i++){
        sumSquare += pow((data[i] - average), 2);
    }
    stDev = sqrt(sumSquare/n);
    return stDev;
}

// fungsi untuk menghitung standar deviasi sampel
double standarDevSam(double data[], int n){
    double average, sumSquare = 0, stDev;
    for(int i = 0; i < n; i++){
        sum += data[i];
    }
    average = sum/n;
    for(int i = 0; i < n; i++){
        sumSquare += pow((data[i] - average), 2);
    }
    stDev = sqrt(sumSquare/(n-1));
    return stDev;
}

// fungsi untuk menghitung deviasi rata-rata
double simpanganRataRata(double data[], int n){
    double average, sumAbs = 0;
    for(int i = 0; i < n; i++){
        sum += data[i];
    }
    average = sum/n;
    for(int i = 0; i < n; i++){
        sumAbs += abs(data[i] - average);
    }
    return sumAbs/n;
}

// fungsi untuk menghitung sigma (jumlahan data)
double sigma(double data[], int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += data[i];
    }
    return sum;
}

// fungsi untuk menghitung perkalian dua data
double product(double dataX[], double dataY[], int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += dataX[i]*dataY[i];
    }
    return sum;
}

// fungsi untuk menghitung jumlah kuadrat data
double kuadrat(double data[], int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += pow(data[i], 2);
    }
    return sum;
}

// fungsi untuk mengecek apakah sebuah bilangan termasuk prima atau bukan
void apaPrima(int n){
    int hasil;
    if(n > 1){
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0) {
                hasil = 0;
                break;
            }
        hasil = 1;
        }
    } else {
        hasil = 0;
    }

    if(hasil == 1){
        printf("%d adalah bilangan prima\n", n);
    } else {
        printf("%d bukan bilangan prima\n", n);
    }
}

// fungsi untuk mendata bilangan prima
void dataPrima(int a, int b){
    int primaData;
    printf("Data Bilangan Prima \t: ");
    for(int i = a; i <= b; i++){
        if(i > 1){
            for(int j = 2; j <= sqrt(i); j++){
                primaData = 1;
                if(i%j == 0){
                    primaData = 0;
                    break;
                }
            }
            if(primaData){
                printf("%d ", i);
            }
        }
    }
}

// Fungsi untuk mendata faktor bilangan
void faktor(int n){
    if(n > 0){
        for(int i = -1*n; i <= n; i++){
            if(i != 0 && n % i == 0){
                printf("%d ", i);
            }
        }
    } else {
        for(int i = n; i < 0; i++){
            if(n % i == 0){
                printf("%d ", i);
            }
        }
    }
}

// Fungsi untuk menghitung jumlah faktor bilangan
int sumPowFactor(int n, int p){
    for(int i = 1; i <= abs(n); i++){
        if(i != 0 && n % i == 0){
            sum += pow(i, p);
        }
    }
    return sum;
}

// fungsi untuk menghitung barisan aritmatika
double BarisanAritmatika(double a, double b, int n){
    return a+(n-1)*b;
}

// fungsi untuk menghitung deret aritmatika
double DeretAritmatika(double a, double b, int n){
    double Sn;
    for(int i = 1; i <= n; i++){
        Sn += a + (i-1)*b;
    }
    return Sn;
}

// fungsi untuk menghitung barisan geometri
double barisanGeometri(double a, double r, int n){
    return a*pow(r, n-1);
}

// fungsi untuk menghitung deret geometri
double deretGeometri(double a, double r, int n){
    double Sn;
    for(int i = 1; i <= n; i++){
        Sn += barisanGeometri(a, r, i);
    }
    return Sn;
}

// fungsi untuk menghitung barisan fibonacci
int fibonacci(int n){
    if(n == 1 || n == 2){
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// fungsi untuk membandingkan dua data
int banding(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Fungsi untuk menghitung modus 
double modus(double arr[], int n) {
    double modus = 0, hitungMax = 0, sekarang = 0, hitungSekarang = 0; 

    for (int i = 0; i < n; i++) {
        sekarang = arr[i];
        hitungSekarang = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] == sekarang) {
                hitungSekarang++;
            }
        }
        
        if (hitungSekarang > hitungMax) {
            hitungMax = hitungSekarang;
            modus = sekarang;
        }
    }
    return modus;
}

// fungsi untuk melakukan sorting data menaik
void sortingData(double array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// fungsi untuk menampilkan data dalam struct
void tampilkanStruct(const struct pilihanUser *contoh){
    printf("%s\n", contoh->pilihan);
}