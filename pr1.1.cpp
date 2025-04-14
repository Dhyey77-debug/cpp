#include<iostream> 
#include<string>
using namespace std;

class BankAccount
{
private:
    string name;
    int account_number;
    double balance;

public:
    // Constructor to initialize the bank account
    BankAccount(string accName, int accNumber, double initialBalance) {
        name = accName;
        account_number = accNumber;
        balance = initialBalance;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Error: Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrew: " << amount << ". New balance: " << balance << endl;
            } else {
                cout << "Error: Insufficient balance." << endl;
            }
        } else {
            cout << "Error: Invalid withdrawal amount." << endl;
        }
    }

    // Method to display the current balance
    void display_balance() const {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // Getter for account number (optional)
    int get_account_number() const {
        return account_number;
    }
};

int main() {
    int no_accounts;
    cout << "Enter the number of accounts: ";
    cin >> no_accounts;

    // Array of BankAccount pointers for multiple accounts
    BankAccount* accounts[no_accounts];

    // Loop to create and initialize accounts
    for (int i = 0; i < no_accounts; i++) {
        string name;
        int account_number;
        double initial_balance;

        cout << "\nEnter details for Account " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> account_number;
        cout << "Enter initial balance: ";
        cin >> initial_balance;

        // Create a BankAccount object and store it in the array
        accounts[i] = new BankAccount(name, account_number, initial_balance);
    }

    // Perform operations: deposit and withdraw for each account
    for (int i = 0; i < no_accounts; i++) {
        double amount;

        // Deposit
        cout << "\nEnter amount to deposit for Account " << i + 1 << ": ";
        cin >> amount;
        accounts[i]->deposit(amount);

        // Withdraw
        cout << "Enter amount to withdraw for Account " << i + 1 << ": ";
        cin >> amount;
        accounts[i]->withdraw(amount);
    }

    // Display balance for all accounts
    cout << "\nDisplaying account balances:\n";
    for (int i = 0; i < no_accounts; i++) {
        accounts[i]->display_balance();
    }
    cout<<"DHYEY SHAH"<<endl<<"24CE113"<<endl;


    return 0;
}
