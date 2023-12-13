//Liam Armstrong
//Project 6
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <limits>
using namespace std;
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    try {
        string input;

        // Prompt for input
        cout << "Enter a string (letters only): ";
        cin >> input;

        // Check if the input contains wrong characters
        for (char c : input) {
            if (!isalpha(c)) {
                throw runtime_error("Error: Input should contain letters only.");
            }
        }
        if (isPalindrome(input, 0, input.length() - 1)) {
            cout << "The input is a palindrome.\n";
        } else {
            cout << "The input is not a palindrome.\n";
        }
    } catch (const exception& e) {
        cerr << e.what() << "\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
