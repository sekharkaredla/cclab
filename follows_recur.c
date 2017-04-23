#include<stdio.h>
#include<ctype.h>
#include<string.h>
char prods[10][10];
char follows[10][10];
int n;
int get_index_prod(char s)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(prods[i][0]==s)
			return i;
	}
	return -1;
}
void main()
{
printf("enter the number of productions:");
scanf("%d",&n);
int i;
printf("enter the prods :");
for(i=0;i<n;i++)
{
	scanf("%s",prods[i]);
}
strcat(follows[0],"^");
for(i=0;i<n;i++)
{
	int j;
	for(j=0;j<n;j++)
	{
		int k;
		for(k=3;prods[j][k]!='\0';k++)
		{
			if(prods[j][k]==prods[i][0])
			{
			//	printf("hi1 %c",prods[j][k]);
				if(k==strlen(prods[j])-1||prods[j][k+1]=='|')
				{
			//		printf("hi2 %c",prods[j][k]);
					strcat(follows[i],follows[j]);
				}
				else if(islower(prods[j][k+1]))
				{
			//		printf("hi3 %c",prods[j][k]);
					// char temp[1];temp[0]=prods[j][k+1];
					// strcat(follows[i],temp);
					int len=strlen(follows[i]);
					follows[i][len]=prods[j][k+1];
			//		printf("hi4 %s",follows[i]);
				}
				// else
				// {
				// 	strcat(follows[i],first[j]);
				// }
			}
		}
	}
}
for(i=0;i<n;i++)
{
	int j;
	printf("%s\n",follows[i]);
}
}