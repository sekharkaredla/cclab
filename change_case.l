%{
#include<stdio.h>
%}
%%
[a-z] {printf("%c",(char)(yytext[0]-32));}
[A-Z] {printf("%c",(char)(yytext[0]+32));}
%%
void main()
{
yylex();
}
