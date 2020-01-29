#include <stdio.h>

int main()
{
    int i=1,f=0,c=0,j=0;
    char ch[50];
    int lps[50];
    scanf("%s",ch);
    f=strlen(ch);
    lps[0]=0;
    while(i<f)
    {
        if(ch[i] == ch[j])
        {
          
            lps[i]=j+1;
              j++;
            i++;
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
    
    for(j=0;j<i;j++)
    {
        printf("%d ",lps[j]);
    }
    return 0;
}
