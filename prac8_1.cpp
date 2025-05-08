#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Original sequence: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> reversed_numbers = numbers;

    // Using std::reverse() to reverse the sequence
    std::reverse(reversed_numbers.begin(), reversed_numbers.end());

    std::cout << "Reversed sequence (using std::reverse): ";
    for (const auto& num : reversed_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Manually reversing the sequence using iterators
    std::vector<int> manual_reversed_numbers = numbers;
    auto left = manual_reversed_numbers.begin();
    auto right = manual_reversed_numbers.end() - 1;

    while (left < right) {
        std::swap(*left, *right);
        ++left;
        --right;
    }

    std::cout << "Reversed sequence (manual iteration): ";
    for (const auto& num : manual_reversed_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
