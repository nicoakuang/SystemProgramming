#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char *stack[MAX_STACK_SIZE];
int stack_top = -1;

// Function to push a string onto the stack
void push(char *str) {
    if (stack_top < MAX_STACK_SIZE - 1) {
        stack[++stack_top] = strdup(str); // Allocate and copy the string
    }
}

// Function to pop a string from the stack
char *pop() {
    if (stack_top >= 0) {
        return stack[stack_top--];
    } else {
        return NULL;
    }
}

// Function to evaluate expressions
void evaluate(char *expression) {
    char operator[10];
    char operand[200]; // Increased size for operand to accommodate longer strings

    // Read the operator and operand from the expression
    if (sscanf(expression, "%s \"%[^\"]\"", operator, operand) < 1) {
        fprintf(stderr, "Error: Invalid expression format: %s\n", expression);
        return;
    }

    // Perform operations based on the operator
    if (strcmp(operator, "PUSH") == 0) {
        push(operand);
    } else if (strcmp(operator, "CONCAT") == 0) {
        char *str1 = pop();
        char *str2 = pop();
        if (str1 && str2) {
            // Allocate memory for concatenated string
            char *concat_str = malloc(strlen(str1) + strlen(str2) + 1);
            if (!concat_str) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                free(str1);
                free(str2);
                return;
            }
            
            // Concatenate strings and push result back to stack
            strcpy(concat_str, str2);
            strcat(concat_str, str1);
            push(concat_str);

            // Free temporary strings
            free(str1);
            free(str2);
        } else {
            fprintf(stderr, "Error: Not enough elements on stack for CONCAT\n");
            if (str1) free(str1);
            if (str2) free(str2);
        }
    } else if (strcmp(operator, "PRINT") == 0) {
        char *str = pop();
        if (str) {
            printf("%s\n", str);
            free(str);
        } else {
            
        }
    } else if (strcmp(operator, "LEN") == 0) {
        char *str = pop();
        if (str) {
            int length = strlen(str);
            printf("%d\n", length);
            free(str);
        } else {
            fprintf(stderr, "Error: Stack underflow on LEN\n");
        }
    } else {
        fprintf(stderr, "Error: Unsupported operator: %s\n", operator);
    }
}

// Function to read the program file and evaluate each line
void interpret(FILE *file) {
    char line[200]; // Maximum size of one program line

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if present
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        // Evaluate the expression
        evaluate(line);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string.nico>\n", argv[0]);
        return 1; // Error code
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", argv[1]);
        return 1; // Error code
    }

    interpret(file);
    fclose(file);

    return 0; // Program completed successfully
}
