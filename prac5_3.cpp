/*Question: */

#include <iostream>
#include <vector>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class PointStack {
    vector<Point> stack;

public:
    void push(const Point& p) {
        stack.push_back(p);
    }

    Point pop() {
        if (!stack.empty()) {
            Point top = stack.back();
            stack.pop_back();
            return top;
        }
        return Point();
    }

    bool isEmpty() const {
        return stack.empty();
    }
};

int main() {
    Point p1(3, 4), p2(1, -2);
    PointStack history;

    cout << "Initial Points:" << endl;
    cout << "P1 = "; p1.display(); cout << endl;
    cout << "P2 = "; p2.display(); cout << endl;

    Point p3 = p1 + p2;
    history.push(p1);
    p1 = p3;

    cout << "After P1 + P2:" << endl;
    cout << "P1 = "; p1.display(); cout << endl;

    p1 = -p1;
    history.push(p3);

    cout << "After Negating P1:" << endl;
    cout << "P1 = "; p1.display(); cout << endl;

    cout << "Undoing last operation..." << endl;
    p1 = history.pop();
    cout << "P1 = "; p1.display(); cout << endl;

    cout << "Undoing previous operation..." << endl;
    p1 = history.pop();
    cout << "P1 = "; p1.display(); cout << endl;

    cout << "Comparing P1 and P2: ";
    if (p1 == p2)
        cout << "They are equal" << endl;
    else{
        cout << "They are not equal" << endl;
    }
    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
