#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

ostream& tab(ostream& os) {
    return os << left << setw(20);
}

int main() {
    const string filename = "students.txt";
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    string name;
    int marks;
    char grade;

    cout << tab << "Name" << setw(10) << "Marks" << "Grade" << "\n";
    cout << string(35, '-') << "\n";

    while (file >> name >> marks >> grade) {
        cout << tab << name << setw(10) << marks << grade << "\n";
    }

    file.close();
    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
