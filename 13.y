%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token ta tb tc NL

%%
stmt: S NL { printf("Valid string\n");
			exit(0); }
;
S: tc A | tc tc B
A: tc A | ta
B: tc tc B | tb
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

