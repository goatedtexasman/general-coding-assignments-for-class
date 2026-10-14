#include <iostream>
#include <fstream>



// find padovan sequence using two functions
// will recieve an input file

using namespace std;


// function prototype for openFiles
// this function will prompt the user to enter the input and output files

void openFiles (ifstream& inputFile, ofstream& outputFile);


int main(){


ifstream inputFile;
ofstream outputFile;



openFiles(inputFile, outputFile); // open the input and output files

outputFile << "Kayden Conner" << endl << "Program #1\n" << endl;


// checks if the input and output files are open, if not, it will display an error message 
if (!inputFile) {
    cerr << "Error opening input file. " << endl;
    return 1; 
}
if (!outputFile) {
    cerr << "Error opening output file." << endl;
    return 1;
}
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