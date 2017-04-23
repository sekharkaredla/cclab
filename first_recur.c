#include<stdio.h>
#include<ctype.h>
#include<string.h>
int n;
char prods[10][10];
void first(int i)
{
int count=0;
int j;
for(j=0;prods[i][j]!='\0';j++)
{
	if(j==3||prods[i][j]=='|')
	{
		if(prods[i][j]=='|')
		j++;
		if(islower(prods[i][j]))
		printf("%c",prods[i][j]);
		else
		{
			int k;
			for(k=0;k<n;k++)
			{
			if(prods[k][0]==prods[i][j])
			first(k);
			}		
		}
	}
}
}
int main()
{
printf("number of productions :");
scanf("%d",&n);
int i;
printf("enter the grammar:");
for(i=0;i<n;i++)
{
scanf("%s",prods[i]);
}
for(i=0;i<n;i++)
{
	printf("first of %c is :",prods[i][0]);
	first(i);
	printf("\n");
}
return 1;
}
