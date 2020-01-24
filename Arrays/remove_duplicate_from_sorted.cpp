#include <iostream>

using namespace std;

int removeDuplicates(int arr[], int n) 
{
    int i=0,j=1,c=0;
    while(i<n)
    {
        if(arr[i]!=arr[j])
        {
            arr[c]=arr[i];
            i++;
            j++;
            c++;
        }
        else
        {
            j++;
            i++;
        }
    }
    return c;
}

int main() 
{ 
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // removeDuplicates() returns new size of 
    // array. 
    n = removeDuplicates(arr, n); 
  
    // Print updated array 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
  
    return 0; 
} 