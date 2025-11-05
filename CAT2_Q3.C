/*MARION MWIKALI MUTISYA 
CT100/G/26273/25
C FILE
*/

#include <stdio.h>
#include <stdlib.h> // Required for exit()

// Function Prototypes
void writeinputfile();
void processandwriteoutput();
void displayfiles();

int main() {
    printf("--- C File Processing Program ---\n\n");

    writeinputfile();
    processandwriteoutput();
    displayfiles();

    printf("\nProgram finished successfully.\n");
    return 0;
}

// --- 1. Create input file and store integers ---
void writeinputfile() {
    FILE *fileptr;
    int number;
    int i;
    const int COUNT = 10;
    const char *INPUTFILE = "input.txt";

    fileptr = fopen(INPUTFILE, "w");

    if (fileptr == NULL) {
        perror("Error opening input.txt for writing");
        exit(EXIT_FAILURE);
    }

    printf("1. Enter %d integers:\n", COUNT);

    for (i = 0; i < COUNT; i++) {
        printf("Enter integer #%d: ", i + 1);
        if (scanf("%d", &number) != 1) {
            printf("Invalid input! Using 0 instead.\n");
            number = 0;
            while (getchar() != '\n');
        }
        fprintf(fileptr, "%d\n", number);
    }

    fclose(fileptr);
    printf("Successfully wrote to '%s'.\n\n", INPUTFILE);
}

// --- 2. Process input and write results to output ---
void processandwriteoutput() {
    FILE *inputfp, *outputfp;
    int number;
    long long sum = 0;
    int count = 0;
    double average;
    const char *INPUTFILE = "input.txt";
    const char *OUTPUTFILE = "output.txt";

    inputfp = fopen(INPUTFILE, "r");
    if (inputfp == NULL) {
        perror("Error opening input.txt for reading");
        exit(EXIT_FAILURE);
    }

    while (fscanf(inputfp, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    fclose(inputfp);

    outputfp = fopen(OUTPUTFILE, "w");
    if (outputfp == NULL) {
        perror("Error opening output.txt for writing");
        exit(EXIT_FAILURE);
    }

    if (count > 0) {
        average = (double)sum / count;
        fprintf(outputfp, "Total Numbers Processed: %d\n", count);
        fprintf(outputfp, "Sum of Integers: %lld\n", sum);
        fprintf(outputfp, "Average of Integers: %.2f\n", average);
    } else {
        fprintf(outputfp, "Error: No integers found in input file.\n");
    }

    fclose(outputfp);
    printf("Successfully wrote results to '%s'.\n\n", OUTPUTFILE);
}

// --- 3. Display contents of both files ---
void displayfiles() {
    FILE *fileptr;
    char line[256];
    const char *FILES[] = {"input.txt", "output.txt"};
    int i;

    printf("3. Displaying file contents:\n");

    for (i = 0; i < 2; i++) {
        fileptr = fopen(FILES[i], "r");

        if (fileptr == NULL) {
            printf("Could not open %s\n", FILES[i]);
            continue;
        }

        printf("==========================================\n");
        printf("Contents of %s:\n", FILES[i]);
        printf("------------------------------------------\n");

        while (fgets(line, sizeof(line), fileptr)) {
            printf("%s", line);
        }

        printf("==========================================\n\n");
        fclose(fileptr);
    }
}
