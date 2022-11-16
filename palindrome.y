%{
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   void yyerror(char *);
   int flag, k, i;
%}

%union {char *string;}
%start lines
%token newline
%token <string> STR 
%type <string> E S

%%
lines:  
    |    lines S newline     {;}
    ;
S:E
{
	flag = 0;
	k = strlen($1);
	if(k%2==0 || $1[k/2] != 'c' || (k == 1 && $1[0]=='c'))
	{
		printf("Invalid String\n");
	}
	else
	{
		k--;
		for (i = 0; i < k/2; i++)
		{
		    if ($1[i] == $1[k-i])
			{} 
		    else
			{
		        flag = 1;
		    }
		}
		if (flag == 1) printf("Not palindrome\n");
		else printf("palindrome\n");
		//printf("%s\n", $1);
	}
	printf("Enter the string to be checked : ");
};

E:STR {$$ = $1;};
%%

int main() 
{
	printf("Enter the string to be checked : ");
	return yyparse();
}

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
    exit(1);
}
