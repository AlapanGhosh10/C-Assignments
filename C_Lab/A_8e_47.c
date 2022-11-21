#include <stdio.h>
#include <math.h>

long long int getNextPrime(long long int prevPrime)
{
    long long int nextPrime = prevPrime + 1;
    while (1)
    {
        int flag = 1;
        for (long long int i = 2; i <= nextPrime / 2; i++)
        {
            if (nextPrime % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return nextPrime;
        }
        nextPrime++;
    }
}

int main(){

    int n;
            long long int result = 0;
            printf("Enter value of n: ");
            scanf("%d", &n);
            long long int prevPrime = 2;
            for (int i = 1; i <= n; i++)
            {
                long long int nextPrime = getNextPrime(prevPrime);
                result += prevPrime * nextPrime;
                prevPrime = nextPrime;
            }
            printf("2*3 + 3*5 + 5*7 + ... = %lld\n", result);

    return 0;
}
