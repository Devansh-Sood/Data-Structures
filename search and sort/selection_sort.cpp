#include <bits/stdc++.h> 
using namespace std; 
  
void selectionSort(int arr[], int n)  
{  

    int imin=0,temp=0;  
  
    for (int i = 0; i < n-1; i++)  

    {  
        imin= i;  
        for (int j = i+1; j < n; j++)  
        {
            if (arr[j] < arr[imin])  
            imin = j;  
        }          
        temp=arr[imin] ;
        arr[imin]=arr[i];
        arr[i]=temp;
    }  
}  
  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)
    {  
        cout << arr[i] << " ";
    }  
    cout << endl;  
}  
  
int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
} 