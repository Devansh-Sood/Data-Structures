#include <iostream> 
  
using namespace std;
 
void heapify(int arr[], int n, int i) 
{ 
     int large = i;
     int l=i*2+1;
     int r=i*2+2;
     if(l<n && arr[l]<arr[large])
     large=l;
     if(r<n && arr[r]<arr[large])
     large=r;
     if(large!=i)
     {
         swap(arr[i],arr[large]);
         heapify(arr,n,large);
     }
} 
  

void buildHeap(int arr[], int n) 
{ 
     int startind = n/2 -1;
     for(int i=startind;i>=0;i--)
     {
         heapify(arr,n,i);
     }
} 
  

void printHeap(int arr[], int n) 
{ 
    cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver Code 
int main() 
{ 
    // Binary Tree Representation 
    // of input array 
    //                1 
    //            /        \ 
    //          3          5 
    //        /    \     /  \ 
    //       4      6   13  10 
    //      / \    / \ 
    //    9   8  15   17 
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    buildHeap(arr, n); 
  
    printHeap(arr, n); 
  
    return 0; 
} 