#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <cmath>

class SinWaveGenerator : public TimeSeriesGenerator {
    private:
        double amplitude;
        double frequency;
        double phase;
        
    public:
        SinWaveGenerator();
        SinWaveGenerator(double amplitude, double frequency, double phase);
        SinWaveGenerator(int seed, double amplitude, double frequency, double phase);
        
        std::vector<double> generateTimeSeries(int size) override;
        
        void setAmplitude(double amplitude);
        void setFrequency(double frequency);
        void setPhase(double phase);
        
        double getAmplitude() const;
        double getFrequency() const;
        double getPhase() const;
};

#endif