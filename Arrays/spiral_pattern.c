#include <stdio.h>

int main()
{
    int n,i,j,a,b,c,d,t=1;
    scanf("%d",&n);
    
   int arr[n][n];
   a=0;
   b=n-1;
   c=n-1;
   d=0;
   while(a<=c && d<=b)
   {
       for(i=d;i<=b;i++)
       {
           arr[a][i]=t++;
       }
       a++;
       for(i=a;i<=c;i++)
       {
           arr[i][b]=t++;
       }
       b--;
       for(i=b;i>=d;i--)
       {
           arr[c][i]=t++;
       }
        c--;
       for(i=c;i>=a;i--)
       {
           arr[i][d]=t++;
       }
       d++;
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           printf("%d ",arr[i][j]);
       }
       printf("\n");
   }
    return 0;
}
