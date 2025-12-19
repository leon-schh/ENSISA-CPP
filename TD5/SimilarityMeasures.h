#ifndef SIMILARITYMEASURES_H
#define SIMILARITYMEASURES_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

double euclidean_distance(const std::vector<double>& series1, const std::vector<double>& series2);

double dynamic_time_warping(const std::vector<double>& series1, const std::vector<double>& series2);

#endif