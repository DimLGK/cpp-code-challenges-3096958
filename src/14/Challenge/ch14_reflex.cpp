// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <thread>
#include <cstdlib>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    do{
        // Generate a random delay between 4 and 10 seconds
        int delay_seconds=4 + (rand() % 7);

        // Wait for the random delay
        std::this_thread::sleep_for(std::chrono::seconds(delay_seconds));
        
        // Select a random word from the list
        std::string random_word=words[rand() % 10];
        
        // Prompt the user to type in the word
        std::cout << "\nType in this word: " << random_word << "\n" << std::flush;
        // Start measuring time
        auto start_time=std::chrono::high_resolution_clock::now();
        
        // Get the user's input
        std::string user_input;
        std::getline(std::cin, user_input);
        
        // Stop measuring time
        auto end_time=std::chrono::high_resolution_clock::now();
        
        // Calculate the elapsed time in milliseconds
        auto elapsed_time=std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        
        // Convert both strings to uppercase for case-insensitive comparison
        std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
        
        // Check if the user input matches the random word and if it was entered within 2 seconds
        if(user_input==random_word && elapsed_time<=2000){
            std::cout << "Congratulations! You typed the word correctly in " << elapsed_time << " milliseconds.\n";
        }else{
            std::cout << "Sorry, you failed. You took " << elapsed_time << " milliseconds.\n";
        }

        // Ask the user if they want to try again
        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
