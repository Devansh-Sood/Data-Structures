/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void reverse(int *a,int n,int k)
{
    int i=0,l=0,r=0,q=0,w=0,e=0;
    for(i=0;i<n;i=i+3)
    {
        l=i;
        q=i+k-1;
        w=n-1;
        if(q<w)
        r=q;
        else
        r=w;
        
        while(l<r)
        {
            e=a[r];
            a[r]=a[l];
            a[l]=e;
            l++;
            r--;
        }
    }
    
}

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    int k = 3; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    reverse(arr, n, k); 
  
    for (int i = 0; i < n; i++) 
       printf("%d ",arr[i]);
  
    return 0; 
} 
