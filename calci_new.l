%{
#include<stdio.h>
#include "y.tab.h"
extern yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext);return NUM;}
[+] {return '+';}
[-] {return '-';}
[*] {return '*';}
[/] {return '/';}
[\^] {return '^';}
"sqrt" {return sqroot;}
[\n]|. {return yytext[0];}
