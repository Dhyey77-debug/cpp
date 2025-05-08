#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override {
        return length * width;
    }
    void display() const override {
        cout << "Rectangle: Area = " << Area() << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override {
        return 3.14159 * radius * radius;
    }
    void display() const override {
        cout << "Circle: Area = " << Area() << endl;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(4));
    shapes.push_back(new Rectangle(2, 7));
    shapes.push_back(new Circle(6));

    cout << "Shape Areas:" << endl;
    for (Shape* shape : shapes) {
        shape->display();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
