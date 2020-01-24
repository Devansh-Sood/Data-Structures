#include <stdio.h>

int main()
{
   int i,n;
   scanf("%d",&n);
   int a[n];
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   int ms=0,me=0;
   for(i=0;i<n;i++)
   {
       me=me+a[i];
       if(me<0)
       {
           me=0;
       }
       else
       {
       if(me>ms)
       {
           ms=me;
       }
       }
   }
   printf("%d",ms);
    return 0;
}
