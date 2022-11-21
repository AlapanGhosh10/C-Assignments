#include <stdio.h>

long long findGCD(long long a, long long b){
    if(b == 0)
        return a;
    return findGCD(b, a % b);
}

int main() {
    int size, j;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter elements:\n");
    long array[size];
    for(j = 0 ; j < size ; j++){
        scanf("%ld", &array[j]);
    }

    long long lcm = array[0];;
    long long  gcd = array[0];
 
  
    for(int i = 0; i < size ; i++){
      gcd = findGCD(array[i], lcm);
      lcm = (lcm * array[i]) / gcd;
    }
    
    if((int)lcm == 0){
        printf("Cannot be calculated(undefined)\n");
        return 0;
    } else{
        printf("Output: %lld\n", lcm);
        return 0;
    }
}



