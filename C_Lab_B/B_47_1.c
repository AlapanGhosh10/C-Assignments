#include<stdio.h>
#include<limits.h>
 
int main()
{
    int len;
    printf("Enter the size of array: ");
    scanf("%d",&len);

    if(len < 5 ){
      printf("Please enter minimum of five elements.");
      return 0;
    }

    int arr[len];
    printf("Enter elements of the array: ");
    for(int j = 0 ; j < len ; j++)
      scanf("%d",&arr[j]);
    
    
    
    int firMin = INT_MAX, secMin = INT_MAX, thrMin = INT_MAX, forMin = INT_MAX, fifMin= INT_MAX;
    int firMax = INT_MIN, secMax = INT_MIN, thrMax = INT_MIN;
    for (int i = 0; i < len ; i++)
    {
        if (arr[i] < firMin)
        {
            fifMin = forMin;
            forMin = thrMin;
            thrMin = secMin;
            secMin = firMin;
            firMin = arr[i];
        }
 
        else if (arr[i] < secMin)
        {
            fifMin = forMin;
            forMin = thrMin;
            thrMin = secMin;
            secMin = arr[i];
        }
 
        else if (arr[i] < thrMin){
            fifMin = forMin;
            forMin = thrMin;
            thrMin = arr[i];
        }
        else if (arr[i] < forMin){
            fifMin = forMin;
            forMin = arr[i];
        }
        else if (arr[i] < fifMin)
            fifMin = arr[i];

        if (arr[i] > firMax)
        {
            thrMax = secMax;
            secMax = firMax;
            firMax = arr[i];
        }
 
        else if (arr[i] > secMax)
        {
            thrMax = secMax;
            secMax = arr[i];
        }
 
        else if (arr[i] > thrMax)
            thrMax = arr[i];
    }
 
    printf( "Fifth Minimum Element: %d\n",fifMin);
    printf( "Third Maximum Element: %d\n",thrMax);
    printf( "Middle Element: %d\n", arr[len / 2 - 1]);
    return 0;
}
