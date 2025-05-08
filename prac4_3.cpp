#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string type) : fuelType(type) {}
    string getFuelType() const {
        return fuelType;
    }
};

class Brand {
protected:
    string brandName;
public:
    Brand(string name) : brandName(name) {}
    string getBrandName() const {
        return brandName;
    }
};

class Car : public Fuel, public Brand {
public:
    Car(string type, string name) : Fuel(type), Brand(name) {}
    void displayInfo() const {
        cout << "Brand: " << getBrandName() << ", Fuel Type: " << getFuelType() << endl;
    }
};

int main() {
    queue<Car> serviceQueue;
    serviceQueue.push(Car("Petrol", "Toyota"));
    serviceQueue.push(Car("Diesel", "Ford"));
    serviceQueue.push(Car("Electric", "Tesla"));

    while (!serviceQueue.empty()) {
        Car currentCar = serviceQueue.front();
        currentCar.displayInfo();
        serviceQueue.pop();
    }
    
    cout<<endl<<"24CE113"<<endl<<"Dhyey shah";

    return 0;
}
