%{
    #include<stdio.h>
    #include "y.tab.h"
%}


%%
"a" {return ta;}
"b" {return tb;}
"c" {return tc;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap()
{
return 1;
}

