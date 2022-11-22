#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print(double *arr, int m, int n)
{
      int i, j;
      for (i = 0; i < m; i++)
      {
           for (j = 0; j < n; j++)
           {
               printf("%.2lf  ", *((arr + i * n) + j));
           }
           printf("\n");
      }


}

int main()
{
     int n;
     printf("Enter value of n for the n x n matrix: ");
     scanf("%d",&n);
     double m1[n][n], m2[n][n], m3[n][n];
     for(int i = 0; i < n ; i++)
      {
           double sum = 0;
           for(int j = 0 ; j < n-1 ; j++)
               {
                    double d = (rand() % 100);
                    m1[i][j] = d;
                    m2[i][j] = d;
                    m3[i][j] = d;
                    sum += m1[i][j];
                } 
                m1[i][n-1] = 1 - sum;
                m2[i][n-1] = 1 - sum;
                m3[i][n-1] = 1 - sum;
       }
       
       printf("\nMatrix M: \n");
       print((double *)m1, n, n);
       
       int p;
       printf("\nEnter the value of p for M^p: ");
       scanf("%d",&p);
       
       int temp = p;
       while(--p) {
   	       for(int i = 0 ; i < n ; i++){
               	for(int j = 0 ; j < n ; j++) {
                      if(p % 2 != 0) 
                      	m2[i][j] = 0;
                      else 
                      	m3[i][j] = 0;
                      for(int k = 0 ; k < n ; k++) {
                      	if(p % 2 != 0) 
                        	m2[i][j] += m3[i][k] * m1[k][j];
                        else
                              	m3[i][j] += m2[i][k] * m1[k][j];
                     }
                }
               }
      }
      
      printf("\nMatrix M^%d: \n",temp) ;
      print((double *)m2, n, n);
      
      double f = 1 / (double)n;
      double R[n][1];
      for(int i = 0 ; i < n ; i++)
      {
         R[i][0] = f; 
      }
      
      printf("\nColumn Vector R:\n");
      print((double *)R, n, 1);  

      printf("\n(M ^ %d) * R:\n",temp);
      double ans[n][1];
      for(int i = 0 ; i < n ; i++)
      {
        ans[i][0] = 0;
      	for(int j = 0 ; j < n ; j++)
     	{
          ans[i][0] += m2[i][j]*R[j][0];
     	}
      }
      print((double *)ans, n, 1);

      printf("\nTherefore (M^%d) * R == R \n",temp);
      return 0;
}
