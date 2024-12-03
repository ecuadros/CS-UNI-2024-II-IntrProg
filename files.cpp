#include <iostream>
#include <fstream>
#include <string>
#include "files.h"
using namespace std;

void WriteFile()
{
    ofstream outputFile("example.txt");

    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return; 
    }

    // Write data to the file
    outputFile << "This is some text for the file.\n";
    outputFile << "This is another line.\n";

    // Write data from variables
    string name = "Alice";
    int age = 30;
    outputFile << "Name: " << name << ", Age: " << age << endl;

    // Close the output file (important!)
    outputFile.close();
}

void ReadFile(){
    ifstream inputFile("example.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return; 
    }

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
}

void DemoFiles(){
    WriteFile();
    ReadFile();
}