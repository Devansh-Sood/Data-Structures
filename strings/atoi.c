#include <stdio.h>

void aatoi(char ch[])
{
    int i=0,s=1,base=0;
    while(ch[i]==' ')
    {
        i++;
    }
    if(ch[i]=='-')
    {
        s=-1;
        i++;
    }
    while(ch[i]>='0' && ch[i]<='9')
    {
       
        base=base*10 + (ch[i] - '0');
        i++;
    }
    printf("%d",base*s);
}

int main()
{
    char ch[50];
    scanf("%s",ch);
    aatoi(ch);
    return 0;
}
