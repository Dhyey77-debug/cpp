#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;
    stack<string> transactionHistory;

public:
    BankAccount(string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
        transactionHistory.push("Deposited: " + to_string(amount));
    }

    virtual bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push("Withdrew: " + to_string(amount));
            return true;
        }
        cout << "Insufficient funds for withdrawal."<<endl;
        return false;
    }

    void undoTransaction() {
        if (!transactionHistory.empty()) {
            cout << "Undoing last transaction: " << transactionHistory.top() << endl;
            transactionHistory.pop();
        } else {
            cout << "No transactions to undo."<<endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void printDetails() const {
        cout << "Account Number: " << accountNumber << endl
             << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        balance += balance * (interestRate / 100);
        transactionHistory.push("Applied interest: " + to_string(interestRate) + "%");
    }

    void printDetails() const {
        BankAccount::printDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    bool withdraw(double amount) {
        if (amount <= (balance + overdraftLimit)) {
            balance -= amount;
            transactionHistory.push("Withdrew: " + to_string(amount));
            return true;
        }
        cout << "Exceeded overdraft limit."<<endl;
        return false;
    }

    void printDetails() const {
        BankAccount::printDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings("12345", 1000.0, 5.0);
    savings.printDetails();
    savings.deposit(500.0);
    savings.applyInterest();
    cout << "Balance after deposit and interest: " << savings.getBalance() <<endl;

    savings.undoTransaction();
    cout << "Balance after undo: " << savings.getBalance() << endl;

    CurrentAccount current("67890", 500.0, 200.0);
    current.printDetails();
    current.deposit(300.0);
    current.withdraw(700.0);
    cout << "Balance after deposit and withdrawal: " << current.getBalance() << endl;

    current.undoTransaction();
    cout << "Balance after undo: " << current.getBalance() << endl;

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
