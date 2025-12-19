#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include <vector>
#include <iostream>

class GaussianGenerator {
    public:
        GaussianGenerator();
        
        virtual std::vector<double> generateTimeSeries(int size);
        
        static void printTimeSeries(const std::vector<double>& series);
};

#endif