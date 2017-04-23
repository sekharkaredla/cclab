%{
#include<stdio.h>
#include<math.h>
%}
%token NUM
%token sqroot
%left '+' '-'
%left '*' '/' '^'
%%
str:exp {printf("%d",$$);}  
exp:exp '+' exp {$$=$1+$3;}
|exp '-' exp {$$=$1-$3;}
|exp '*' exp {$$=$1*$3;}
|exp '/' exp {if($3==0)
				yyerror("divide by zero");
				else
				$$=$1/$3;
				}
|'('exp')'{$$=$2;}
|sqroot'('exp')' {$$=sqrt($3);}
|NUM {$$=$1;}
;
%%
int yyerror(char *s)
{
	printf("%s",s);
}
int main()
{
	yyparse();
}