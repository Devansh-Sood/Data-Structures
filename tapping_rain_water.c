/*Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
       | 
   |   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2 
watertrap

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   int a[10];
   int i=0,j,lmax=0,rmax=0,s=0,n;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   i=0;
   j=n-1;
   while(i<j)
   {
       if(a[i]<a[j])
       {
           if(a[i]>lmax)
           {
               lmax=a[i];
           }
           else
           {
               s=s+lmax-a[i];
           }
           i++;
       }
       else
       {
           if(a[j]>rmax)
           {
               rmax=a[j];
           }
           else
           {
               s=s+rmax-a[j];
           }
           j--;
       }
   }
   printf("%d",s);
    return 0;
}