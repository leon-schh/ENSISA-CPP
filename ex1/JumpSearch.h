#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "SearchingAlgorithm.h"
#include <cmath>

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vec, int target) override;
};

#endif
