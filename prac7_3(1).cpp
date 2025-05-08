#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addItem(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;

    outFile << name << " " << quantity << " " << price << "\n";
    outFile.close();
}

void viewInventory(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Inventory:\n";
    while (inFile >> name >> quantity >> price) {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: " << price << "\n";
    }

    inFile.close();
}

void searchItem(const string& filename, const string& target) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    string name;
    int quantity;
    double price;
    bool found = false;

    while (inFile >> name >> quantity >> price) {
        if (name == target) {
            cout << "Found: Name: " << name << ", Quantity: " << quantity << ", Price: " << price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Item not found.\n";

    inFile.close();
}

int main() {
    const string filename = "inventory.txt";
    int choice;
    string itemName;

    do {
        cout << "\n1. Add Item\n2. View Inventory\n3. Search Item\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(filename);
                break;
            case 2:
                viewInventory(filename);
                break;
            case 3:
                cout << "Enter item name to search: ";
                cin >> itemName;
                searchItem(filename, itemName);
                break;
        }
    } while (choice != 0);

    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
