%{
#include<stdio.h>
#include<string.h>
%}

%%
[^0-9\n]* printf("error");
[+-]?[0] printf("decimal");
[-+]?[1-9][0-9]* printf("decimal");
[-+]?[0][0-7]+ printf("octal");
[-+]?[0][xX][a-fA-F]+ printf("hexadecimal");
[-+]?[0]?[xX]?[a-zA-Z]* printf("error");
%%

int yywrap()
{
return 1;
}
int main()
{
yylex();
}
