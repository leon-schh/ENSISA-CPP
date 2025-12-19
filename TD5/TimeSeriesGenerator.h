#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>

class TimeSeriesGenerator {
    protected:
        int seed;
    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int seed);

        virtual ~TimeSeriesGenerator() = default;
        virtual std::vector<double> generateTimeSeries(int size) = 0;

        static void printTimeSeries(const std::vector<double>& series);
        
        void setSeed(int seed);
        int getSeed() const;
};

#endif