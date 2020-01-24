/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int maximumOccurredElement(int L[], int R[], int n) 
{
    int max=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(R[i]>max)
        {
            max=R[i];
        }
    }
    int a[max];
    for(i=0;i<=max;i++)
    {
        a[i]=0;
    }
    i=0;
   
    while(i<n)
    {
        a[L[i]] =a[L[i]]+1;
        a[R[i]+1] =a[R[i]+1]-1;
        i++;
    }
    i=1;
    int m1=-1,ind;
    while(i<max)
    {
        a[i]=a[i]+a[i-1];
        if(a[i]>m1)
        {
        m1=a[i];
        ind=i;
        }
        i++;
    }

    return ind;
}

int main() 
{ 
    int L[] = { 1, 4, 3,1 }; 
    int R[] = { 15, 8, 5,4}; 
    int n = sizeof(L) / sizeof(L[0]); 
  
    cout << maximumOccurredElement(L, R, n) << endl; 
    return 0; 
} 
