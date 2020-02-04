#include <stdio.h>
#include<string.h>

int main()
{
    char ch[50];
    int i,l=0,m=0,j,q=0,w=0;
    scanf("%s",ch);
    l=strlen(ch);
    int a[l][l];
    for(i=0;i<l;i++)
    {
        a[i][i]=1;
    }
    for(i=0;i<(l-1);i++)
    {
        if(ch[i]==ch[i+1])
        {
            m=2;
            a[i][i+1]=1;
        }
        else
        a[i][i+1]=0;
    }
    for(i=2;i<l;i++)
    {
        for(j=0;j<l-i;j++)
        {
            if(ch[j]==ch[j+i] && a[j+1][j+i-1])
            {
                m=i+1;
                q=j;
                w=j+i;
                a[j][i+j]=1;
            }
            else
            a[j][i+j]=0;
        }
    }
    printf("%d",m);
    for(i=q;i<=w;i++)
    {
        printf("%c",ch[i]);
    }
    return 0;
}
