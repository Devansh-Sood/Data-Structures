#include <stdio.h>

int binary(int a[],int f,int l,int d)
{
    int mid=(f+l+1)/2;
    if(a[mid]==d)
    {
        return mid;
    }
    if(a[mid]>d)
    {
        return binary(a,0,mid-1,d);
    }
    else
    {
        return binary(a,mid,l,d);
    }
}

int main()
{
    int i,j,n,d,a[10];
    scanf("%d",&n);
    scanf("%d",&d);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int res = binary(a,0,n-1,d);
    printf("Present at %d",res);
    return 0;
}
