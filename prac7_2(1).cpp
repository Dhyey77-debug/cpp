#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    const char* filename = "sample.txt";
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    const int MAX_LINES = 10000;
    char** lines = new char*[MAX_LINES];
    int lineCount = 0, wordCount = 0, charCount = 0;

    string tempLine;
    while (getline(file, tempLine) && lineCount < MAX_LINES) {
        lines[lineCount] = new char[tempLine.length() + 1];
        strcpy(lines[lineCount], tempLine.c_str());
        charCount += tempLine.length() + 1;

        char* copy = new char[tempLine.length() + 1];
        strcpy(copy, tempLine.c_str());
        char* token = strtok(copy, " \t\n,.!?;:-");

        while (token) {
            ++wordCount;
            token = strtok(nullptr, " \t\n,.!?;:-");
        }
        delete[] copy;

        ++lineCount;
    }

    cout << "Lines: " << lineCount << "\nWords: " << wordCount << "\nCharacters: " << charCount << "\n";

    for (int i = 0; i < lineCount; ++i)
        delete[] lines[i];
    delete[] lines;

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}