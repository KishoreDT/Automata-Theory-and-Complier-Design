#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum token_ty{CON,punc,iden,key,op};

void printf_token(const char* token,enum token_ty type){
    switch(type){
        case key:
            printf("Keyword: %s\n", token);
            break;
        case punc:
            printf("Punctuator: %s\n", token);
            break;
        case iden:
            printf("Identifier: %s\n", token);
            break;
        case CON:
            printf("Constant: %s\n", token);
            break;
        case op:
            printf("Operator: %s\n", token);
            break;
    }
}

int main(){
    char program[]= "int\n main\n \n(\n) \n+ \n34";
    char* token=strtok(program,"\n");
    while (token !=NULL){
        if(strcmp(token,"int")==0||strcmp(token,"main")==0){
            printf_token(token,key);
        }
        else if(isdigit(token[0])){
            printf_token(token,CON);
        }
        else if(isalpha(token[0])){
            printf_token(token,iden);
        }
        else if(token[0]=='+'||token[0]=='-'||token[0]=='*'||token[0]=='/'||token[0]=='='){
            printf_token(token,op);
        }
        else{
            printf_token(token,punc);
        }
         token = strtok(NULL, " \n");
    }
    return 0;
}