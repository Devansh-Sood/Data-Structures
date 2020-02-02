#include <stdio.h>
#include<string.h>

int cal(char c)
{
    if(c=='I')
    return 1;
    else if(c=='V')
    return 5;
    else if(c=='X')
    return 10;
    else if(c=='L')
    return 50;
    else if(c=='C')
    return 100;
    else if(c=='D')
    return 500;
    else if(c=='M')
    return 1000;
    else
    return -1;
}

int main()
{
    char ch[50];
    int i,l=0,s=0;
    scanf("%s",ch);
    l=strlen(ch);
    i=l-1;
    while(i>=0)
    {
        if(i==0)
        {
            s=s+cal(ch[i]);
            
            break;
        }
        if(cal(ch[i])>cal(ch[i-1]))
        {
          s=s+cal(ch[i])-cal(ch[i-1]);
          i=i-2;
        }
        else if(cal(ch[i])<=cal(ch[i-1]))
        {
          s=s+cal(ch[i]);
          i=i-1;
        }
       
    }
    printf("%d",s);
    return 0;
}
