// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>
#include <cassert>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    enum State { ASCENDING, DESCENDING, UNDEFINED };
    State state = UNDEFINED;
    size_t n = v.size();
    size_t transitions = 0;
    size_t maxTransitions = 2;

    
    for(size_t i = 0; i < n; ++i) {
        size_t next = (i + 1) % n;

        if(v[i] < v[next]){
            if(state == DESCENDING) transitions++;
            state = ASCENDING;
        } else if(v[i] > v[next]){
            if(state == ASCENDING) transitions++;
            state = DESCENDING;
        }

        // If we have exceeded the maximum number of transitions allowed, exit early
        if(transitions > maxTransitions) break;        
    }

    return transitions <= maxTransitions;
}

void test_is_bitonic(std::vector<int> &v, bool expected){
    assert(is_bitonic(v) == expected);
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    test_is_bitonic(myvec, true);

    std::vector<int> myvec1 = {1, 1, 1, 1, 1};  // Yes
    test_is_bitonic(myvec1, true);

    std::vector<int> myvec2 = {3, 4, 5, 2, 2};  // Yes
    test_is_bitonic(myvec2, true);

    std::vector<int> myvec3 = {3, 4, 5, 2, 4};  // No
    test_is_bitonic(myvec3, false);

    std::vector<int> myvec4 = {1, 2, 3, 4, 5};  // Yes
    test_is_bitonic(myvec4, true);

    std::vector<int> myvec5 = {1, 2, 3, 1, 2};  // No
    test_is_bitonic(myvec5, false);

    std::vector<int> myvec6 = {5, 4, 6, 2, 6};  // No
    test_is_bitonic(myvec6, false);

    std::vector<int> myvec7 = {5, 4, 3, 2, 1};  // Yes
    test_is_bitonic(myvec7, true);

    std::vector<int> myvec8 = {5, 4, 3, 2, 6};  // Yes
    test_is_bitonic(myvec8, true);

    std::vector<int> myvec9 = {5, 4, 6, 5, 4};  // No
    test_is_bitonic(myvec9, false);

    std::vector<int> myvec10 = {5, 4, 6, 5, 5};  // Yes
    test_is_bitonic(myvec10, true);

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
