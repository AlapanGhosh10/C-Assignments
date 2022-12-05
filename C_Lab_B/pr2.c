#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void partition(int arr[],int n);

int main()
{
  int n;
  printf("Enter the number of elements:--\n");
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
     }
  partition(a,n);

  return 0;

}
void partition(int arr[],int n)
{
  srand(time(NULL));  //preventing same sequence generation 
  int a= rand()%n;
  //printf("%d\n",arr[a]);
  int j=0,k=n-1;
  int tmp[n];
  //printf("%d",a);
  for(int i=0;i<n;i++)
  {
    if(arr[i]==arr[a]) continue;
    else if (arr[a]>arr[i])  tmp[j++]=arr[i];
    else tmp[k--]=arr[i];
  }
  tmp[j]=arr[a];
  printf("The random element is %d\n",arr[a]);
  printf("The elements less than %d are \n",arr[a]);
  for(int i=0;i<j;i++)
    printf("%d  ",tmp[i]);
  printf("\nThe elements after %d are \n",arr[a]);
  for(int i=j+1;i<n;i++)
    printf("%d  ",tmp[i]);


}
