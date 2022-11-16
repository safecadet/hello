%{
    #include<stdio.h>
    #include "y.tab.h"
%}


%%
"da"|"bda"|"bdc"|"dc" {return A;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap()
{
return 1;
}

