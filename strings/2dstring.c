/*--------------Naive or basic algorithmn----------Takes :- O(mn)time----------*/

#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,k=0,a,b,c;
	char str[50],st[50][50];
	gets(str);
	a=strlen(str);
	for(i=0;i<a;i++)
	{
		if(str[i]==' ')
		{
			st[k][j]='\0';
			k++;
			j=0;
		}
		else
		{
			st[k][j]=str[i];
			j++;
		}
	}
//	st[k][j]='\0';
	for(i=0;i<=k;i++)
	{
		printf("%s\n",st[i]);
	}
	printf("The reverse is :\n");
	for(i=0;i<=k;i++)
	{
		b=strlen(st[i]);
		for(c=b;c>=0;c--)
		{
			printf("%c",st[i][c]);
		}
	}
	return 0;
}
