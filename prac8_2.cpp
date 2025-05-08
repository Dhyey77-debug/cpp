#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <iterator>
using namespace std;

void countWordFrequencies(const std::string& sentence) {
    std::map<std::string, int> wordFrequency;  // Map to store word counts
    std::string word;
    std::stringstream ss(sentence);  // Use stringstream to parse the sentence

    // Parse the sentence and count word frequencies
    while (ss >> word) {
        // Remove punctuation from each word (if any)
        for (char &c : word) {
            if (std::ispunct(c)) {
                c = ' ';  // Replace punctuation with spaces
            }
        }

        // Convert word to lowercase to make counting case-insensitive
        for (char &c : word) {
            c = std::tolower(c);
        }

        // Increment the frequency of the word in the map
        ++wordFrequency[word];
    }

    // Display the word frequencies
    std::cout << "Word frequency distribution:\n";
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);  // Input sentence

    countWordFrequencies(sentence);  // Process and display word frequencies
    cout<<endl<<"24CE113-Dhyey shah"<<endl;
    return 0;
}
