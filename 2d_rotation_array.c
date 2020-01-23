#include <stdio.h>

int main()
{
    int n,i,j,m;
    scanf("%d",&n);
    scanf("%d",&m);
   int arr[n][n];
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           scanf("%d",&arr[i][j]);
       }
   }
   
   int temp=0;
   if(n==m)
    {
   for(i=0;i<n/2;i++)
   {
       for(j=i;j<m-1-i;j++)
       {
           temp=arr[i][j];
           arr[i][j]=arr[n-1-j][i];
           arr[n-1-j][i]=arr[n-1-i][m-1-j];
           arr[n-1-i][m-1-j]=arr[j][m-1-i];
           arr[j][m-1-i]=temp;
       }
   }
   
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           printf("%d ",arr[i][j]);
       }
       printf("\n");
   }
    }
    return 0;
}
