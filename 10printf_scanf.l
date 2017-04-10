%{
	#include<stdio.h>
	#include<string.h>
	FILE *out;
	char line[50];
	int count=0;
%}

%%
	
"printf" yytext="writef";
"scanf" yytext="readf";
['\n'] { fprintf(out,"%s\n",line);}
(.*) {strcpy(line,yytext);}

%%

int yywrap()
{
	return 1;
}
int main()
{
	yyin=fopen("in.txt","r");
	out=fopen("psout.txt","w");
	yylex();
}

