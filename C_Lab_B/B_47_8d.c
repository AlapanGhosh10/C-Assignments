/*
    d)to find the sum of the digits of any number.
*/
#include<stdio.h>

long sumDigits(long num){
    if(num==0)  return 0;
    return num%10 + sumDigits(num/10);
}

int main(){
    long n;
    scanf("%ld",&n);
    printf("%ld",sumDigits(n));
}