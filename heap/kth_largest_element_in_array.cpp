#include<iostream> 
#include<climits> 
using namespace std; 

int hsize;
int *a;
void heapify(int i);

 void minheap(int arr[],int k)
 {
     int starti = (k-1)/2 ;
     hsize = k;
     a=arr;
     for(int i=starti;i>=0;i--)
     {
        heapify(i);
     }
 }

void heapify(int i)
{
    int small = i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<hsize && a[small]>a[l])
    small=l;
    if(r<hsize && a[small]>a[r])
    small=r;
    if(small!=i)
    {
        swap(a[small],a[i]);
        heapify(small);
    }
}

// Function to return k'th largest element in a given array 
int kthLargest(int arr[], int n, int k) 
{ 
	 minheap(arr,k);
	 
	 for(int i=k;i<n;i++)
	 {
	     if(arr[i]>a[0])
	     {
	         a[0]=arr[i];
	         heapify(0);
	     }
	 }
	 return a[0];
} 

// Driver program to test above methods 
int main() 
{ 
	int arr[] = {12, 3, 5, 7, 19}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 5; 
	cout << "K'th largest element is " << kthLargest(arr, n, k); 
	return 0; 
}