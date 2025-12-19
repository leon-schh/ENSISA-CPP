#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include <vector>
#include <iostream>

class StepGenerator {
    public:
        StepGenerator();
        
        virtual std::vector<double> generateTimeSeries(int size);
        
        static void printTimeSeries(const std::vector<double>& series);
};

#endif