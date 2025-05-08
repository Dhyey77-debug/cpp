#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Directory {
private:
    map<string, vector<string>> directory;

public:
    void addFolder(const string& folderName) {
        if (directory.find(folderName) == directory.end()) {
            directory[folderName] = vector<string>();
        }
    }

    void addFileToFolder(const string& folderName, const string& fileName) {
        if (directory.find(folderName) != directory.end()) {
            directory[folderName].push_back(fileName);
        } else {
            cout << "Folder does not exist!" << endl;
        }
    }

    void displayDirectory() const {
        for (const auto& folder : directory) {
            cout << folder.first << ":" << endl;
            for (const auto& file : folder.second) {
                cout << "  " << file << endl;
            }
        }
    }
};

int main() {
    Directory dir;

    dir.addFolder("Documents");
    dir.addFolder("Pictures");
    dir.addFolder("Projects");

    dir.addFileToFolder("Documents", "Resume.pdf");
    dir.addFileToFolder("Documents", "Report.docx");
    dir.addFileToFolder("Pictures", "Vacation.jpg");
    dir.addFileToFolder("Projects", "Project1.cpp");

    dir.displayDirectory();

    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
