%{
#include<stdio.h>
int vd;
%}
%union
{
        char dval;
}
%token <dval> A
%token <dval> B
%%
str:s'\n' { vd=1; return 0;}
s:A s B   ;
 |  ;
%%
int main()
{
        printf("enter the string\n");
        yyparse();
        if(vd==1)
        printf(" valid");
        else
        printf(" not valid");
}
yyerror(char *s)
{
        printf("%s",s);
}
