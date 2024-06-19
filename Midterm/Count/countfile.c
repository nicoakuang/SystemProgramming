#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to evaluate arithmetic expressions in math
int evaluate(char *expression) {
    int operand1, operand2;
    char operator;

    // Read the operands and operator from the expression
    if (sscanf(expression, "%d %c %d", &operand1, &operator, &operand2) != 3) {
        fprintf(stderr, "Error: Invalid expression format: %s\n", expression);
        return 0; // Error code
    }

    // give this program to do addition
    if (operator == '+') {
        return operand1 + operand2;
    }
    // give this program to do subtraction
    else if (operator == '-') {
        return operand1 - operand2;
    }
    // Display error message if the operator is not work well
    else {
        fprintf(stderr, "Error: operator: %c\n", operator);
        return 0; // Error code
    }

}

// Function to read the Nico program file and evaluate each line
void interpret(FILE *file) {
    char line[100]; // give Maximum size of one program line
    int result;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if present
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        // Evaluate and print the result
        result = evaluate(line);
        printf("Result: %d\n", result);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.nico>\n", argv[0]);
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
