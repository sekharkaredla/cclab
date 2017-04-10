%{
	#include"y.tab.h"
%}

%%
[0-9]+ {yylval.dval=atoi(yytext);return digit;}
\n|. return yytext[0];
%%
