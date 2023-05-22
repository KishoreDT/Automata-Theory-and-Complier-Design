#include <stdio.h>
#include <string.h>

#define STACK_SIZE 100

int top = -1;
char stack[STACK_SIZE];

void push(char c) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = c;
    }
}

char pop() {
    char c;
    if (top < 0) {
        printf("Stack underflow!\n");
        return '\0';
    } else {
        c = stack[top];
        top--;
        return c;
    }
}

int main() {
    char input[STACK_SIZE];
    int i, n, m;
    int state = 0;
    printf("Enter a string of the form 0^n 1^m 0^n: ");
    scanf("%s", input);
    n = strlen(input);
    m = 0;
    for (i = 0; i < n; i++) {
        if (state == 0) {
            if (input[i] == '0') {
                push('0');
            } else if (input[i] == '1') {
                state = 1;
                m++;
            } else {
                printf("Invalid input!\n");
                return 0;
            }
        } else if (state == 1) {
            if (input[i] == '1') {
                m++;
            } else if (input[i] == '0') {
                state = 2;
                pop();
            } else {
                printf("Invalid input!\n");
                return 0;
            }
        } else if (state == 2) {
            if (input[i] == '0') {
                pop();
            } else {
                printf("String is not of the form 0^n 1^m 0^n\n");
                return 0;
            }
        }
    }
    if (top == -1 && m > 0) {
        printf("String is of the form 0^n 1^m 0^n\n");
    } else {
        printf("String is not of the form 0^n 1^m 0^n\n");
    }
    return 0;
}
