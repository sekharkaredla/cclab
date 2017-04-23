%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
a {return A;}
b {return B;}
[c-zC-Z]+ {return C;}
\n {return NL;}
. {return yytext[0];}
%%
