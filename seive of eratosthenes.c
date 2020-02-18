#include <stdio.h>
#include<math.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<=n;i++)
    {
        arr[i]=1;
    }
    arr[0]=0;
    arr[1]=0;
    for(i=2;i<=sqrt(n);i++)
    {
        if(arr[i]==1)
        {
            for(j=2;i*j<=n;j++)
            {
                arr[i*j]=0;
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(arr[i]==1)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
