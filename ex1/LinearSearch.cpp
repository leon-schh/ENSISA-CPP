#include "LinearSearch.h"

int LinearSearch::search(const std::vector<int>& vec, int target) {
    numberComparisons = 0;
    
    for (size_t i = 0; i < vec.size(); i++) {
        numberComparisons++;
        if (vec[i] == target) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return i;
        }
    }
    
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1;
}
