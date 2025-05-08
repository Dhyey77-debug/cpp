#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int marks;
    char grade;
};

ostream& tab(ostream& os) {
    return os << left << setw(20);
}

void displayReport(const vector<Student>& students) {
    cout << tab << "Name" << setw(10) << "Marks" << "Grade" << "\n";
    cout << string(35, '-') << "\n";
    for (const auto& s : students) {
        cout << tab << s.name << setw(10) << s.marks << s.grade << "\n";
    }
}

int main() {
    const string filename = "students.txt";
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    vector<Student> students;
    Student s;

    while (file >> s.name >> s.marks >> s.grade) {
        students.push_back(s);
    }

    file.close();

    // Optional sorting (e.g., by marks descending)
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    });

    displayReport(students);

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}