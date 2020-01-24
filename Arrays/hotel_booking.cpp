#include <bits/stdc++.h> 
using namespace std; 
  
bool areBookingsPossible(int a[],int d[], int n, int k) 
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            
            if(d[i]>d[j])
            {
                int t=d[i];
                d[i]=d[j];
                d[j]=t;
            }
            
        }
    }
    int x=0;
    i=0,j=0;
    while(i<n && j<n)
    {
        if(a[i]<d[j])
        {
            x++;
            i++;
        }
        else
        {
            x--;
            j++;
        }
        if(k<x)
    return false;
    }
    return true;
}


int main() 
{ 
    int arrival[] = { 1, 3, 7 }; 
    int departure[] = { 2, 6, 8 }; 
    int n = sizeof(arrival) / sizeof(arrival[0]); 
    cout << (areBookingsPossible(arrival, 
                                 departure, n, 1) 
                 ? "Yes\n"
                 : "No\n"); 
    return 0; 
} 