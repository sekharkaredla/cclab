%{
#include<stdio.h>
%}
%%
[^a-zA-Z] {}
[a-z] {printf("%c",(char)(yytext[0]-32));}
[A-Z] {printf("%c",(char)(yytext[0]+32));}
%%
int main()
{
yylex();
}
