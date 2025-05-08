#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int> transactions = {1001, 1002, 1003, 1001, 1004, 1002, 1005};

    set<int> uniqueTransactions(transactions.begin(), transactions.end());

    cout << "Unique transaction IDs in sorted order: ";
    for (const auto& transaction : uniqueTransactions) {
        cout << transaction << " ";
    }
    cout << endl;
    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
