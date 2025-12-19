#include "TimeSeriesGenerator.h"
#include <iomanip>

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {}

void TimeSeriesGenerator::setSeed(int seed) {
    this->seed = seed;
}

int TimeSeriesGenerator::getSeed() const {
    return seed;
}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (size_t i = 0; i < series.size(); ++i) {
        std::cout << std::fixed << std::setprecision(6) << series[i];
        if (i < series.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}