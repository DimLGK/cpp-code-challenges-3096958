// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>
#include <cassert>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// run_tests()
// Summary: Runs test cases to verify the is_palindrome function works correctly.
void run_tests(){
    std::cout << "Running tests...\n";

    // Test palindromes
    assert(is_palindrome("civic") == true);
    assert(is_palindrome("Civic") == true);
    assert(is_palindrome("radar") == true);
    assert(is_palindrome("level") == true);
    assert(is_palindrome("racecar") == true);
    assert(is_palindrome("Rats live on no evil star") == true);

    // Test non-palindromes
    assert(is_palindrome("hello") == false);
    assert(is_palindrome("world") == false);
    assert(is_palindrome("Don't nod") == false);
    assert(is_palindrome("Evil olive") == false);

    // Test edge cases
    assert(is_palindrome("") == true);      // empty string
    assert(is_palindrome("a") == true);     // single char
    assert(is_palindrome("aa") == true);    // two same chars
    assert(is_palindrome("ab") == false);   // two different chars

    std::cout << "All tests passed!\n\n";
}

// Main function
int main(){
    // Run tests first
    run_tests();

    // Interactive part
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
