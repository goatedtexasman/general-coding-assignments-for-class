// Kayden Conner - CMPS 2433-101 Discrete Structures - Program 1 - 14/9/26



#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <iomanip>


using namespace std;


void printArray(ostream& out, const vector<short>& arr, int generation);
void openFiles (ifstream& inputFile, ofstream& outputFile);
void whileLoopforGenerations(vector<short>& arr, int n, ofstream& outputFile);
vector<short> readArray(ifstream& inputFile, int& n);


int main() {

ifstream inputFile;
ofstream outputFile;



openFiles(inputFile, outputFile); // open the input and output files

outputFile << "Kayden Conner" << endl << "Program 1\n" << endl;


if (!inputFile) {
    cerr << "Error opening input file. " << endl;
    return 1; 
}
if (!outputFile) {
    cerr << "Error opening output file." << endl;
    return 1;
}



int n; 
vector<short> arr = readArray(inputFile, n); // reads the array from the input file


printArray(cout, arr, 0);
printArray(outputFile, arr, 0);

whileLoopforGenerations(arr, n, outputFile); // calls the function to compute the generations

cout << "Generations complete!" << endl;
outputFile << "Generations complete!" << endl; 
outputFile.close(); // finally closes the output file
return 0;

}


// Function to print the contents of the array and then calculate the sum of the elements in the array
void printArray(ostream& out, const vector<short>& arr, int generation){
    out << "Generation " << generation << ": ";
    int sum = 0;
    for (short val : arr) {
        out << setw(6) << val; //organizes my output to be in a column format
        sum += val;
    }

    out << "   Sum : " << setw(5) << sum << endl;
}

void openFiles (ifstream& inputFile, ofstream& outputFile){
    char inputName[40];
    char outputName[40];

    cout <<"Enter the input file name: "; 
    cin >> inputName;
    inputFile.open(inputName); // opens input file

    cout << "Enter the output file name: ";
    cin >> outputName;
    outputFile.open(outputName); //opens output file
}


void whileLoopforGenerations(vector<short>& arr, int n, ofstream& outputFile){
    int generation = 0; 
    char choice;

    while (true) { 
        cout << endl << "Compute another generation? (Y/N): ";
        cin >> choice;
    if (choice != 'Y' && choice != 'y') break;

        generation++;

   
    // calculations of the index to determine if odd, even, or the last digit in the array
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                arr[0] = arr[0] >> 1;
            }
            else if (j == n - 1 ) { 
                short mask = 1 << generation;
                arr[j] = arr[j] & ~mask;
            }
            else if (j % 2 == 1) { // odd generation
                arr[j] = arr[j] & arr[j-1];
            }
            else { // even generation
                arr[j] = arr[j] ^ arr[j+1];
            }

    }
    
    printArray(cout, arr, generation);
    printArray(outputFile, arr, generation);
    }
}

vector<short> readArray(ifstream& inputFile, int& n) {
    inputFile >> n; // read the first integer from the file (sets n in main, too)

    vector<short> arr(n);
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i]; // read the next n integers from the file into the vector
    }
    inputFile.close(); // closes the file

    return arr;
}
