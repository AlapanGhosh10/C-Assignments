#include<stdio.h>
int hcf(int , int );

int main(){
  int n1, n2;
  printf("Enter First Number: ");
  scanf("%d",&n1);
  printf("Enter Second Number: ");
  scanf("%d",&n2);

  
  int res = hcf(n1, n2);
  printf("The GCD of %d and %d: %d\n",n1, n2, res);
  return 0;
}

int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}
