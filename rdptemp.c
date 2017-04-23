/*
for the grammar
S->aA|B
A->Ba
B->b
*/


#include<stdio.h>
#include<string.h>
int i=0;
void S();
char a[10];
void A();
void B();
int main()
{
	while(1)
	{
	i=0;
	scanf("%s",a);
	if(strcmp(a,"bye"))
	{
		S();
		if(a[i]=='$')
		printf("success\n");
		else
		printf("failed\n");
	}
	else
	break;
	}
return 1;
}
void S()
{
	if(a[i]=='a')
	{
	i++;
	A();
	}
	else
	B();
}
void A()
{
	B();
	if(a[i]=='a')
	{
	i++;
	}
}
void B()
{
	if(a[i]=='b')
	i++;
}
