#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    const string filename = "sample.txt";
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    vector<string> lines;
    string line;
    int wordCount = 0, charCount = 0;

    while (getline(file, line)) {
        lines.push_back(line);
        charCount += line.length() + 1;

        istringstream iss(line);
        string word;
        while (iss >> word)
            ++wordCount;
    }

    cout << "Lines: " << lines.size() << "\nWords: " << wordCount << "\nCharacters: " << charCount << "\n";

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}