/*
Input

Input any number: 22
Output

Highest order set bit in 22 is 4.
 */

#include<stdio.h>
int main()
{
    int i,num,bit;
    scanf("%d",&num);
    for(i=31;i>=0;i--)
    {
        if(num & (1<<i))
        {
            bit=i;
            break;
        }
    }
    printf("Highest set bit is %d",bit);

}