#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate factorial
int calculateFactorial(int n) {
    if (n < 0) {
        return -1; // Indicate an error for negative input
    }
    else if (n == 0 || n == 1) {
        return 1;
    }
    else {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

// Function to calculate arithmetic series
void calculateArithmeticSeries() {
    int difference, startingNumber, numberOfElements;

    cout << "Difference: ";
    cin >> difference;

    cout << "Starting number: ";
    cin >> startingNumber;

    cout << "Number of elements in the series: ";
    cin >> numberOfElements;

    if (numberOfElements <= 0) {
        cout << "Number of elements must be positive." << endl;
        return;
    }

    // Display the series equation
    cout << "Equation: ";
    cout << "n/2 * [2 * " << startingNumber << " + (n-1) * " << difference << "]";

    // Display the series
    cout << "\nArithmetic Series: ";
    for (int i = 0; i < numberOfElements; ++i) {
        cout << startingNumber + i * difference;
        if (i < numberOfElements - 1) {
            cout << " + ";
        }
    }

    int seriesSum = (numberOfElements * (2 * startingNumber + (numberOfElements - 1) * difference)) / 2;

    cout << "\nArithmetic Series Sum = " << seriesSum << endl;
}

// Function to calculate geometric series
void calculateGeometricSeries() {
    float ratio, constantFactor;
    int numberOfElements;

    cout << "Ratio: ";
    cin >> ratio;

    cout << "Constant factor (a): ";
    cin >> constantFactor;

    cout << "Number of elements in the series: ";
    cin >> numberOfElements;

    if (numberOfElements <= 0) {
        cout << "Number of elements must be positive." << endl;
        return;
    }

    // Display the series equation
    cout << "Series Equation: ";
    cout << "a * (1 - r^n) / (1 - r)";

    // Display the series
    cout << "\nGeometric Series: ";
    float seriesResult = 0;
    for (int i = 0; i < numberOfElements; ++i) {
        float term = constantFactor * pow(ratio, i);
        seriesResult += term;
        cout << term;
        if (i < numberOfElements - 1) {
            cout << " + ";
        }
    }

    cout << "\nGeometric Series Sum = " << seriesResult << endl;
}

// Function to print out the menu of choices for the user to select from
void printMenu() {
    cout << "Please Select which operation to perform:" << endl;
    cout << "\t1. Factorial" << endl;
    cout << "\t2. Arithmetic Series" << endl;
    cout << "\t3. Geometric Series" << endl;
    cout << "\t4. Exit" << endl;
    cout << "Your Selection: ";
}

int main() {
    int choice;
    char again;
    do {
        printMenu();
        cin >> choice;

        if (choice > 4 || choice < 1) {
            cout << "Invalid selection. Exiting." << endl;
            return 0;
        }
        else if (choice == 1) {
            int n;
            cout << "Enter a number for factorial calculation: ";
            cin >> n;

            int result = calculateFactorial(n);
            if (result == -1) {
                cout << "Factorial is not defined for negative numbers." << endl;
            }
            else {
                // Display the factorial equation
                cout << "Equation: " << n << "! = ";
                for (int i = 1; i <= n; ++i) {
                    cout << i;
                    if (i < n) {
                        cout << " * ";
                    }
                }

                cout << "\nFactorial of " << n << " = " << result << endl;
            }
        }
        else if (choice == 2) {
            calculateArithmeticSeries();
        }
        else if (choice == 3) {
            calculateGeometricSeries();
        }

        cout << "\nGo Again? [Y/N] ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
