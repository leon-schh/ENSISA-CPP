#include "StepGenerator.h"

StepGenerator::StepGenerator() 
    : TimeSeriesGenerator(), generator(std::random_device{}()), 
      probability(0.0, 1.0), valueDistribution(0, 100) {}

StepGenerator::StepGenerator(int seed) 
    : TimeSeriesGenerator(seed), generator(seed), 
      probability(0.0, 1.0), valueDistribution(0, 100) {}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> timeSeries;
    timeSeries.reserve(size);
    
    if (size == 0) {
        return timeSeries;
    }
    
    timeSeries.push_back(0.0);
    int previousValue = 0;
    
    for (int i = 1; i < size; ++i) {
        double randomProb = probability(generator);
        
        if (randomProb < 0.5) {
            timeSeries.push_back(previousValue);
        } else {
            previousValue = valueDistribution(generator);
            timeSeries.push_back(previousValue);
        }
    }
    
    return timeSeries;
}