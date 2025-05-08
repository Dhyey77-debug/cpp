#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
    int* arr;
public:
    Derived() {
        arr = new int[5];
        cout << "Derived constructor" << endl;
    }
    ~Derived() {
        delete[] arr;
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
