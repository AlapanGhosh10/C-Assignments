#include<stdio.h>
int main(){
  
   int arr1[2][3],arr2[2][3],merarray[2][6];
   
   int i, j;
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("Enter value for arr1[%d][%d]:", i, j);
         scanf("%d", &arr1[i][j]);
      }
   }

  printf("\n");

  for(int x=0; x<2; x++) {
      for(int y=0;y<3;y++) {
         printf("Enter value for arr2[%d][%d]:", x, y);
         scanf("%d", &arr2[x][y]);
      }
   }

   
   printf("\nTwo Dimensional array 1 elements are before sorting:\n");
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("%d ", arr1[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }

   printf("\nTwo Dimensional array 2 elements are before sorting:\n");
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("%d ", arr2[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }

int k,m,n;
  for(k=0; k< 2; k++) {
   for (i = 0; i < 3; i++) {
     for (j = i +1; j < 3; ++j) {
       if (arr1[k][i] > arr1[k][j])  {
           int swap = arr1[k][i];
           arr1[k][i] = arr1[k][j];
           arr1[k][j] = swap;
       }
     }
   } 
}

for(k=0; k< 2; k++) {
   for (i = 0; i < 3; i++) {
     for (j = i +1; j < 3; ++j) {
       if (arr2[k][i] > arr2[k][j])  {
           int temp = arr2[k][i];
           arr2[k][i] = arr2[k][j];
           arr2[k][j] = temp;
       }
     }
   } 
}

printf("\nTwo Dimensional array 1 elements are after sorting :\n");
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("%d ", arr1[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }

printf("\nTwo Dimensional array 2 elements are after sorting :\n");
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("%d ", arr2[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }

  for(int x=0; x<2; x++) {
      for(int y=0;y<3;y++) {
         merarray[x][y] = arr1[x][y] ;
        //  printf("the value for merge array[%d][%d]: %d\n", x, y,merarray[x][y]);
      }
      int m = 0;
      for(int z=3;z<6;z++) {
         merarray[x][z] = arr2[x][m++] ;
        //  printf("the value for merge array[%d][%d]: %d\n", x, z,merarray[x][z]);
      }
   }

  for(k=0; k< 2; k++) {
   for (i = 0; i < 6; i++) {
     for (j = i +1; j < 6; ++j) {
       if (merarray[k][i] > merarray[k][j])  {
           int tem = merarray[k][i];
           merarray[k][i] = merarray[k][j];
           merarray[k][j] = tem;
       }
     }
   } 
}

printf("\nTwo Dimensional merge array sorting elements are :\n");
   for(i=0; i<2; i++) {
      for(j=0;j<6;j++) {
         printf("%d   ", merarray[i][j]);
         if(j==5){
            printf("\n");
         }
      }
   }

   return 0;
}