// Include Files
#include <iostream>
#include <fstream>

using namespace std;


// STRING STREAM BASED PARSING
void parseFile(){
    fstream f;              // 1. Make a File object using fstream class
    f.open("test.txt");     // 2. Open the file to read

    string line;

    if(f.is_open()){
        while(getline(f, line))
            cout << line << endl;
    }
    else{
        cout << "Cannot Open File" << endl;
    }

}

// TOKEN BASED PARSING
// Read integers from file and print sum.
#include <iomanip>

int tokenBasedParsing1() {
    int sum = 0;
    int x;
    ifstream inFile;
    
    inFile.open("test.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> x) {
        sum = sum + x;
    }
    
    inFile.close();
    cout << "Sum = " << sum << endl; 
    return sum;
}

// Expanding on the above concept, if the input is:

// 1,NYC
// 2,ABQ
// ...
// you will still be able to apply the same logic, like this:

#include <fstream>

void tokenBasedParsing2(){
    std::ifstream infile("test2.txt");

    if (infile.is_open()) {
        int number;
        std::string str;
        char c;
    
        while (infile >> number >> c >> str && c == ','){
            std::cout << number << " " << str << "\n";
        }
    }
    infile.close();
}


void tokenBasedParsing3(){
    fstream infile("test2.txt");
    int count = 0;

    if (infile.is_open()) {
        int number;
        std::string str;
        char c;
    
        // Count the frequency of a number
        while (infile >> number >> c >> str && c == ','){
            std::cout << number << " " << str << "\n";
            if(number == 10 && str == " china"){
                count++;
            }
        }
    }

    cout << "Count of 10 " << count << endl;
    infile.close();
}


int main() {
    cout << "FILE PARSING IN C++" << endl;

    // parseFile();
    tokenBasedParsing3();

    return 0;

}