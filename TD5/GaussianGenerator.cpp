#include "GaussianGenerator.h"

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), stdDev(1.0), generator(std::random_device{}()) {}

GaussianGenerator::GaussianGenerator(double mean, double stdDev) 
    : TimeSeriesGenerator(), mean(mean), stdDev(stdDev), generator(std::random_device{}()) {}

GaussianGenerator::GaussianGenerator(int seed, double mean, double stdDev) 
    : TimeSeriesGenerator(seed), mean(mean), stdDev(stdDev), generator(seed) {}

double GaussianGenerator::generateGaussianValue() {
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    
    double u1 = uniform(generator);
    double u2 = uniform(generator);
    
    if (u1 < 1e-12) {
        u1 = 1e-12;
    }
    
    double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
    
    return mean + stdDev * z0;
}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> timeSeries;
    timeSeries.reserve(size);
    
    for (int i = 0; i < size; ++i) {
        timeSeries.push_back(generateGaussianValue());
    }
    
    return timeSeries;
}

void GaussianGenerator::setMean(double mean) {
    this->mean = mean;
}

void GaussianGenerator::setStdDev(double stdDev) {
    this->stdDev = stdDev;
}

double GaussianGenerator::getMean() const {
    return mean;
}

double GaussianGenerator::getStdDev() const {
    return stdDev;
}