#incluce<stdio.h>
int gcd(int, int);
int main() {
	int n;
	printf("Enter the number of numbers: ");
	scanf("%d", &n);

	int n1, n2;
	int max, lcm = 1;
	scanf("%d", n1);
	max = n1;
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", n2);
		if(n2 > max)
			max = n2;
		if(n1 == 0 || n2 == 0) {
			printf("Cannot be calculated(undefined)");
			return 0;
		}
		lcm *= gcd(n1, n2);
		n1 = n2;
	}
	lcm *= max;
