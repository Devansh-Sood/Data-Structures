/*Minimum insertions to form a palindrome | DP-28
Given a string str, the task is to find the minimum number of characters to be inserted to convert it to palindrome.
Before we go further, let us understand with few examples:

ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd
abcda: Number of insertions required is 2 i.e. adcbcda which is same as number of insertions in the substring bcd(Why?).
abcde: Number of insertions required is 4 i.e. edcbabcde

*/



#include<stdio.h>
#include<string.h>
int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int main()
{
    char str[50];
    scanf("%s",str);
    int t[strlen(str)][strlen(str)];
    for(int i=0;i<strlen(str);i++)
    {
        t[i][i]=0;
    }
    for(int i=0;i<strlen(str)-1;i++)
    {
        if(str[i]==str[i+1])
        {
            t[i][i+1]=0;
        }
        else
        {
            t[i][i+1]=1;
        }
    }
    for(int i=2;i<strlen(str);i++)
    {
        for(int j=0;j<strlen(str)-i;j++)
        {
            if(str[j]==str[i+j])
            {
                t[j][i+j]=t[j+1][i+j-1];
            }
            else
            {
                t[j][i+j]=1+min(t[j][i+j-1],t[j+1][i+j]);
            }
        }
    }
    printf("%d",t[0][strlen(str)-1]);
    return 0;
}