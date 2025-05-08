#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;
    cout << "Input first complex number:\n";
    cin >> c1;
    cout << "Input second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nFirst Complex: " << c1 << endl;
    cout << "Second Complex: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    vector<Complex> complexList;
    int n;
    cout << "\nEnter number of complex numbers to input: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Complex temp;
        cout << "Complex number " << i + 1 << ":\n";
        cin >> temp;
        complexList.push_back(temp);
    }

    Complex total;
    for (const Complex& c : complexList)
        total = total + c;

    cout << "\nTotal sum of all complex numbers: " << total << endl;
    cout << "\n\n24CE113 - Dhyey shah" << endl;
    return 0;
}
