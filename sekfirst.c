#include<stdio.h>
#include<ctype.h>
#include<string.h>
char first[10][10];
char prods[10][10];
int main()
{
int n;
printf("number of productions :");
scanf("%d",&n);
int i,j;
for(i=0;i<n;i++)
{
scanf("%s",prods[i]);
}
while(i>=0)
{
	int count=3;
	first[i][0]=prods[i][0];
	first[i][1]=prods[i][1];
	first[i][2]=prods[i][2];
	first[i][count]=prods[i][count];count++;
	for(j=count;prods[i][j]!='\0';j++)
	{
		if(prods[i][j]=='|')
		{
			first[i][count++]=prods[i][j+1];
		}
	}
i--;
}
for(i=0;i<n;i++)
{
	printf("%s\n",first[i]);
}
for(i=0;i<n;i++)
{
printf("first of %c is : ",first[i][0]);
for(j=3;first[i][j]!='\0';j++)
{
//	printf("%c",first[i][j]);
	if(islower(first[i][j]))
	printf("%c",first[i][j]);
	else
	{
		int k;
		for(k=0;k<n;k++)
		{
			if(first[k][0]==first[i][j])
			printf("%c",first[k][3]);
		}
	}
}
printf("\n");
}
return 1;
}
