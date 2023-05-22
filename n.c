#include <stdio.h>
#define max 100
int main() 
{
    char str[max],f='a';
    int i;
    printf("enter the string to be checked: ");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++) 
    {
        switch(f) 
        {
            case 'a': 
                if(str[i]=='1') f='b';
                break;
            case 'b': 
                if(str[i]=='0') f='a';
                else if(str[i]=='1') f='c';
                else if(str[i]=='0') f='c';
                break;
        }
    }
    if(f=='a')
    {
        printf("String is accepted", f);
    }
    else
    {
        printf("String is not accepted", f);
    }
    return 0;
}