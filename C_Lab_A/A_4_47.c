#include<stdio.h>
void toIndian(long );
void toInternational(long );
int numWord(long );
int main(){
	long num;
	
  	printf("Enter amount: ");
	scanf("%ld",&num);
	
  	printf("Indian Number System: ");
	toIndian(num);
	printf("\n");
	
  	printf("International Number System: ");
	toInternational(num);
	printf("\n");
	
	return 0;
}

void toIndian(long n){
	long arr[]={10000000, 100000, 1000};
	char ind[][10]={"crore", "lakh", "thousand"};
	for(int i = 0 ; i < 3 ; i++){
		if(numWord(n / arr[i]))
			printf(" %s ", ind[i]);
		n %= arr[i];		
	}
	numWord(n);
}

void toInternational(long n){
	long arr[] = {1000000, 1000};
	char inl[][10] = {"million", "thousand"};
	for(int i = 0 ; i < 2 ; i++){
		if(numWord(n / arr[i]))
			printf(" %s ", inl[i]);
		n %= arr[i];
	}
	numWord(n);
}

char s1[][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

char s2[][10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int numWord(long n){
	int len = 0,n3,n2,n1;
	int temp = n;
	while(temp > 0){
		temp /= 10;
		len++;
	}
	
	if(len == 0){
		return 0;
	} else if(len == 1){
		printf("%s",s1[n]);
		return 1;
	} else if(len == 2){
		if(n <= 20){
			printf("%s",s1[n]);
			return 1;
		} else{
			n2 = n % 10;
        		n1 = (n - n2) / 10;
			printf("%s %s",s2[n1],s1[n2]);
			return 1;
		}
	} else {
		n3 = n % 10;
		n2 = ((n - n3) / 10) % 10;
		n1 = (n - n2 * 10 - n3) / 100;
		printf("%s hundred ",s1[n1]);
		if(n2 * 10 + n3 <= 20){
			printf("%s",s1[n2 * 10 + n3]);
		} else{
			printf("%s %s",s2[n2], s1[n3]);
		}
		return 1;
	}
}
