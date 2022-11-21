#include<stdio.h>

int main(){
	long double  num, ans;
	int pow;
	
	printf("Enter value of n = ");
	scanf("%Lf",&num);
	
	printf("Enter value of p = ");
	scanf("%d",&pow);
	
	if(num == 0 && pow <= 0){
		printf("Undefined\n");
	} else if(num == 0 && pow >= 0){
		ans = 0;
		printf("Output: %Lf\n", ans);
	} else if(pow < 0 && num < 0){
		long double ans = 1;
		int i;
		pow *= -1;
		for(i = 1 ; i <= pow ; i++){
			ans *= 1.0 / num;
		}
		printf("Output: %Lf\n",ans);
	} else{
		long double ans = 1;
		int i;
		for(i = 1 ; i <= pow ; i++){
			ans *= num;
		}
		printf("Output: %Lf\n", ans);
	}
	
	return 0;
}
