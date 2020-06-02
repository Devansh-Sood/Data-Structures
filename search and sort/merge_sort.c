#include <stdio.h>

void merge(int *a,int *l,int nl,int *r,int nr)
{
    int i=0,j=0,k=0;
    while(i<nl && j<nr)
    {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            k++;
            i++;
        }
        else
        {
            a[k]=r[j];
            k++;
            j++;
        }
    }
    while(i<nl)
    {
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<nr)
    {
        a[k]=r[j];
        k++;
        j++;
    }
}

void mergesort(int *a,int n)
{
    int mid,i;
    if(n<2)
    return ;
    mid=n/2;
    int left[mid],right[n-mid];
    
    for(i=0;i<mid;i++)
    {
        left[i]=a[i];
    }
    int c=0;
    for(i=mid;i<n;i++)
    {
        right[c]=a[i];
        c++;
    }
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(a,left,mid,right,n-mid);
}

void printArray(int *a,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergesort(arr,arr_size); 
  
     printf("\nSorted array is \n"); 
     printArray(arr, arr_size); 
    return 0; 
} 

