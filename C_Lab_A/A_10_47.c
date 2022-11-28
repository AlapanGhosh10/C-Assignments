#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(){
    char s1[50];
    int i, len;
    int flag = 0;
    
    printf("Enter number: ");
    scanf("%s", s1);
    
    len = strlen(s1);
    
    if (len >= 15){
    	for(i = 0;i < len ;i++){
    	    if(s1[i] != s1[len-i-1]){
    	        flag = 1;
    	        break;
    	       }
    	    }
    	printf("Reverse = %s\n", strrev(s1));
    	if(flag) {
        	printf("\nIt is not a palindrome\n");
    	} else {
        	printf("\nIt is a palindrome\n");
    	}
    	return 0;
    } 
    else{
  	long n,m,r,rev=0;
  	n = atoi(s1);
	m = n;
	while(m > 0)
	{
		r = m % 10;
		rev = rev * 10 + r;
		m = m / 10;
	}
  	printf("Reverse = %ld", rev);
	if(rev == n)
		printf("\nIt is palindrome\n");
	else
		printf("\nIt is not palindrome\n");
  }

}
