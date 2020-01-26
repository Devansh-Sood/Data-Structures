/* 
Input

Input number: 22
Input nth bit to toggle: 1
Output

After toggling nth bit: 20 (in decimal)
*/

#include<stdio.h>
int main()
{
    int i,num,bit;
    scanf("%d",&num);
    scanf("%d",&bit);
    int status= num ^ (1<<bit);
    printf("%d",status);

}