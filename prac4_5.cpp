#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    vector<int> marks;
public:
    Student(const string& n) : name(n) {}
    virtual void inputMarks() = 0;
    virtual char computeGrade() const = 0;
    virtual void display() const = 0;
    virtual ~Student() {}
};

class Undergraduate : public Student {
public:
    Undergraduate(const string& n) : Student(n) {}
    void inputMarks() override {
        marks.clear();
        cout << "Enter 3 marks for " << name << ": ";
        for (int i = 0; i < 3; ++i) {
            int m;
            cin >> m;
            marks.push_back(m);
        }
    }
    char computeGrade() const override {
        int total = 0;
        for (int m : marks) total += m;
        float avg = total / 3.0f;
        if (avg >= 85) return 'A';
        else if (avg >= 70) return 'B';
        else if (avg >= 50) return 'C';
        else return 'F';
    }
    void display() const override {
        cout << "Undergraduate: " << name << ", Grade: " << computeGrade() << endl;
    }
};

class Postgraduate : public Student {
public:
    Postgraduate(const string& n) : Student(n) {}
    void inputMarks() override {
        marks.clear();
        cout << "Enter 4 marks for " << name << ": ";
        for (int i = 0; i < 4; ++i) {
            int m;
            cin >> m;
            marks.push_back(m);
        }
    }
    char computeGrade() const override {
        int total = 0;
        for (int m : marks) total += m;
        float avg = total / 4.0f;
        if (avg >= 90) return 'A';
        else if (avg >= 75) return 'B';
        else if (avg >= 60) return 'C';
        else return 'F';
    }
    void display() const override {
        cout << "Postgraduate: " << name << ", Grade: " << computeGrade() << endl;
    }
};

int main() {
    vector<Student*> students;
    int choice;

    do {
        cout << "\n1. Add Undergraduate\n2. Add Postgraduate\n3. Show All\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            string name;
            cout << "Enter name: ";
            cin >> name;

            Student* s = nullptr;
            if (choice == 1) s = new Undergraduate(name);
            else if (choice == 2) s = new Postgraduate(name);

            if (s) {
                s->inputMarks();
                students.push_back(s);
            }
        } else if (choice == 3) {
            for (Student* s : students) s->display();
        }

    } while (choice != 0);

    for (Student* s : students) delete s;

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
