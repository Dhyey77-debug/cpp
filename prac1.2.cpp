#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    void setDetails(int pid, string pname, int qty, double pr) {
        id = pid;
        name = pname;
        quantity = qty;
        price = pr;
    }

    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    double getPrice() {
        return price;
    }

    void updateQuantity(int qtyChange) {
        quantity += qtyChange;
    }

    double getTotalValue() {
        return quantity * price;
    }

    void display() {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Quantity: " << quantity
             << ", Price: $" << price << endl;
    }
};

class Inventory {
private:
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    int findProductIndex(int id) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].getID() == id) {
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

        products[productCount].setDetails(id, name, quantity, price);
        productCount++;

        cout << "Product added successfully.\n";
    }

    void updateProductQuantity(int id, int qtyChange) {
        int index = findProductIndex(id);
        if (index == -1) {
            cout << "Product with ID " << id << " not found.\n";
            return;
        }

        products[index].updateQuantity(qtyChange);
        cout << "Quantity updated successfully.\n";
    }

    double calculateTotalInventoryValue() {
        double total = 0;
        for (int i = 0; i < productCount; i++) {
            total += products[i].getTotalValue();
        }
        return total;
    }

    void displayAllProducts() {
        cout << "\nCurrent Inventory:\n";
        for (int i = 0; i < productCount; i++) {
            products[i].display();
        }
    }
};

int main() {
    Inventory store;
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
            cin.ignore(); // clear input buffer
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Price: ";
            cin >> price;

            store.addProduct(id, name, quantity, price);
        }
        else if (choice == 2) {
            int id, qtyChange;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity Change: ";
            cin >> qtyChange;

            store.updateProductQuantity(id, qtyChange);
        }
        else if (choice == 3) {
            double total = store.calculateTotalInventoryValue();
            cout << "Total Inventory Value: $" << total << endl;
        }
        else if (choice == 4) {
            store.displayAllProducts();
        }

    } while (choice != 0);
    cout<<endl<<"DHYEY SHAH "<<endl<<"24CE113";

    return 0;
}
