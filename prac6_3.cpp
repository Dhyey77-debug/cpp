
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int s) : size(s) {
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size)
            data[index] = value;
    }

    int get(int index) const {
        if (index >= 0 && index < size)
            return data[index];
        return -1;
    }

    void read() {
        for (int i = 0; i < size; ++i)
            cin >> data[i];
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    friend DynamicArray mergeSortedArrays(const DynamicArray& a, const DynamicArray& b);
};

DynamicArray mergeSortedArrays(const DynamicArray& a, const DynamicArray& b) {
    int size1 = a.getSize();
    int size2 = b.getSize();
    DynamicArray result(size1 + size2);

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (a.get(i) <= b.get(j))
            result.set(k++, a.get(i++));
        else
            result.set(k++, b.get(j++));
    }

    while (i < size1)
        result.set(k++, a.get(i++));

    while (j < size2)
        result.set(k++, b.get(j++));

    return result;
}

int main() {
    int size1, size2;

    cout << "Enter size of first sorted array: ";
    cin >> size1;
    cout << "Enter size of second sorted array: ";
    cin >> size2;

    DynamicArray arr1(size1);
    DynamicArray arr2(size2);

    cout << "Enter elements of the first sorted array: ";
    arr1.read();

    cout << "Enter elements of the second sorted array: ";
    arr2.read();

    DynamicArray merged = mergeSortedArrays(arr1, arr2);

    cout << "Merged sorted array: ";
    merged.print();

    cout<<endl<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
