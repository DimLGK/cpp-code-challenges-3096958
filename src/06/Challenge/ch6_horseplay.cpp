// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// Converts a character digit to its integer value.
int charToDigit(char c) {
    // Throws if character is not between '0' and '9'.
    if (c < '0' || c > '9') {
        throw std::invalid_argument("Input character is not a digit");
    }

    /*
        In ASCII, digit characters are sequential:
            '0' = 48    
            '1' = 49
            '2' = 50
            ...
            '9' = 57

        So subtracting '0' (48) from any digit character gives you the numeric value:
            '0' - '0' = 0
            '1' - '0' = 1
            '5' - '0' = 5
            '9' - '0' = 9
        
        This is a common C/C++ idiom for converting single digit characters to their integer equivalents.
    */

    return c - '0';
}

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    char file = knight[0];
    int rank = charToDigit(knight[1]);

    std::vector<std::pair<int, int>> offsets = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2},
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
    };

    for (auto offset : offsets) {
        char new_file = file + offset.first;
        int new_rank = rank + offset.second;

        if (new_file >= 'a' && new_file <= 'h' && new_rank >= 1 && new_rank <= 8) {
            std::string new_move = std::string(1, new_file) + std::to_string(new_rank);
            moves.push_back(new_move);
        }
    }

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}