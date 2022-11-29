#include<stdio.h>
long convert(long, int);

int main(){
    long n;
    int base;
    printf("Enter the number in decimal: ");
    scanf("%ld",&n);
    printf("Enter the base to convert to: ");
    scanf("%d", &base);
    printf("The number in Base %d is: ", base);
    printf("%ld\n",convert(n,base));
    return 0;
}

long convert(long n, int base){
    long res = 0, rem, pro = 1;
    while(n > 0){
        rem = n % base;
        res += rem * pro;
        pro *= 10;
        n /= base; 
    }
    return res;
}
