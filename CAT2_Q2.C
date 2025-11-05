#include <stdio.h>
// Define constants for clarity and easy modification
#define STANDARDHOURS 40.0
#define OVERTIMEMULTIPLIER 1.5
#define TAXBRACKET1 600.00
#define TAXRATE1 0.15
#define TAXRATE2 0.20
/*
  @brief Calculates gross pay, taxes, and net pay based on hours worked and hourly wage.
 /
int main() {
    // Variable declarations
    double hoursworked = 0.0;
    double hourlywage = 0.0;
    double standardpay = 0.0;
    double overtimehours = 0.0;
    double overtimepay = 0.0;
    double grosspay = 0.0;
    double taxes = 0.0;
    double netpay = 0.0;
    // 1. Get user input
    printf("--- C Payroll Calculator ---\n");
    printf("Enter hours worked in a week: ");
    // Note: In C, we use & (address-of operator) to read the input into the variable
    if (scanf("%lf", &hoursworked) != 1) { 
        printf("Invalid input for hours worked.\n");
        return 1;
    }
    printf("Enter the hourly wage ($): ");
    if (scanf("%lf", &hourlywage) != 1) {
        printf("Invalid input for hourly wage.\n");
        return 1;
    }
    // --- 2. Gross Pay Calculation (Handling Overtime) ---
    if (hoursworked > STANDARDHOURS) {
        // Calculate standard pay for the first 40 hours
        standardpay = STANDARDHOURS  hourlywage;
        // Calculate overtime hours and pay
        overtimehours = hoursworked - STANDARDHOURS;
        overtimepay = overtimehours  hourlywage  OVERTIMEMULTIPLIER;
        grosspay = standardpay + overtimepay;
    } else {
        // No overtime
        grosspay = hoursworked  hourlywage;
    }
    // --- 3. Tax Calculation (Tiered Rate) ---
    if (grosspay > TAXBRACKET1) {
        // Tax on the first $600 at 15%
        double taxonfirstbracket = TAXBRACKET1  TAXRATE1;
        // Tax on the remainder at 20%
        double remainingincome = grosspay - TAXBRACKET1;
        double taxonrest = remainingincome  TAXRATE2;
        taxes = taxonfirstbracket + taxonrest;
    } else {
        // If $600 or less, tax the entire amount at 15%
        taxes = grosspay  TAXRATE1;
    }
    // --- 4. Net Pay Calculation ---
    netpay = grosspay - taxes;
    // --- 5. Print Results ---
    printf("\n--- Payroll Summary ---\n");
    printf("Hours Worked: %.2lf\n", hoursworked);
    printf("Hourly Wage: $%.2lf\n", hourlywage);
    printf("-------------------------\n");
    printf("Gross Pay: $%.2lf\n", grosspay);
    printf("Taxes Withheld: $%.2lf\n", taxes);
    printf("Net Pay: $%.2lf\n", netpay);
    printf("-------------------------\n");
    return 0; // Standard exit code for successful execution
}
