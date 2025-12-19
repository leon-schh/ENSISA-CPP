#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include <vector>
#include <iostream>

class SinWaveGenerator {
    private:
        double amplitude;
        double frequency;
        double phase;
        
    public:
        SinWaveGenerator();
        SinWaveGenerator(double amplitude, double frequency, double phase);
        
        virtual std::vector<double> generateTimeSeries(int size);
        
        static void printTimeSeries(const std::vector<double>& series);
        
        void setAmplitude(double amplitude);
        void setFrequency(double frequency);
        void setPhase(double phase);
        
        double getAmplitude() const;
        double getFrequency() const;
        double getPhase() const;
};

#endif