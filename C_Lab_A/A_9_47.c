#include<stdio.h>
long long isPrime(long long );

int main(){
    long long n1=2, n2;
    printf("Enter the limit n: ");
    scanf("%lld", &n2);

    if(n2 <= 2){
        printf("No prime number is present\n");
        return 0;
    }

    printf("The prime numbers between %lld and %lld are: ",n1, n2);

    for (long long i = n1; i < n2; i++)
    {
        if(isPrime(i)){
            printf("%lld ", i);
        }
    }
    printf("\n");
    return 0;
}

long long isPrime(long long n){

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0){
       	    return 0;
        }
    }
    return 1;
}
