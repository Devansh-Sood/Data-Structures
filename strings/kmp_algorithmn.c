/* ---------------------- KMP Algorithmn ---------------------*/
#include <stdio.h>

int main()
{
    char txt[50];
    char ch[50];
    int lps[50];
    int i=1,j=0;
    scanf("%s",txt);
    scanf("%s",ch);
    int l=strlen(ch);
    int l1=strlen(txt);
    lps[0]=0;
    while(i<l)
    {
        if(ch[j] == ch[i])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    i=0;
    j=0;
    while(i<l1 && j<l)
    {
        if(txt[i] == ch[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
     if(j == l)
        {
            printf("Present");
        }
        else
        {
            printf("Not");
        }
    return 0;
}
