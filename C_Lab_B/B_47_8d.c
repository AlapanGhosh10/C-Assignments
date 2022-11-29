#include<stdio.h>

long sumOfDigits(long num){
    if(num == 0)  
    	return 0;
    return num % 10 + sumOfDigits(num / 10);
}

int main(){
    long num;
    printf("Enter a number: ");
    scanf("%ld",&num);
    printf("The sum of the digits is: %ld\n", sumOfDigits(num));
}
