#include "JumpSearch.h"

int JumpSearch::search(const std::vector<int>& vec, int target) {
    numberComparisons = 0;
    
    int n = vec.size();
    int step = std::sqrt(n);
    int prev = 0;
    
    while (prev < n) {
        numberComparisons++;
        if (vec[std::min(step, n) - 1] >= target) {
            break;
        }
        prev = step;
        step += std::sqrt(n);
    }
    
    for (int i = prev; i < std::min(step, n); i++) {
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
