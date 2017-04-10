#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(int argc,char *argv[])
{
bool isKeyword(char *,char *[]);
char *keyw[32]={"auto","double","int",	"struct","break","else","long",	"switch","case","enum",	"register","typedef","char","extern","return","union","const",	"float","short","unsigned","continue","for","signed","void","default","goto","sizeof","volatile","do","if","static","while"};
FILE *fp=fopen(argv[1],"r");
int i=0;
char c;int linenumber;linenumber=0;
int keyws,iden;
keyws=iden=0;
char buf[100];
while((c=fgetc(fp))!=EOF)
{
	//printf("%c hi :\n",c);
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
	{
	printf("operator %c line number : %d\n",c,linenumber);
	}
	if(c!=' '&&c!='\n'&&c!='\r'&&c!=';'&&c!='(')
	{
	buf[i++]=c;
	}
	else
	{
	if(c=='\n')
	linenumber++;
	buf[i]='\0';
	//printf("hi : %s\n",buf);
	if(isKeyword(buf,keyw))
	{
	keyws++;
	printf("keyword :%s  line number :%d\n",buf,linenumber);
	}
	//else if(strcmp(buf,""))
	else
	{
	iden++;
	printf("identifier :%s line number :%d\n",buf,linenumber);
	}
	i=0;
	}
}
printf("keywords are : %d\n",keyws);
printf("identifiers are : %d\n",iden);
}
bool isKeyword(char *s,char *keyw[])
{
int flag=0;
int k;
for(k=0;k<32;k++)
{
	if(!strcmp(keyw[k],s))
	{
	flag=1;
	break;
	}
}
if(flag)
return true;
else
return false;
}
