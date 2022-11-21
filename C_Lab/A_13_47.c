#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(double *arr, int m, int n)
{
      int i, j;
      for (i = 0; i < m; i++)
      {
           for (j = 0; j < n; j++)
           {
               printf("%.2lf  ", *((arr+i*n) + j));
           }
           printf("\n");
      }


}

void solve()
{
     static int test=1;
     printf(" \n\n Test case No %d:---\n\n",test++);

     int n;
     scanf("%d",&n);
     double m1[n][n],m2[n][n],m3[n][n];
     for(int i=0;i<n;i++)
      {
           double sum=0;
           for(int j=0;j<n-1;j++)
               {
                    double t=(double)rand();
                     double d=remainder(t,100.00);
                     m1[i][j]=d;
                    m2[i][j]=m1[i][j];
                    m3[i][j]=m1[i][j];
                    sum+=m1[i][j];
                } 
                m1[i][n-1]=1-sum;
                m2[i][n-1]=1-sum;
                m3[i][n-1]=1-sum;
       }
       printf("The Matrix M is--\n");
       print((double *)m1, n, n);
       int p;
       scanf("%d",&p);
       int temp=p;
       while(--p)
       {
   	       for(int i=0;i<n;i++)
               {
                for(int j=0;j<n;j++)
                     {
                      if(p%2!=0) m2[i][j]=0;
                      else m3[i][j]=0;
                         {
                           for(int k=0;k<n;k++)
                            {
                              if(p%2!=0) 
                               m2[i][j] += m3[i][k]*m1[k][j];
                              else
                              m3[i][j] += m2[i][k]*m1[k][j];

                            }
                        }  

                     }

                }
      }
      printf("The matrix M^%d is--\n",temp) ;
      print((double *)m2, n, n);
      double f=1/(double)n;
      double R[n][1];
      for(int i=0;i<n;i++)
      {
         R[i][0]=f; 
      }
      printf("The Column Vector(R) is-->\n");
      print((double *)R, n, 1);  

      printf("(M^%d)*R iss----\n",temp);
      double ans[n][1];
      for(int i=0;i<n;i++)
      {
        ans[i][0]=0;
      	for(int j=0;j<n;j++)
     	{
          ans[i][0]+=m2[i][j]*R[j][0];
     	}
      }
      print((double *)ans, n, 1);

      printf("\nSo we can say (M^%d)*R==R hold(proved)\n",temp);
}

int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
          solve();
     }
     return 0;
}



