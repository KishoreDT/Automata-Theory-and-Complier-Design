#include <stdio.h>
#include <string.h>

const int MAX_LEN = 100;
const int MAX_STATES = 10;

int main() {
    char input[MAX_LEN];
    printf("Q={0,1,2}");
    printf("\ninitial state is {0}");
    printf("\nFinal state is {2}");
    printf("\nsymbols={a,b}");
    printf("\n\nEnter a string: ");
    scanf("%s", input);

    int len = strlen(input);
    int end_ab = len >= 2 && input[len-2] == 'a' && input[len-1] == 'b';

    if (!end_ab) {
        int current_state = 0;
        for (int i = 0; i < len; i++) {
            if (input[i] == 'a') {
                current_state = 1;
            } else if (input[i] == 'b') {
                current_state = 2;
            } else {
                printf("Invalid input\n");
                return 0;
            }
        }

        if (current_state == 2) {
            printf("Reject\n");
        } else {
            printf("Accept\n");
        }
    } else {
        printf("Reject\n");
    }
    return 0;
}
