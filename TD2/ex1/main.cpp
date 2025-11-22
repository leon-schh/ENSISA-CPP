#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;
    
    // Test Linear Search
    LinearSearch linear;
    int result = linear.search(vec, target);
    linear.displaySearchResults(std::cout, result, target);
    std::cout << "\n";
    
    // Test Jump Search
    JumpSearch jump;
    result = jump.search(vec, target);
    jump.displaySearchResults(std::cout, result, target);
    std::cout << "\n";
    
    // Test Binary Search
    BinarySearch binary;
    result = binary.search(vec, target);
    binary.displaySearchResults(std::cout, result, target);
    
    return 0;
}
