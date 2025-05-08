#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int score;
};

bool compare(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 92},
        {"David", 88},
        {"Eve", 95}
    };

    sort(students.begin(), students.end(), compare);

    cout << "Ranked Students:" << endl;
    for (const auto& student : students) {
        cout << student.name << ": " << student.score << endl;
    }

    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
