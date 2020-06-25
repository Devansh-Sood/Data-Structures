#include<iostream> 
#include<climits> 
using namespace std; 

	int *harr; // pointer to array of elements in heap  
	int heap_size; // Current number of elements in max heap 
	void maxHeapify(int i); //To maxHeapify subtree rooted with index i 

void MaxHeap(int a[], int size) 
{ 
	heap_size = size; 
	harr = a; // store address of array 
	int i = (heap_size - 1)/2; 
	while (i >= 0) 
	{ 
		maxHeapify(i); 
		i--; 
	} 
} 

// Method to remove maximum element (or root) from max heap 


// A recursive method to heapify a subtree with root at given index 
// This method assumes that the subtrees are already heapified 
void maxHeapify(int i) 
{ 
	int l = 2*i+1; 
	int r = 2*i+2; 
	int largest = i; 
	if (l < heap_size && harr[l] > harr[largest]) 
		largest = l; 
	if (r < heap_size && harr[r] > harr[largest]) 
		largest = r; 
	if (largest != i) 
	{ 
		swap(harr[i], harr[largest]); 
		maxHeapify(largest); 
	} 
} 

// Function to return k'th largest element in a given array 
int kthSmallest(int arr[], int n, int k) 
{ 
	// Build a heap of first k elements: O(k) time 
	MaxHeap(arr, k); 

	// Process remaining n-k elements. If current element is 
	// smaller than root, replace root with current element 
	for (int i=k; i<n; i++)
    {
		if (arr[i] < harr[0]) 
        {
          // to replace root with new node x and heapify() new root 
		harr[0] = arr[i];
        maxHeapify(0); 
        }
    }

	// Return root 
	return harr[0]; 
} 

// Driver program to test above methods 
int main() 
{ 
	int arr[] = {12, 3, 5, 7, 19}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 2; 
	cout << "K'th smallest element is " << kthSmallest(arr, n, k); 
	return 0; 
}