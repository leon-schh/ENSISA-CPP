#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int>& vec, int target) {
    numberComparisons = 0;
    
    int left = 0;
    int right = vec.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        numberComparisons++;
        if (vec[mid] == target) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return mid;
        }
        
        numberComparisons++;
        if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1;
}
