#include <stdio.h>  
#include <string.h> 

void revStrRec(char *str1)  
{    
    static int i, len, temp;  
    len = strlen(str1); 
      
      
    if (i < len / 2){  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
        i++;  
        revStrRec(str1); 
    }  
}  
   
void revStrItr(char *str1, int len)  
{  
    
    int temp;  
  
    for (int i = 0; i < len/2; i++)  
    {   
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
      
int main()  
{
	char str[50], strHold[50];  
        printf ("Enter String: ");  
        fgets(str, 50, stdin);
        int len = strlen(str);
        strcpy(strHold, str);     
        
        printf ("\nBefore reversing string:  \n%s\n", str);  
            
        revStrItr(str, len);  
        printf ("After reversing using iterative function:  %s\n\n", str);  

        revStrRec(strHold);
	printf ("After reversing using recursive function:  %s\n\n", strHold); 

}


