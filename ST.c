#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void main()
{
    void *p;
    char b[15],c;
    printf("Expression terminated by $:");
    scanf("%[^\n]s", &b);
    
    printf("\n Symbol Table\n");
    printf("Symbol \t addr \t type");
    for (int i = 0; i <= strlen(b); i++)
    {
        c=b[i];
        if(isalpha(c))
        {
            p=malloc(c);
            printf("\n%c \t %d \t Identifier\n",c,p);
        }
        else
        {
            if(c=='+'||c=='-'||c=='*'||c=='='||c=='/')
            {
                p=malloc(c);
                printf("\n %c \t %d \t Operator\n",c,p);
            }
        }
    }
}
