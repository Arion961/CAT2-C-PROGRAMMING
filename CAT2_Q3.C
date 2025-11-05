#include <stdio.h>
#include <stdlib.h> // Required for exit()

// Function Prototypes
void writeinputfile();
void processandwriteoutput();
void displayfiles();

int main() {
    printf("--- C File Processing Program ---\n\n");

    // 1. Create the input file
    writeinputfile();

    // 2. Read, process, and write the output file
    processandwriteoutput();

    // 3. Display the contents of both files
    displayfiles();

    printf("\nProgram finished successfully.\n");
    return 0;
}

// --- 1. Function to prompt user and store integers in 'input.txt' ---
void writeinputfile() {
    FILE fileptr;
    int number;
    int i;
    const int COUNT = 10;
    const char INPUTFILE = "input.txt";

    // Open the file for writing ("w"). If it exists, it's overwritten.
    fileptr = fopen(INPUTFILE, "w");

    // Error Handling: Check if file was opened successfully
    if (fileptr == NULL) {
        perror("Error opening input.txt for writing");
        // Exit the program since subsequent steps depend on this file
        exit(EXITFAILURE); 
    }

    printf("1. Entering %d integers into '%s':\n", COUNT, INPUTFILE);

    for (i = 0; i < COUNT; i++) {
        printf("Enter integer #%d: ", i + 1);
        // Ensure that a valid integer is read
        if (scanf("%d", &number) != 1) {
            printf("Invalid input detected. Using 0 instead.\n");
            number = 0;
            // Clear the input buffer after a failed read
            while (getchar() != '\n');
        }

        // Write the integer followed by a newline character to the file
        fprintf(fileptr, "%d\n", number);
    }

    // Always close the file stream after writing
    fclose(fileptr);
    printf("Successfully wrote %d integers to '%s'.\n\n", COUNT, INPUTFILE);
}

// --- 2. Function to read, process, and write results to 'output.txt' ---
void processandwriteoutput() {
    FILE inputfp, outputfp;
    int number;
    long long sum = 0; // Use long long for sum to prevent potential overflow
    int count = 0;
    double average;
    const char INPUTFILE = "input.txt";
    const char OUTPUTFILE = "output.txt";

    printf("2. Reading from '%s' and writing results to '%s':\n", INPUTFILE, OUTPUTFILE);

    // Open input file for reading ("r")
    inputfp = fopen(INPUTFILE, "r");
    if (inputfp == NULL) {
        perror("Error opening input.txt for reading");
        // Exit, as we cannot proceed without the input file
        exit(EXITFAILURE); 
    }

    // Read integers from the file until End-Of-File (EOF)
    while (fscanf(inputfp, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    // Close the input file
    fclose(inputfp);

    // Open output file for writing ("w")
    outputfp = fopen(OUTPUTFILE, "w");
    if (outputfp == NULL) {
        perror("Error opening output.txt for writing");
        exit(EXITFAILURE);
    }

    // Calculate average and write results
    if (count > 0) {
        average = (double)sum / count;

        // Write results to output.txt in a formatted way
        fprintf(outputfp, "Total Numbers Processed: %d\n", count);
        fprintf(outputfp, "Sum of Integers: %lld\n", sum);
        fprintf(outputfp, "Average of Integers: %.2f\n", average);
        printf("Calculation complete. Sum: %lld, Average: %.2f\n", sum, average);
    } else {
        fprintf(outputfp, "Error: No integers were read from the input file.\n");
        printf("Error: Input file was empty or contained no valid integers.\n");
    }

    // Close the output file
    fclose(outputfp);
    printf("Successfully wrote results to '%s'.\n\n", OUTPUTFILE);
}

// --- 3. Function to read and display contents of both files ---
void displayfiles() {
    FILE fileptr;
    char line[256]; // Buffer to read one line at a time
    const char FILES[] = {"input.txt", "output.txt"};
    int i;

    printf("3. Displaying file contents:\n");

    for (i = 0; i < 2; i++) {
        const char *filename = FILES[i];

        fileptr = fopen(filename, "r");

        // Error Handling: Check if file exists/can be opened
        if (fileptr == NULL) {
            fprintf(stderr, "Could not open %s for display (File not found or permission issue).\n", filename);
            continue; // Skip to the next file
        }

        printf("==========================================\n");
        printf("Contents of %s:\n", filename);
        printf("------------------------------------------\n");

        // Read and print file contents line by line
        while (fgets(line, sizeof(line), fileptr) != NULL) {
            printf("%s", line);
        }

        printf("==========================================\n\n");

        fclose(file_ptr);
    }
}
