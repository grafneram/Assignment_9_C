// Ashley Grafner
// Original Date: 9/17/2024, Updated: 11/4/2024
// Question 2

// Updated the A4 ex1 question to now have command line arguments
// Updated to also include function pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double calculator(char operation, double numbers[], int count);
double factorial(int n);
double power(double base, int exp);

// Main method with command line args
int main(int argc, char *argv[]) {
    // Check if there are enough arguments
    if (argc < 2) {
        printf("Usage: <command> [args...]\n");
        return 1;
    }

    // Command handling
    if (strcmp(argv[1], "calc") == 0) {
        // Ensure there are enough arguments for the calculator task
        if (argc < 5) {
            printf("Usage: calc <operation> <num1> <num2> ...\n");
            return 1;
        }

        char operation = argv[2][0];  // Get the first character of the operation
        int count = argc - 3;          // Calculate how many numbers were provided
        double numbers[count];          // Array to hold the numbers

        // Parse numbers from command-line arguments and convert them to double
        for (int i = 0; i < count; i++) {
            numbers[i] = atof(argv[i + 3]); // Convert string to double
        }

        // Handle factorial separately since it takes only one argument
        if (operation == '!') {
            if (count != 1) {
                printf("Factorial operation requires exactly one argument.\n");
                return 1;
            }
            int n = (int)numbers[0];
            double result = factorial(n);
            printf("Result: %.2lf\n", result);
        }
        // Handle power operation separately since it takes two arguments
        else if (operation == '^') {
            if (count != 2) {
                printf("Power operation requires exactly two arguments.\n");
                return 1;
            }
            double result = power(numbers[0], (int)numbers[1]);
            printf("Result: %.2lf\n", result);
        }
        // Handle addition, subtraction, multiplication, and division
        else if (operation == '+' || operation == '-' || operation == 'm' || operation == '/') {
            double result = calculator(operation, numbers, count); // Pass count to calculator
            printf("Result: %.2lf\n", result);
        } else {
            printf("Invalid operation.\n");
            return 1; // Exit if the operation is invalid
        }
    } else {
        printf("Invalid command.\n");
        return 1; // Exit if the command is invalid
    }

    return 0; // Successful execution
}

// Function Definitions

// Function to calculate the factorial of a number
double factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial of a negative number is undefined.\n");
        return -1; // Indicate an error
    }
    if (n == 0 || n == 1) return 1;
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate power
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < abs(exp); i++) {
        result *= base;
    }
    if (exp < 0) {
        return 1.0 / result; // Handle negative exponents
    }
    return result;
}

// Calculator function that performs the specified operation on an array of numbers
double calculator(char operation, double numbers[], int count) {
    double result = numbers[0]; // Initialize result with the first number

    switch (operation) {
        case '+': // Addition
            for (int i = 1; i < count; i++)
                result += numbers[i]; // Accumulate sum
            break;
        case '-': // Subtraction
            for (int i = 1; i < count; i++)
                result -= numbers[i]; // Subtract each number
            break;
        case 'm': // Multiplication
            for (int i = 1; i < count; i++)
                result *= numbers[i]; // Multiply each number
            break;
        case '/': // Division
            for (int i = 1; i < count; i++) {
                if (numbers[i] != 0) { // Check for division by zero
                    result /= numbers[i]; // Divide by each number
                } else {
                    printf("Error: Division by zero.\n");
                    return 0; // Exit on division by zero
                }
            }
            break;
        default: // Invalid operation
            printf("Invalid operation.\n");
            return 0; // Exit on invalid operation
    }

    return result; // Return the result of the operation
}
