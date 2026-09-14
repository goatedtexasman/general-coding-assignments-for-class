#include <iostream>
#include <fstream> 
#include <string>

using namespace std;




int main() {



string filename = "bits1.dat";              // checks for the file
ifstream inputFile(filename);
    
if (!inputFile) {                   // if the file doesn't open, display error message
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

cout <<"the file is working" << endl;


}