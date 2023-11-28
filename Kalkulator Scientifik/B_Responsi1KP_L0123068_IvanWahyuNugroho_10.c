/* Ivan Wahyu Nugroho
 B - L0123068 */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> // libarary math untuk perhitungan matematika
#include "EnumAndStruct.h"
#include "Fungsi.hpp"

int main()
{   
    struct data num, matdas, stat, LOG, barder;
    struct pilihanUser utama, barisder;
    strcpy(utama.pilihan, " 1. Operasi Matematika Dasar\n 2. Trigonometri\n 3. Logaritma\n 4. Statistika\n 5. Teori Bilangan\n 6. Berisan dan Deret");
    strcpy(barisder.pilihan, " 1. Barisan dan Deret Aritmatika\n 2. Barisan dan Deret Geometri\n 3. Barisan Fibonacci"); 

    // Program dimulai
    printf("\n       SELAMAT DATANG DI KALKULATOR SAINTIFIKU");
    do
    {
        // Menu Utama Kalkulator
        printf("\n_____________________________________________________\n");
        printf("\t\tKALKULATOR SAINTIFIKU\n");
        printf("_____________________________________________________\n");
        // Pilihan Mode
        tampilkanStruct(&utama);
        pilihanMenu(&pilihUtama);

       // Mode 1 (Operasi Dasar Matematika)
        if(pilihUtama == OPERASI_MATEMATIKA_DASAR){
            printf("_____________________________________________________\n");
            printf("OPERASI MATDAS \t: \n");
            for(int i = 0; i < sizeof(operasiMatdas)/sizeof(operasiMatdas[0]); i++){
                printf("%s\n", operasiMatdas[i]);
            }
            printf("_____________________________________________________\n");

            pilihanMenu(&pilihKedua);
            
            // Masuk Menu Kedua untuk mode 1
            switch (pilihKedua){

            // Operasi Perkalian
            case PERKALIAN: 
                printf("\n\n\t\tOPERASI PERKALIAN\n");
                printf  ("_____________________________________________________\n");
                printf("Bilangan Pertama \t: ");
                scanf("%lf", &matdas.db1);
                printf("Bilangan Kedua \t\t: ");
                scanf("%lf", &matdas.db2);
                printf("_____________________________________________________\n");
                matdas.hasil = matdas.db1*matdas.db2;
                printf("Operasi \t\t: %lf x %lf = %lf", matdas.db1, matdas.db2, matdas.hasil);
                tanyaUser();
                break;
            
            // Operasi Pembagian
            case PEMBAGIAN: 
                printf("\n\t\tOPERASI PEMBAGIAN\n");
                printf  ("_____________________________________________________\n");
                printf("Bilangan Pertama \t: ");
                scanf("%lf", &matdas.db1);
                printf("Bilangan Kedua \t\t: ");
                scanf("%lf", &matdas.db2);
                printf("_____________________________________________________\n");
                if(matdas.db2 == 0){
                    printf("Tidak Terdefinisi\n");
                } else {
                    matdas.hasil = matdas.db1/matdas.db2;
                    printf("Operasi \t\t: %lf / %f = %lf", matdas.db1, matdas.db2, matdas.hasil);
                }
                tanyaUser();
                break;

            // Operasi Penjumlahan
            case PENJUMLAHAN: 
                printf("\n\t\tOPERASI PENJUMLAHAN\n");
                printf  ("_____________________________________________________\n");
                printf("Bilangan Pertama \t: ");
                scanf("%lf", &matdas.db1);
                printf("Bilangan Kedua \t\t: ");
                scanf("%lf", &matdas.db2);
                printf("_____________________________________________________\n");
                matdas.hasil = matdas.db1+matdas.db2;
                printf("Operasi \t\t: %lf + %lf = %lf", matdas.db1, matdas.db2, matdas.hasil);
                tanyaUser();
                break;

            // Operasi Pengurangan
            case PENGURANGAN: 
                printf("\n\t\tOPERASI PENGURANGAN\n");
                printf  ("_____________________________________________________\n");
                printf("Bilangan Pertama \t: ");
                scanf("%lf", &matdas.db1);
                printf("Bilangan Kedua \t\t: ");
                scanf("%lf", &matdas.db2);
                printf("_____________________________________________________\n");
                matdas.hasil = matdas.db1-matdas.db2;
                printf("Operasi \t\t: %lf - %lf = %lf", matdas.db1, matdas.db2, matdas.hasil);
                tanyaUser();
                break; 

            // Operasi akar kuadrat
            case AKAR_KUADRAT: 
                printf("\n\t\tAKAR KUADRAT\n");
                printf("_____________________________________________________\n");
                printf("Bilangan \t\t: ");
                scanf("%lf", &matdas.db1);
                matdas.hasil = sqrt(matdas.db1);
                printf("Operasi \t\t: sqrt(%lf) = %lf", matdas.db1, matdas.hasil);
                tanyaUser();
                break;

            // Operasi akar pangkat tiga
            case AKAR_KUBIK:
                printf("\n\t\tAKAR PANGKAT TIGA\n");
                printf("_____________________________________________________\n");
                printf("Bilangan \t\t: ");
                scanf("%lf", &matdas.db1);
                matdas.hasil = cbrt(matdas.db1);
                printf("Operasi \t\t: cbrt(%lf) = %lf", matdas.db1, matdas.hasil);
                tanyaUser();
                break;

            // Operasi e^x
            case EPOWX:
                printf("\n\t\tEXP OF X\n");
                printf("_____________________________________________________\n");
                printf("Pangkat (x) \t\t: ");
                scanf("%lf", &matdas.db1);
                matdas.hasil = exp(matdas.db1);
                printf("Operasi \t\t: e^%lf = %lf", matdas.db1, matdas.hasil);
                tanyaUser();
                break;

            // Operasi Eksponensial
            case EKSPONENSIAL: 
                printf("\n\t\tOPERASI EKSPONENSIAL\n");
                printf("_____________________________________________________\n");  
                printf("Bilangan Pokok \t\t: ");
                scanf("%lf", &matdas.db1);
                printf("Pangkat \t\t: ");
                scanf("%lf", &matdas.db2);
                printf("_____________________________________________________\n");
                matdas.hasil = pow(matdas.db1, matdas.db2);
                printf("Operasi \t\t: %lf ^ %lf = %lf", matdas.db1, matdas.db2, matdas.hasil);
                tanyaUser();
                break;

            // Operasi faktorial
            case FAKTORIAL:
                printf("\n\t\tFAKTORIAL\n");
                printf("_____________________________________________________\n");
                printf("Bilangan \t\t: ");
                scanf("%d", &matdas.int1);
                printf("Hasil \t\t\t: %d! = %d", matdas.int1, Faktorial(matdas.int1));
                tanyaUser();
                break;
            
            // Operasi permutasi
            case PERMUTASI:
                printf("\n\t\tPERMUTASI (nPx)\n");
                printf("_____________________________________________________\n");
                printf("Bilangan cacah (n) \t: ");
                scanf("%d", &matdas.int1);
                printf("Bilangan cacah (x) \t: ");
                scanf("%d", &matdas.int2);
                printf("Hasil \t\t\t: %dP%d = %d", matdas.int1, matdas.int2, Permutasi(matdas.int1, matdas.int2));
                tanyaUser();
                break;

            // Operasi kombinasi
            case KOMBINASI:
                printf("\n\t\tKOMBINASI (nCx)\n");
                printf("_____________________________________________________\n");
                printf("Bilangan cacah (n) \t: ");
                scanf("%d", &matdas.int1);
                printf("Bilangan cacah (x) \t: ");
                scanf("%d", &matdas.int2);
                printf("Hasil \t\t\t: %dC%d = %d", matdas.int1, matdas.int2, Kombinasi(matdas.int1, matdas.int2));
                tanyaUser();
                break;

            // User salah memasukkan input
            default:
                printf("Masukan Anda salah\n");
                break;
            }

        } else if(pilihUtama == TRIGONOMETRI){
            // Operasi Trigonometri
            printf("_____________________________________________________\n");
            printf("TRIGONOMETRI \t\t: \n");
            for(int i = 0; i < sizeof(trigon)/sizeof(trigon[0]); i++){
                printf("%s\n", trigon[i]);
            }
       pilihanMenu(&pilihUtama);
            printf("_____________________________________________________\n");
            
            pilihanMenu(&pilihKedua);

            // sinus
            if(pilihKedua == TRIGONSIN){
                printf("\n\t\t\tSIN(X)\n");
                printf("_____________________________________________________\n");
                printf("Satuan sudut:\n 1. Derajat\n 2. Radian\n");
                pilihanMenu(&pilihKetiga);

                if(pilihKetiga == 1){
                    printf("Sudut(degree) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = sin(degreeToRad(stat.db1));
                    printf("Operasi \t\t: sin(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else if(pilihKetiga == 2){
                    printf("Sudut(radian) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = sin(stat.db1);
                    printf("Operasi \t\t: sin(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else {
                    printf("Masukan Anda Salah\n");
                }

            // cosinus
            } else if(pilihKedua == TRIGONCOS){
                printf("_____________________________________________________\n");
                printf("Satuan sudut:\n 1. Derajat\n 2. Radian\n");
                pilihanMenu(&pilihKetiga);
                if(pilihKetiga == 1){
                    printf("\n\t\t\tCOS(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(degree) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = cos(degreeToRad(stat.db1));
                    printf("Operasi \t\t: cos(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else if(pilihKetiga == 2){
                    printf("\n\t\t\tCOS(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(radian) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = cos(stat.db1);
                    printf("Operasi \t\t: cos(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else {
                    printf("Masukan Anda Salah\n");
                }

            // tangen
            }else if(pilihKedua == TRIGONTAN){
                printf("_____________________________________________________\n");
                printf("Satuan sudut:\n 1. Derajat\n 2. Radian\n");
                pilihanMenu(&pilihKetiga);
                if(pilihKetiga == 1){
                    printf("\n\t\t\tTAN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(degree) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = tan(degreeToRad(stat.db1));
                    printf("Operasi \t\t: tan(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else if(pilihKetiga == 2){
                    printf("\n\t\t\tTAN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(radian) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = tan(stat.db1);
                    printf("Operasi \t\t: tan(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else {
                    printf("Masukan Anda Salah\n");
                }

            // cosecan
            } else if(pilihKedua == TRIGONCSC){
                printf("_____________________________________________________\n");
                printf("Satuan sudut:\n 1. Derajat\n 2. Radian\n");
                pilihanMenu(&pilihKetiga);
                if(pilihKetiga == 1){
                    printf("\n\t\t\tCOSECAN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(degree) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = 1/sin(degreeToRad(stat.db1));
                    printf("Operasi \t\t: csc(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else if(pilihKetiga == 2){
                    printf("\n\t\t\tCOSECAN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(radian) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = 1/sin(stat.db1);
                    printf("Operasi \t\t: csc(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else {
                    printf("Masukan Anda Salah\n");
                }

            // secan
            } else if(pilihKedua == TRIGONSEC){
                printf("_____________________________________________________\n");
                printf("Satuan sudut:\n 1. Derajat\n 2. Radian\n");
                pilihanMenu(&pilihKetiga);
                if(pilihKetiga == 1){
                    printf("\n\t\t\tSECAN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(degree) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = 1/cos(degreeToRad(stat.db1));
                    printf("Operasi \t\t: sec(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else if(pilihKetiga == 2){
                    printf("\n\t\t\tSECAN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(radian) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = 1/cos(stat.db1);
                    printf("Operasi \t\t: sec(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else {
                    printf("Masukan Anda Salah\n");
                }

            // cotangen
            } else if(pilihKedua == TRIGONCOT){
                printf("_____________________________________________________\n");
                printf("Satuan sudut:\n 1. Derajat\n 2. Radian\n");
                pilihanMenu(&pilihKetiga);
                if(pilihKetiga == 1){
                    printf("\n\t\t\tCOTANGEN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(degree) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = 1/tan(degreeToRad(stat.db1));
                    printf("Operasi \t\t: cot(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else if(pilihKetiga == 2){
                    printf("\n\t\t\tCOTANGEN(X)\n");
                    printf("_____________________________________________________\n");
                    printf("Sudut(radian) \t\t: ");
                    scanf("%lf", &stat.db1);
                    stat.hasil = 1/tan(stat.db1);
                    printf("Operasi \t\t: cot(%lf) = %lf", stat.db1, stat.hasil);
                    tanyaUser();
                } else {
                    printf("Masukan Anda Salah\n");
                }                

            // invers sin
            } else if(pilihKedua == TRIGONASIN){
                printf("\n\t\tINVERS SIN(X)\n");
                printf("_____________________________________________________\n");
                printf("Sin \t\t\t: ");
                scanf("%lf", &stat.db1);
                stat.hasil = asin(stat.db1);
                printf("Operasi \t\t: asin(%lf) = %.3lf radian\n", stat.db1, stat.hasil);
                stat.hasil = radToDegree(stat.hasil);
                printf("Operasi \t\t: asin(%lf) = %.3lf degree", stat.db1, stat.hasil);
                tanyaUser();

            // invers cos
            } else if(pilihKedua == TRIGONACOS){
                printf("\n\t\t INVERS COS(X)\n");
                printf("_____________________________________________________\n");
                printf("Cos \t\t\t: ");
                scanf("%lf", &stat.db1);
                stat.hasil = acos(stat.db1);
                printf("Operasi \t\t: acos(%lf) = %.3lf radian\n", stat.db1, stat.hasil);
                stat.hasil = radToDegree(stat.hasil);
                printf("Operasi \t\t: acos(%lf) = %.3lf degree", stat.db1, stat.hasil);
                tanyaUser();

            // invers tan
            } else if(pilihKedua == TRIGONATAN){
                printf("\n\t\tINVERS TAN(X)\n");
                printf("_____________________________________________________\n");
                printf("Sudut(degree) \t\t: ");
                scanf("%lf", &stat.db1);
                stat.hasil = atan(stat.db1);
                printf("Operasi \t\t: atan(%lf) = %.3lf radian\n", stat.db1, stat.hasil);
                stat.hasil = radToDegree(stat.hasil);
                printf("Operasi \t\t: atan(%lf) = %.3lf degree", stat.db1, stat.hasil);
                tanyaUser();
                  
            // User memasukkan input lain
            } else {
                printf("\nMasukan Anda salah\n");
            }

        // Operasi Logaritma
        } else if(pilihUtama == LOGARITMA){
            printf("\nLOGARITMA \t\t: \n");
            printf("1. log()\n2. ln()\n3. Logaritma dengan Basis Lain\n");
            printf("_____________________________________________________\n");

            pilihanMenu(&pilihKedua);
            switch (pilihKedua){

            // Logaritma dengan basis 10
            case LOG10:
                printf("\n\t\t\tLOG(X)\n");
                printf("_____________________________________________________\n");
                printf("Numerus \t\t: ");
                scanf("%lf", &LOG.db1);
                LOG.hasil = log(LOG.db1)*logE;
                printf("Operasi \t\t: log(%.3lf) = %0.5lf", LOG.db1, LOG.hasil);
                tanyaUser();
                break;
            
            // Logaritma natural
            case LEN:
                printf("\n\t\t\tLOGARITMA NATURAL\n");
                printf("_____________________________________________________\n");
                printf("Numerus \t\t: ");
                scanf("%lf", &LOG.db1);
                LOG.hasil = log(LOG.db1);
                printf("Operasi \t\t: ln(%.3lf) = %.5lf", LOG.db1, LOG.hasil);
                tanyaUser();
                break;

            // Logaritma dengan basis lain
            case LOGBASISLAIN:
                printf("\n\t\t\tLOGARITMA\n");
                printf("_____________________________________________________\n");
                printf("Basis \t\t\t: ");
                scanf("%lf", &LOG.db1);
                printf("Numerus \t\t: ");
                scanf("%lf", &LOG.db2);
                LOG.hasil = log(LOG.db2)/log(LOG.db1);
                printf("Operasi \t\t: ^(%.2lf) log(%.2lf) = %.5lf", LOG.db1, LOG.db2, LOG.hasil);
                tanyaUser();
                break;

            default:
                printf("\nMasukan Anda salah\n");
                break;
            }

        // Operasi Statistika
        } else if(pilihUtama == STATISTIKA){
            printf("_____________________________________________________\n");
            printf("STATISTIKA \t\t: \n");
            for(int i = 0; i < sizeof(statistik)/sizeof(statistik[0]); i++){
                printf("%s\n", statistik[i]);
            }
            printf("_____________________________________________________\n");
            pilihanMenu(&pilihKedua);

            // Rata-Rata
            if(pilihKedua == MEAN){
                printf("\n\t\t\tAVERAGE\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                stat.int2 = 0;
                while(stat.int2 < stat.int1){
                    printf("Data ke-%d : ", stat.int2+1);
                    scanf("%lf", &stat.db1);
                    sum += stat.db1;
                    stat.int2++;
                }
                printf("Rata-Rata \t\t: %.3lf", sum/stat.int1);
                tanyaUser();

            // Median
            } else if(pilihKedua == MEDIAN){
                printf("\n\t\tMEDIAN DAN KUARTIL\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1], median, q1, q3;
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", &data[i]);
                }
                qsort(data, stat.int1, sizeof(int), banding);
    
                if (stat.int1 % 2 == 0) {
                    median = (data[stat.int1 / 2 - 1] + data[stat.int1 / 2]) / 2;
                } else {
                    median = data[stat.int1 / 2];
                }
                
                int dataTengah = stat.int1 / 2;
                if (stat.int1 % 2 == 0) {
                    q1 = (data[dataTengah / 2 - 1] + data[dataTengah / 2]) / 2.0;
                    q3 = (data[dataTengah + dataTengah / 2 - 1] + data[dataTengah + dataTengah / 2]) / 2.0;
                } else {
                    q1 = data[dataTengah / 2];
                    q3 = data[dataTengah + dataTengah / 2];
                }
                printf("Q1\t\t\t: %.3lf\n", q1);
                printf("Median (Q2) \t\t: %.3lf\n", median);
                printf("Q3\t\t\t: %.3lf\n", q3);
                tanyaUser();

            // Modus
            } else if(pilihKedua == MODUS){
                printf("\n\t\tMEDIAN DAN KUARTIL\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1];
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", &data[i]);
                }
                printf("The mode is: %.3lf\n", modus(data, stat.int1));
                tanyaUser();

            // Std Populasi dan variansi
            } else if(pilihKedua == STDEVPOP){
                printf("\n\t\tSTANDAR DEVIASI POPULASI\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1];
                double* dataPtr = data;
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", data+i);
                }
                printf("\nStandar Deviasi \t: %.5lf\n", standarDevPop(data, stat.int1));
                printf("Variansi/Ragam \t\t: %.5lf", pow(standarDevPop(data, stat.int1), 2));
                tanyaUser();

            // Std sampel dan variansi
            } else if(pilihKedua == STDEVSAM){
                printf("\n\t\tSTANDAR DEVIASI SAMPEL\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1];
                double* dataPtr = data;
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", dataPtr + i);
                }
                printf("\nStandar Deviasi \t: %.5lf\n", standarDevSam(data, stat.int1));
                printf("Variansi/Ragam \t\t: %.5lf", pow(standarDevSam(data, stat.int1), 2));
                tanyaUser();

            // Desil
            } else if(pilihKedua == DESIL){
                printf("\n\t\tDESIL\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1];
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", &data[i]);
                }
                printf("Desil ke berapa yang ingin Anda cari? (1-9) : ");
                scanf("%d", &stat.int2);
            
                if(stat.int2 < 1 || stat.int2 > 9){
                    printf("Masukan Anda Salah\n");
                } else {
                sortingData(data, stat.int1);
                stat.db1 = stat.int2*(stat.int1+1)/10;
                    if(stat.db1 == trunc(stat.db1)){
                        stat.int3 = trunc(stat.db1);
                        stat.db2 = data[stat.int3-1];
                    } else {
                        stat.int3 = trunc(stat.db1);
                        printf("\n%d", stat.int3);
                        stat.db2 = data[stat.int3] + (stat.db1-stat.int3)*(data[stat.int3-1] - data[stat.int3]);
                    }
                    printf("Desil : %.5lf", stat.db2);
                }
                tanyaUser();
            
            } else if(pilihKedua == PERSENTIL){
                printf("\n\t\tPERSENTIL\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1];
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", &data[i]);
                }
                printf("Persentil ke berapa yang ingin Anda cari? (0-100) : ");
                scanf("%d", &stat.int2);
            
                if(stat.int2 < 0 || stat.int2 > 100){
                    printf("Masukan Anda Salah\n");
                } else {
                sortingData(data, stat.int1);
                stat.db1 = stat.int2*(stat.int1+1)/100;
                    if(stat.db1 == trunc(stat.db1)){
                        stat.int3 = trunc(stat.db1);
                        stat.db2 = data[stat.int3-1];
                    } else {
                        stat.int3 = trunc(stat.db1);
                        printf("\n%d", stat.int3);
                        stat.db2 = data[stat.int3] + (stat.db1-stat.int3)*(data[stat.int3-1] - data[stat.int3]);
                    }
                    printf("Persentil : %.5lf", stat.db2);
                }
                tanyaUser();

            // Deviasi Rata-Rata
            } else if(pilihKedua == DEVIASIRATARATA){
                printf("\n\t\tSIMPANGAN RATA-RATA\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1];
                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", &data[i]);
                }
                printf("\nSimpangan Rata-Rata \t: %.5lf\n", simpanganRataRata(data, stat.int1));
                tanyaUser();

            // Data min, max, dan jangkauan
            } else if(pilihKedua == DATAMINMAXRANGE){
                printf("\n\t\tDATA MIN, MAX, DAN RANGE\n");
                printf("_____________________________________________________\n");
                printf("Banyak Data \t\t: ");
                scanf("%d", &stat.int1);
                double data[stat.int1], min, max;

                for(int i = 0; i < stat.int1; i++){
                    printf("Data ke-%d : ", i+1);
                    scanf("%lf", &data[i]);

                    if(i == 0){
                        min = data[0];
                        max = data[0];
                    } 
                    if(data[i] < min){
                        min = data[i];
                    } else if(data[i] > max){
                        max = data[i];
                    }
                }
                printf("_____________________________________________________\n");
                printf("\nData Minimum \t: %lf\n", min);
                printf("Data Maksimum \t: %lf\n", max);
                printf("Jangkauan \t: %.5lf\n", max-min);
                tanyaUser();
            
            // Regresi dan Korelasi
            } else if(pilihKedua == REGRESIKORELASI){
                printf("\n\t\tREGRESI DAN KORELASI\n");
                printf("_____________________________________________________\n");
                printf("Banyak Pasangan Data \t: ");
                scanf("%d", &stat.int1);
                printf("_____________________________________________________\n");
                double data[stat.int1];

                double dataX[stat.int1], dataY[stat.int1];
                for(int i = 0; i < stat.int1; i++){
                    printf("Data X ke-%d : ", i+1);
                    scanf("%lf", &dataX[i]);
                }
                printf("_____________________________________________________\n");
                for(int i = 0; i < stat.int1; i++){
                    printf("Data Y ke-%d : ", i+1);
                    scanf("%lf", &dataY[i]);
                }
                printf("_____________________________________________________\n");
                printf("Jumlah data X adalah \t: %.3lf\n", sigma(dataX, stat.int1));
                printf("Jumlah data Y adalah \t: %.3lf\n", sigma(dataY, stat.int1));
                printf("Jumlah data X^2 adalah \t: %.3lf\n", kuadrat(dataX, stat.int1));
                printf("Jumlah data Y^2 adalah \t: %.3lf\n", kuadrat(dataY, stat.int1));
                printf("Jumlah data XY adalah \t: %.3lf\n", product(dataX ,dataY, stat.int1));
                printf("_____________________________________________________\n");

                double r = (stat.int1*product(dataX, dataY, stat.int1) - sigma(dataX, stat.int1)*sigma(dataY, stat.int1))/(sqrt((stat.int1*kuadrat(dataX, stat.int1) - sigma(dataX, stat.int1)*sigma(dataX, stat.int1))*(stat.int1*kuadrat(dataY, stat.int1) - sigma(dataY, stat.int1)*sigma(dataY, stat.int1))));

                printf("KK Pearson (R) \t\t: %.3lf\n", r);
                printf("Hubungan \t\t: ");
                if(r > 0){
                    printf("Positif - ");
                } else {
                    printf("Negatif - ");
                }

                if(abs(r) < 0.2 && abs(r) >= 0){
                    printf("Sangat lemah");
                } else if(abs(r) >= 0.2 && abs(r) < 0.4){
                    printf("Lemah");
                } else if(abs(r) >= 0.4 && abs(r) < 0.6){
                    printf("Biasa");
                } else if(abs(r) >= 0.6 && abs(r) < 0.8){
                    printf("Sedang");
                } else if(abs(r) >= 0.6 && abs(r) < 0.8){
                    printf("Kuat");
                } else if(abs(r) >= 0.8 && abs(r) <= 1){
                    printf("Sangat Kuat");
                } 

                printf("\nKoef. Determinasi (R^2)\t: %.3f\n", pow(r, 2));
                printf("Besar Pengaruh X thd Y\t: %.3f\%\n", pow(r, 2)*100);

                double constReg, slopeReg;
                constReg = (sigma(dataY, stat.int1)*kuadrat(dataX, stat.int1) - sigma(dataX, stat.int1)*product(dataX, dataY, stat.int1))/(stat.int1*kuadrat(dataX, stat.int1) - sigma(dataX, stat.int1)*sigma(dataX, stat.int1));

                slopeReg = (stat.int1*product(dataX, dataY, stat.int1) - sigma(dataX, stat.int1)*sigma(dataY, stat.int1))/(stat.int1*kuadrat(dataX, stat.int1) - sigma(dataX, stat.int1)*sigma(dataX, stat.int1));

                if(constReg > 0){
                    printf("Persamaan Regresi \t: y = %.3lfx + %.3lf\n", slopeReg, constReg);
                } else {
                    printf("Persamaan Regresi \t: y = %.3lfx  %.3lf\n", slopeReg, constReg);
                }
                tanyaUser();

            } else {
                printf("\n\t\t   Masukan Anda salah\n");
            }
        
        // Teori Bilangan
        } else if(pilihUtama == TEORI_BILANGAN){
            printf("_____________________________________________________\n");
            printf("TEORI BILANGAN \t\t: \n");
            printf("1. Cek Apakah Prima\n2. Mendata Prima\n3. Modulo Eksponen\n4. Modulo Faktorial\n5. Faktor Bilangan\n");
            pilihanMenu(&pilihKedua);

            // Cek Apakah prima
            if(pilihKedua == APAKAHPRIMA){
                printf("\n\t\tCEK APAKAH PRIMA\n");
                printf  ("_____________________________________________________\n");
                printf("Bilangan \t\t: ");
                scanf("%d", &num.int1);
                apaPrima(num.int1);
                tanyaUser();

            // Mendata Bilangan Prima
            } else if(pilihKedua == MENDATAPRIMA){
                printf("\n\t\tMENDATA BILANGAN PRIMA\n");
                printf  ("_____________________________________________________\n");
                printf("Batas Bawah \t\t: ");
                scanf("%d", &num.int1);
                printf("Batas Atas \t\t: ");
                scanf("%d", &num.int2);
                dataPrima(num.int1, num.int2);
                tanyaUser();

            // Modulo eksponen
            } else if(pilihKedua == MODEXP){
                printf("\n\t\tMODULO EKSPONENSIAL\n");
                printf  ("_____________________________________________________\n");
                int angka3;
                printf("Bilangan Pokok \t\t: ");
                scanf("%d", &num.int1);
                printf("Bilangan Pangkat \t: ");
                scanf("%d", &num.int2);
                printf("Bilangan Pembagi \t: ");
                scanf("%d", &angka3);

                int hasil = pow(num.int1, num.int2);
                int sisa = hasil%angka3;
                if(hasil < 0){
                   hasil += angka3;
                }
                printf("Operasi \t\t: %d^%d (mod %d) = %d\n", num.int1, num.int2, angka3, sisa);
                tanyaUser();

            // Modulo Faktorial    
            } else if(pilihKedua == MODFAKTORIAL){
                printf("\n\t\tMODULO FAKTORIAL\n");
                printf  ("_____________________________________________________\n");
                int angka3;
                printf("Bilangan \t\t: ");
                scanf("%d", &num.int1);
                printf("Bilangan Pembagi \t: ");
                scanf("%d", &num.int2);

                int sisa = Faktorial(num.int1)%num.int2;
                printf("Operasi \t\t: %d! (mod %d) = %d", num.int1, num.int2, sisa);
                tanyaUser();

            // Faktor Bilangan
            } else if(pilihKedua == FAKTORPRIMA){
                printf("\n\t\tFAKTOR BILANGAN\n");
                printf  ("_____________________________________________________\n");
                printf("Bilangan \t\t: ");
                scanf("%d", &num.int1);

                printf("Faktor dari %d adalah ", num.int1);
                faktor(num.int1);
                if(num.int1 > 0){
                    printf("\nJumlah faktor positif dari %d adalah %d", num.int1, sumPowFactor(num.int1, 1));
                    printf("\nJumlah faktor negatif dari %d adalah -%d", num.int1, sumPowFactor(num.int1, 1)/2);
                } else {
                    printf("\nJumlah faktor positif dari %d adalah 0", num.int1);
                    printf("\nJumlah faktor negatif dari %d adalah -%d", num.int1, sumPowFactor(num.int1, 1)/2);
                }
                printf("\nJumlah kuadrat faktor dari %d adalah %d", num.int1, 2*sumPowFactor(num.int1, 2));
                tanyaUser();

            // User memasukkan input lain
            } else {
                printf("Masukan Anda salah\n");
            }
            
        // Barisan dan Deret
        } else if(pilihUtama == BARISAN_DAN_DERET){
            printf("_____________________________________________________\n");
            printf("TEORI BILANGAN \t\t: \n");
            tampilkanStruct(&barisder);
            pilihanMenu(&pilihKedua);

            // Barisan dan Deret Aritmatika
            if(pilihKedua == BARISANDERETARITMATIKA){
                printf("\n\t\tBARISAN DAN DERET ARITMATIKA\n");
                printf  ("_____________________________________________________\n");
                printf("Suku Pertama \t\t: ");
                scanf("%lf", &barder.db1);
                printf("Selisih Dua Suku Urut \t: ");
                scanf("%lf", &barder.db2);
                printf("Suku ke berapa? (n) \t: ");
                scanf("%d", &barder.int1);
                printf("Suku ke-%d adalah %.2lf\n", barder.int1, BarisanAritmatika(barder.db1, barder.db2, barder.int1));
                printf("Jumlah %d suku pertama adalah %.2lf\n", barder.int1, DeretAritmatika(barder.db1, barder.db2, barder.int1));
                tanyaUser();

            // Barisan dan Deret Geometri
            } else if(pilihKedua == BARISANDERETGEOMETRI){
                printf("\n\t\tBARISAN DAN DERET GEOMETRI\n");
                printf  ("_____________________________________________________\n");
                printf("Suku Pertama \t\t: ");
                scanf("%lf", &barder.db1);
                printf("Rasio Barisan \t: ");
                scanf("%lf", &barder.db2);
                printf("Suku ke berapa? (n) \t: ");
                scanf("%d", &barder.int1);
                printf("Suku ke-%d adalah %.2lf\n", barder.int1, barisanGeometri(barder.db1, barder.db2, barder.int1));
                printf("Jumlah %d suku pertama adalah %.2lf\n", barder.int1, deretGeometri(barder.db1, barder.db2, barder.int1));
                tanyaUser();

            // Barisan Fibonacci
            } else if(pilihKedua == BARISANFIBONACCI){
                printf("\n\t\tBARISAN FIBONACCI\n");
                printf  ("_____________________________________________________\n");
                printf("Suku ke berapa? (n) \t: ");
                scanf("%d", &barder.int1);
                printf("Suku ke-%d adalah %d\n", barder.int1, fibonacci(barder.int1));
                for(int i = 1; i < barder.int1; i++){
                    printf("%d, ", fibonacci(i));
                }
                printf("%d", fibonacci(barder.int1));
                tanyaUser();

            // User memasukkan input yang salah
            } else {
                printf("\n\t\t  Masukan Anda salah");
            }

        // User memasukkan input yang salah
        } else {
            printf("\n\t\t  Masukan Anda salah");
        }        

    } while (ulang);
    printf("\n_____________________________________________________\n");
    printf("\t\t   PROGRAM DIAKHIRI\n");
    printf("MAKASI DAH GUNAIN KALKULATOR KALKULATOR SAINTIFIKU\n\n");
    // Program diakhiri

    return 0;
}
