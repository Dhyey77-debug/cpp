#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

class Inventory {
private:
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    int findProductIndex(int id) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void addProduct(int id, string name, int quantity, double price) {
        if (productCount >= MAX_PRODUCTS) {
            cout << "Inventory full. Cannot add more products.\n";
            return;
        }

        if (findProductIndex(id) != -1) {
            cout << "Product with ID " << id << " already exists.\n";
            return;
        }

        products[productCount].id = id;
        products[productCount].name = name;
        products[productCount].quantity = quantity;
        products[productCount].price = price;
        productCount++;

        cout << "Product added successfully.\n";
    }

    void updateQuantity(int id, int quantityChange) {
        int index = findProductIndex(id);
        if (index == -1) {
            cout << "Product with ID " << id << " not found.\n";
            return;
        }

        products[index].quantity += quantityChange;
        cout << "Quantity updated successfully.\n";
    }

    double calculateTotalValue() {
        double total = 0.0;
        for (int i = 0; i < productCount; i++) {
            total += products[i].quantity * products[i].price;
        }
        return total;
    }

    void displayInventory() {
        cout << "\nCurrent Inventory:\n";
        for (int i = 0; i < productCount; i++) {
            cout << "ID: " << products[i].id
                 << ", Name: " << products[i].name
                 << ", Quantity: " << products[i].quantity
                 << ", Price: $" << products[i].price << endl;
        }
    }
};

int main() {
    Inventory storeInventory;
    int choice;

    do {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Show Total Inventory Value\n";
        cout << "4. Display All Products\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, quantity;
            double price;
            string name;

            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore(); // to clear input buffer
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Price: ";
            cin >> price;

            storeInventory.addProduct(id, name, quantity, price);
        }
        else if (choice == 2) {
            int id, qtyChange;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity Change: ";
            cin >> qtyChange;

            storeInventory.updateQuantity(id, qtyChange);
        }
        else if (choice == 3) {
            double total = storeInventory.calculateTotalValue();
            cout << "Total Inventory Value: $" << total << endl;
        }
        else if (choice == 4) {
            storeInventory.displayInventory();
        }
    } while (choice != 0);
    cout<<endl<<"DHYEY SHAH"<<endl<<"24ce113"<<endl;

    return 0;
}
