%{
#include<stdio.h>
#include<string.h>
FILE *out;
char line[50];
int count=0;
%}

%%

"/*"[-_a-zA-Z \n]+"*/"  {count++;}
"//"[^\n]+"\n"          {count++;}
['\n'] { fprintf(out,"%s\n",line);}
(.*) {strcpy(line,yytext);}

%%

int yywrap()
{
printf("5 comments\n");
return 1;
}

int main()
{
yyin=fopen("in.txt","r");
out=fopen("cout.txt","w");
yylex();
}

