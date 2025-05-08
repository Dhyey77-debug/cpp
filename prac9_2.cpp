#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            logError("Deposit amount must be positive.");
            return;
        }
        balance += amount;
        transactionHistory.push_back("Deposited: " + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logError("Withdrawal amount must be positive.");
            return;
        }
        if (amount > balance) {
            logError("Insufficient balance for withdrawal.");
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrew: " + to_string(amount));
    }

    void logError(const string& error) {
        cout << "Error: " << error << endl;
        transactionHistory.push_back("Error: " + error);
    }

    void printTransactionHistory() const {
        cout << "Transaction History for " << accountHolder << ":" << endl;
        for (const auto& transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account("John Doe", 500.0);

    cout << "Initial balance: $" << account.getBalance() << endl;

    account.deposit(200.0);
    account.withdraw(100.0);
    account.withdraw(700.0);  // Error: insufficient funds
    account.deposit(-50.0);    // Error: invalid deposit

    account.printTransactionHistory();
    cout << "Final balance: $" << account.getBalance() << endl;
    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
