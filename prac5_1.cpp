#include <iostream>
#include <vector>
using namespace std;

class Calculator {
    vector<double> results;

public:
    int add(int a, int b) {
        int result = a + b;
        results.push_back(result);
        return result;
    }

    float add(float a, float b) {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        results.push_back(result);
        return result;
    }

    double add(double a, int b) {
        double result = a + b;
        results.push_back(result);
        return result;
    }

    void displayResults() {
        cout << "\nStored Results:\n";
        for (size_t i = 0; i < results.size(); ++i) {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;

    int i1 = 10, i2 = 20;
    float f1 = 5.5f, f2 = 2.5f;
    double d1 = 3.14;

    cout << "Adding integers: " << calc.add(i1, i2) << endl;
    cout << "Adding floats: " << calc.add(f1, f2) << endl;
    cout << "Adding int + double: " << calc.add(i1, d1) << endl;
    cout << "Adding double + int: " << calc.add(d1, i2) << endl;

    calc.displayResults();
    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
