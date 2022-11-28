/*
10. Write a function to convert a decimal number to any other
    base given by the user.
*/

#include<stdio.h>

long changeBase(long n,long base){
    long ans=0,rem,mul=1;
    while(n>0){
        rem = n%base;
        ans+= rem*mul;
        mul*=10;
        n/=base; 
    }
    return ans;
}

int main(){
    long n,base;
    scanf("%ld %ld",&n,&base);
    printf("%ld",changeBase(n,base));
    return 0;
}