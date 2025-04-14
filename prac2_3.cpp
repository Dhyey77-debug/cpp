#include <iostream>
#include <string.h>

using namespace std;

class bank {//class has been created named bank
private:
    char name[20];
    double account_num;
    float balance;

public:
    static int account_count;

    // Default constructor
    bank() {
        strcpy(name, "default name");
        account_num = 0;
        balance = 0;
    }

    // Parameterized constructor
    bank(char n[20], double a, float b) {
        strcpy(name, n);
        account_num = a;
        balance = b;
    }

    void creat_account() { // function is created to add account
        char n[20];
        double a;
        float b;

        account_count++;
        cout << "Enter your name: ";
        cin >> n;
        cout << "Enter your account number: ";
        cin >> a;
        cout << "Enter initial balance: ";
        cin >> b;

        // Creating the bank account object
        bank new_account(n, a, b);
        cout << "Account successfully created!" << endl;
        cout << "Account Name: " << new_account.name << endl;
        cout << "Account Number: " << new_account.account_num << endl;
        cout << "Initial Balance: " << new_account.balance << endl;
    }

    void deposit() { // function created for depositing money
        float amount;
        cout << "Enter amount of money to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Your amount has been successfully deposited." << endl;
        cout << "Your current balance: " << balance << endl;
    }

    void withdraw() { //function for withdrawing money
        float amount;
        cout << "Enter amount of money to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Your amount has been successfully withdrawn." << endl;
            cout << "Your current balance: " << balance << endl;
        }
    }

    void show_account_details() {//function for displaying account details
        cout << "Account Name: " << name << endl;
        cout << "Account Number: " << account_num << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

// Initialize the static member variable
int bank::account_count = 0;

int main() {
    int num;
    bank my_bank_account;

    cout << "Enter 1 for creating Account." << endl;
    cout << "Enter 2 for depositing money." << endl;
    cout << "Enter 3 for withdrawing money." << endl;
    cout << "Enter 4 for showing your bank details." << endl;
    cout << "Enter your choice: ";
    cin >> num;

    switch (num) { //switch is used for creating account,withdraw,deposit and displaying account
        case 1:
            my_bank_account.creat_account();
            break;
        case 2:
            my_bank_account.deposit();
            break;
        case 3:
            my_bank_account.withdraw();
            break;
        case 4:
            my_bank_account.show_account_details();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    cout<<endl<<"Dhyey shah"<<endl<<"24CE113";

    return 0;
}