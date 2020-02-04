#include <stdio.h>

int main()
{
    int i,f=0,c=0,j;
    char ch[50],ch1[20];
    scanf("%s",ch);
    scanf("%s",ch1);
    int l=strlen(ch);
    int l1=strlen(ch1);
    for(i=0;i<l-l1;i++)
    {
        for(j=0;j<l1;j++)
        {
            if(ch[i+j] == ch1[j])
            c++;
            else
            break;
        }
        if(c==l1)
        f=1;
        c=0;
    }
    if(f==1)
    printf("Present");
    else
    printf("Not Present");
    return 0;
}
