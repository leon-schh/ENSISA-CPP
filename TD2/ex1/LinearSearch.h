#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vec, int target) override;
};

#endif
