#include <stdio.h>

int main()
{
   int banyakData;
   printf("Banyak data  : ");
   scanf("%d", &banyakData);

   double data[banyakData];
   double* dataPtr = data, sum;
   for(int i = 0; i < banyakData; i++){
      printf("Data ke-%d   : ", i+1);
      scanf("%lf", dataPtr+i);
      sum += *(dataPtr + i);
   }

   printf("Jumlah data  %.3lf: ", sum);
   return 0;
}
