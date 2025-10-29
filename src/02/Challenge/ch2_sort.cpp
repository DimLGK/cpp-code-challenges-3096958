// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>
#include <cassert>

void print_array(int *arr, int n);
void test_sort_array(int *arr, int n);

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
bool sort_array(int *arr, int n){

    // Check for empty or single-element array
    if (arr == NULL) return false;
    if (n < 2) return true;

    // Bubble sort algorithm
    bool sorted = false;
    int temp;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;
            }
        }
        std::cout << "Iteration ended:" << std::endl;
        print_array(arr, n);       
    }

    return true;
}

void print_array(int *arr, int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 7; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};

    test_sort_array(array, len);

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}

void test_sort_array(int *arr, int n){
    // int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};
    // Test that the array is sorted correctly
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort_array(arr, 10);
    for (int i = 0; i < n; i++){
        assert(arr[i] == expected[i]);
    }

    // Test n less than 10
    int expected_partial[] = {0, 1, 2, 3, 4, 5, 6};
    sort_array(arr, 7);
    for (int i = 0; i < 7; i++){
        assert(arr[i] == expected_partial[i]);
    }    

    // Test empty array
    int empty_array[] = {};
    assert(sort_array(empty_array, 0) == true);

    // Test single-element array
    int single_element_array[] = {42};
    assert(sort_array(single_element_array, 1) == true);

}
