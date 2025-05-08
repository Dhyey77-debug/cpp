#include <iostream>
#include <string>
#include <limits>

using namespace std;

double getInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid numerical value." << endl;
        } else {
            break;
        }
    }
    return value;
}

int main() {
    double loanAmount = getInput("Enter the loan amount: ");
    double annualIncome = getInput("Enter the annual income: ");

    if (annualIncome == 0) {
        cout << "Income cannot be zero. Please enter a valid income." << endl;
    } else {
        double ratio = loanAmount / annualIncome;
        cout << "Loan-to-income ratio: " << ratio << endl;
    }
    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
