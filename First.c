#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_nt 10
#define MAX_p 10
#define MAX_s 10

int isnt(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

void calculateFirst(char nt, char production[][MAX_s], int productionCount, int first[]) {
    int i;
    for (i = 0; i < productionCount; i++) {
        if (production[i][0] == nt) {
            if (!isnt(production[i][3])) {
                first[nt - 'A'] |= 1 << (production[i][3] - 'a');
            } 
            else {
                if (nt != production[i][3]) {
                    calculateFirst(production[i][3], production, productionCount, first);
                }
                first[nt - 'A'] |= first[production[i][3] - 'A'];
            }
        }
    }
}

int main() {
    int i, j, ntCount, productionCount;
    char nt[MAX_nt], p[MAX_p][MAX_s];
    int first[MAX_nt];

    printf("Enter the number of nt: ");
    scanf("%d", &ntCount);

    printf("Enter the nt (uppercase letters): ");
    for (i = 0; i < ntCount; i++) {
        scanf(" %c", &nt[i]);
        first[i] = 0;
    }

    printf("Enter the number of p: ");
    scanf("%d", &productionCount);

    printf("Enter the p (in the form A->...): ");
    for (i = 0; i < productionCount; i++) {
        scanf(" %[^\n]s", p[i]);
    }

    for (i = 0; i < ntCount; i++) {
        calculateFirst(nt[i], p, productionCount, first);
    }

    printf("\nFIRST sets:\n");
    for (i = 0; i < ntCount; i++) {
        printf("FIRST(%c) = { ", nt[i]);
        for (j = 0; j < 26; j++) {
            if (first[i] & (1 << j)) {
                printf("%c ", 'a' + j);
            }
        }
        printf("}\n");
    }

    return 0;
}
