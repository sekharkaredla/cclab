%{
#include<stdio.h>
%}
%token A B C NL
%%
stmt:s NL {printf("valid");return 1;}
;
s:A s B
|C;
%%
int main()
{
yyparse();
}
yyerror(char *s)
{
printf("invalid string");
}	
