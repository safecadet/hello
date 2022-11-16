%{
	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
	#include "y.tab.h"
%}

%%
[a-c]+		{yylval.string = yytext; return STR;}
\n              {return newline;}
[ \t]		    ;
.			    {ECHO; yyerror("Unexpected Character");}
%%

int yywrap()
{
	return 1;
}
