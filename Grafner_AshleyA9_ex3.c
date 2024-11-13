// Ashley Grafner
// This code was changed on 10/29/2024 to output tables to files C_to_F.txt and F_to_C.txt
//This code was changed again on 11/4/2024 to use command args and file pointers

// Project will:
// converts temperatures between Fahrenheit and Celsius, outputs tables to separate files, and uses functions for modular design.

#include <stdio.h>
#include <stdlib.h>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(int celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to create a Fahrenheit to Celsius conversion table and save it to "F_to_C.txt"
void writeFahrenheitToCelsiusTable(int maxFahrenheit, int step) {
    FILE *file = fopen("F_to_C.txt", "w");
    if (file == NULL) {
        printf("Error opening F_to_C.txt for writing.\n");
        return;
    }

    fprintf(file, "_____________________________________________\n");
    fprintf(file, "| degree Fahrenheit | degree Celsius      |\n");
    fprintf(file, "_____________________________________________\n");

    for (int i = 0; i <= maxFahrenheit; i += step) {
        double celsius = fahrenheitToCelsius(i);
        fprintf(file, "| %-18d | %-19.2f |\n", i, celsius);
        fprintf(file, "_____________________________________________\n");
    }

    fclose(file);
}

// Function to create a Celsius to Fahrenheit conversion table and save it to "C_to_F.txt"
void writeCelsiusToFahrenheitTable(int maxCelsius, int step) {
    FILE *file = fopen("C_to_F.txt", "w");
    if (file == NULL) {
        printf("Error opening C_to_F.txt for writing.\n");
        return;
    }

    fprintf(file, "_____________________________________________\n");
    fprintf(file, "| degree Celsius    | degree Fahrenheit   |\n");
    fprintf(file, "_____________________________________________\n");

    for (int i = 0; i <= maxCelsius; i += step) {
        double fahrenheit = celsiusToFahrenheit(i);
        fprintf(file, "| %-18d | %-19.2f |\n", i, fahrenheit);
        fprintf(file, "_____________________________________________\n");
    }

    fclose(file);
}

// Main function - reads command line arguments, calls functions to write conversion tables to files
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <maxFahrenheit> <maxCelsius> <stepFahrenheit> <stepCelsius>\n", argv[0]);
        return 1; // Exit with an error code if the number of arguments is incorrect
    }

    // Parse command line arguments
    int maxFahrenheit = atoi(argv[1]);
    int maxCelsius = atoi(argv[2]);
    int stepFahrenheit = atoi(argv[3]);
    int stepCelsius = atoi(argv[4]);

    // Function pointers for the conversion table functions
    void (*writeFtoC)(int, int) = writeFahrenheitToCelsiusTable; // Function pointer for F to C table
    void (*writeCtoF)(int, int) = writeCelsiusToFahrenheitTable; // Function pointer for C to F table

    // Call the function pointers to write the conversion tables
    writeFtoC(maxFahrenheit, stepFahrenheit); // Using function pointer to call F to C table function
    writeCtoF(maxCelsius, stepCelsius);       // Using function pointer to call C to F table function

    // Inform the user that the tables have been written to files
    printf("Conversion tables written to F_to_C.txt and C_to_F.txt.\n");

    return 0; // program finished successfully
}
