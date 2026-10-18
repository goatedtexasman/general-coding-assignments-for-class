//Kayden Conner
// Program 2
// CMPS 2433-101 Discrete Structures

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


// Prompts the user for the input and output file names and opens both files.
// inputFile:  input stream to be opened for reading
// outputFile: output stream to be opened for writing
void openFiles(ifstream& inputFile, ofstream& outputFile);

// Writes the programmer's name and the column headings to the output file.
// outputFile: an open output stream
void printHeading(ofstream& outputFile);

// Returns the nth Padovan number using a loop (no recursion).
// n: which Padovan number to calculate (n >= 0)
long long loopPadovan(int n);

// Returns the nth Padovan number using recursion.
// n: which Padovan number to calculate (n >= 0)
long long recPadovan(int n);

// Returns the sum of the first N Padovan numbers, P(0) through P(n),
// using the formula: sum = P(n + 5) - 2.
// n: the last term to include in the sum (n >= 0)
long long sumPadovan(int n);



int main() {
    ifstream inputFile;
    ofstream outputFile;
    int n;                          // current test case read from the file

    openFiles(inputFile, outputFile);

    // make sure both files opened before using them
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    printHeading(outputFile);

    inputFile >> n;                 // priming read

    while (!inputFile.eof()) {
        // one row: N, iterative result, recursive result, sum
        outputFile << setw(3)  << n
                   << setw(15) << loopPadovan(n)
                   << setw(15) << recPadovan(n)
                   << setw(15) << sumPadovan(n) << endl;

        inputFile >> n;             // read the next value (end of loop)
    }

    inputFile.close();
    outputFile.close();

    cout << endl << "Program executed." << endl;

    return 0;
}



// openFiles: asks the user for both file names and opens the files.
void openFiles(ifstream& inputFile, ofstream& outputFile) {
    string inputName;               // name of the file to read from
    string outputName;              // name of the file to write to

    cout << "Enter the name of the input file: ";
    cin >> inputName;
    inputFile.open(inputName.c_str());

    cout << "Enter the name of the output file: ";
    cin >> outputName;
    outputFile.open(outputName.c_str());
}



// printHeading: writes the name line, a blank line, and the column labels.
void printHeading(ofstream& outputFile) {
    outputFile << "Kayden Conner" << endl << "Program #2" << endl << endl;

    outputFile << setw(3)  << "N"
               << setw(15) << "loopPadovan"
               << setw(15) << "recPadovan"
               << setw(15) << "Sum" << endl;
}



// loopPadovan: iterative solution. Only the previous three values are needed,
// so they are kept in a, b, c and slid forward on each pass of the loop.

long long loopPadovan(int n) {
    // base cases: P(0) = P(1) = P(2) = 1
    if (n <= 2) {
        return 1;
    }

    long long older  = 1;           // P(i-3)
    long long middle = 1;           // P(i-2)
    long long newest = 1;           // P(i-1)
    long long current = 1;          // P(i)

    for (int i = 3; i <= n; i++) {
        current = middle + older;   // P(i) = P(i-2) + P(i-3)

        // slide the window forward by one term
        older  = middle;
        middle = newest;
        newest = current;
    }

    return current;
}


// recPadovan: recursive solution, a direct translation of the recurrence.
// Slow for large n because the same terms are recalculated many times.
long long recPadovan(int n) {
    // base cases: P(0) = P(1) = P(2) = 1
    if (n <= 2) {
        return 1;
    }

    // recursive case: P(n) = P(n-2) + P(n-3)
    return recPadovan(n - 2) + recPadovan(n - 3);
}


// sumPadovan: sum of P(0) through P(n) using the formula P(n + 5) - 2.
// Calls loopPadovan so the large term is found quickly.
long long sumPadovan(int n) {
    return loopPadovan(n + 5) - 2;
}