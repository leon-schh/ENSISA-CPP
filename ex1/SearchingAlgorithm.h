#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <vector>
#include <iostream>

class SearchingAlgorithm {
protected: 
    int numberComparisons;

public:
    SearchingAlgorithm();

    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

    virtual int search(const std::vector<int>& vec, int target) = 0;
    void displaySearchResults(std::ostream& os, int result, int target);
    virtual ~SearchingAlgorithm() = default;
};

#endif
