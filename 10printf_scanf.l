%{
#include<stdio.h>
int pfc=0, sfc=0;
%}

%%
"printf" {fprintf(yyout,"writef"); pfc++;}
"scanf" {fprintf(yyout,"readf"); sfc++;}
%%

main(int argc, char *argv[])
{

yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
printf("\n the number of printf lines = %d\n",pfc);
printf("\n the number of scanf lines = %d\n",sfc);
}

int yywrap()
{
return 1;
}
