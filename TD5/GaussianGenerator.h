#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <random>
#include <cmath>

class GaussianGenerator : public TimeSeriesGenerator {
    private:
        double mean;
        double stdDev;
        std::mt19937 generator;
        
        double generateGaussianValue();
        
    public:
        GaussianGenerator();
        GaussianGenerator(double mean, double stdDev);
        GaussianGenerator(int seed, double mean, double stdDev);
        
        std::vector<double> generateTimeSeries(int size) override;
        
        void setMean(double mean);
        void setStdDev(double stdDev);
        double getMean() const;
        double getStdDev() const;
};

#endif