%{
        #include<stdio.h>
        int c=0,m=0;
%}
%%
[/][/]([a-zA-Z0-9]*|[\t]?)+  {c++;}
[/][*]([a-zA-Z0-9 ]*|[\n]?|[\t]?)+[*][/] {m++;}
%%
int main(int argc,char *argv[])
{
        yyin = fopen(argv[1],"r");
        yyout = fopen(argv[2],"w");
        yylex();
        printf("Number of single line comments %d\n",c);
        printf("Number of multiline coments %d\n",m);
}
int yywrap()
{
return 1;
}
