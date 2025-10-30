// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

void play_fizzbuzz(int n);
void run_tests();

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    play_fizzbuzz(n);

    run_tests();
    
    std::cout << std::endl << std::flush;
    return 0;
}

void play_fizzbuzz(int n) {
    if (n <= 0) {
        std::cout << "Please enter a positive integer greater than zero." << std::endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        bool m3 = (i % 3) == 0;
        bool m5 = (i % 5) == 0;

        if (m3 && m5) {
            std::cout << "FizzBuzz";
        } else if (m3) {
            std::cout << "Fizz";
        } else if (m5) {
            std::cout << "Buzz";
        } else {
            std::cout << i;
        }

        if (i < n) {
            std::cout << ", " << std::flush;
        }
    }
    
    std::cout << std::endl << std::flush;
}

void run_tests() {
    std::cout << "Running tests...\n";

    // Test case 1: FizzBuzz up to 15
    std::cout << "Test Case 1: FizzBuzz up to 15\nExpected Output:\n1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz\nActual Output:\n";
    play_fizzbuzz(15);
    std::cout << "End of Test Case 1\n\n";

    // Test case 2: FizzBuzz up to 5
    std::cout << "Test Case 2: FizzBuzz up to 5\nExpected Output:\n1, 2, Fizz, 4, Buzz\nActual Output:\n";
    play_fizzbuzz(5);
    std::cout << "End of Test Case 2\n\n";

    // Test case 3: FizzBuzz up to 3
    std::cout << "Test Case 3: FizzBuzz up to 3\nExpected Output:\n1, 2, Fizz\nActual Output:\n";
    play_fizzbuzz(3);
    std::cout << "End of Test Case 3\n\n";

    // Test case 4: FizzBuzz with invalid input (0)
    std::cout << "Test Case 4: FizzBuzz with invalid input (0)\nExpected Output:\nPlease enter a positive integer greater than zero.\nActual Output:\n";
    play_fizzbuzz(0);
    std::cout << "End of Test Case 4\n\n";

    std::cout << "All tests completed!\n\n";
}