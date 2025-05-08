#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int x_val = 0.0, int y_val = 0.0) : x(x_val), y(y_val) {}

    Point* move(const int& dx, const int& dy) {
        this->x += dx;
        this->y += dy;
        return this;
    }

    void print() const {
        cout << endl << "Final Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x , y;
    cout << "Enter Initial Coordinates: ";
    cin >> x >> y;
    cout<< "Initial Coordinates: (" << x << "," << y << ")" << endl;
    Point* p = new Point(x,y);

    int dx1, dy1;
    cout << "Enter Coordinates x1 & y1: ";
    cin >> dx1 >> dy1;
    cout << "(x1,y1) Coordinates: (" << dx1 << "," << dy1 << ")" << endl;
    int dx2, dy2;
    cout << "Enter Coordinates x1 & y2: ";
    cin >> dx2 >> dy2;
    cout << "(x2,y2) Coordinates: (" << dx2 << "," << dy2 << ")" << endl;

    p->move(dx1, dy1)
     ->move(dx2, dy2);

    p->print();

    delete p;

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}

