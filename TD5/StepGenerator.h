#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <random>

class StepGenerator : public TimeSeriesGenerator {
    private:
        std::mt19937 generator;
        std::uniform_real_distribution<double> probability;
        std::uniform_int_distribution<int> valueDistribution;
        
    public:
        StepGenerator();
        StepGenerator(int seed);
        
        std::vector<double> generateTimeSeries(int size) override;
};

#endif