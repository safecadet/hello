%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token A NL

%%
stmt: S NL { printf("Valid string\n");
			exit(0); }
;
S: A S |
;
%%

int yyerror(char *msg)
{
printf("Invalid string\n");
exit(0);
}

main()
{
printf("Enter the string : ");
yyparse();
}

