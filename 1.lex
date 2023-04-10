%{
#include<stdio.h>
#include<string.h>
int i = 0;
%}

/* Rules Section*/
%%
([0-9a-zA-Z])* {i++;} /* Rule for counting number of words*/

"\n" {
         printf("%d\n", i); 
         i = 0;
        }
%%

int yywrap(void){}

int main()
{
	yylex();
	return 0;
}
