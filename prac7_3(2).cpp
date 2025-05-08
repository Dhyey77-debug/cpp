#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

void addItem(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Cannot open file.\n";
        return;
    }

    Item item;
    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter quantity: ";
    cin >> item.quantity;
    cout << "Enter price: ";
    cin >> item.price;

    outFile << item.name << " " << item.quantity << " " << item.price << "\n";
    outFile.close();
}

vector<Item> loadInventory(const string& filename) {
    vector<Item> inventory;
    ifstream inFile(filename);
    if (!inFile) return inventory;

    Item item;
    while (inFile >> item.name >> item.quantity >> item.price) {
        inventory.push_back(item);
    }

    return inventory;
}

void viewInventory(const vector<Item>& inventory) {
    cout << "Inventory:\n";
    for (const auto& item : inventory) {
        cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << "\n";
    }
}

void searchItem(const vector<Item>& inventory, const string& target) {
    for (const auto& item : inventory) {
        if (item.name == target) {
            cout << "Found: Name: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << "\n";
            return;
        }
    }
    cout << "Item not found.\n";
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
            case 2: {
                vector<Item> inventory = loadInventory(filename);
                viewInventory(inventory);
                break;
            }
            case 3: {
                vector<Item> inventory = loadInventory(filename);
                cout << "Enter item name to search: ";
                cin >> itemName;
                searchItem(inventory, itemName);
                break;
            }
        }
    } while (choice != 0);

     cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
