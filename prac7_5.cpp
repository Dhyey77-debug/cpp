#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    double marks;
    double tuition;
};

class Currency {
    char symbol;
public:
    Currency(char s) : symbol(s) {}
    friend ostream& operator<<(ostream& os, const Currency& c) {
        return os << c.symbol;
    }
};

Currency currency(char symbol) {
    return Currency(symbol);
}

int main() {
    vector<Student> students = {
        {"Alice", 89.456, 25000.50},
        {"Bob", 72.3, 18000.75},
        {"Clara", 95.78, 30500.00},
        {"David", 60.0, 17000.00}
    };

    cout << fixed << setprecision(2);
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    for (const auto& s : students) {
        cout << left << setw(15) << s.name
             << right << setw(10) << s.marks
             << setw(5) << " " << currency('₹') << setw(8) << s.tuition << endl;
    }

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}