#include<stdio.h>
#include<math.h>


int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    double x = 1 / sqrt(5) * (pow((1 + sqrt(5)) / 2, n) - pow((1-sqrt(5)) / 2, n));
    double f1 = 1, f2 = 1, temp;
    while(n - 2 > 0){
        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
        n--;
    }

    printf("Actual Output: %.lf\n",f2);
    printf("Formula Output: %.lf\n",x);
    printf("Difference: %e\n", fabs(f2-x));
    return 0;
}
