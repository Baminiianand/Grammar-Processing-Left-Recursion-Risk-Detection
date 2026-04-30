#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n, i;

    printf("Enter number of grammar rules: ");
    scanf("%d", &n);
    getchar(); // clear newline

    char grammar[MAX][MAX];

    // Input grammar rules
    for(i = 0; i < n; i++) {
        printf("Enter rule %d: ", i + 1);
        fgets(grammar[i], MAX, stdin);
        grammar[i][strcspn(grammar[i], "\n")] = 0; // remove newline
    }

    printf("\n--- Output ---\n");

    for(i = 0; i < n; i++) {
        char lhs;
        char rhs[MAX];
        int depth = 0;
        int flag = 0;

        // Get LHS (first character)
        lhs = grammar[i][0];

        // Find RHS after "->"
        char *arrow = strstr(grammar[i], "->");
        if (arrow != NULL) {
            strcpy(rhs, arrow + 2); // take everything after ->
        } else {
            printf("Invalid rule: %s\n", grammar[i]);
            continue;
        }

        // Skip leading spaces in RHS
        int k = 0;
        while(rhs[k] == ' ') {
            k++;
        }

        // Check left recursion
        if(rhs[k] == lhs) {
            flag = 1;
        }

        // Calculate recursion depth
        int j;
for(j = 0; j < strlen(rhs); j++) {
    if(rhs[j] == lhs) {
        depth++;
    }
}

        // Print output
        printf("Rule: %s\n", grammar[i]);
        printf("Recursion_Depth = %d\n", depth);
        printf("Has_Left_Recursion = %d\n\n", flag);
    }

    return 0;
}
