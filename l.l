%{
#include <stdio.h>
%}

%%

[a-zA-Z]          { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+          { printf("NUMBER: %s\n", yytext); }
[int|float|for|while|if|else|#include]          { printf("KEYWORD: %s\n", yytext); }
[stdio.h|stdlib.h]          { printf("HEADER: %s\n", yytext); }
[-+*/]          { printf("OPERATOR: %c\n", yytext[0]); }
[ \t\n]         ; /* Skip whitespace and newlines */
.               { printf("Invalid character: %c\n", yytext[0]); }

%%

int main()
{
    yylex();
    return 0;
}
