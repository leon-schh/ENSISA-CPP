#include "SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator() 
    : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase) 
    : TimeSeriesGenerator(), amplitude(amplitude), frequency(frequency), phase(phase) {}

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase) 
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> timeSeries;
    timeSeries.reserve(size);
    
    for (int i = 0; i < size; ++i) {
        double value = amplitude * std::sin(frequency * i + phase);
        timeSeries.push_back(value);
    }
    
    return timeSeries;
}

void SinWaveGenerator::setAmplitude(double amplitude) {
    this->amplitude = amplitude;
}

void SinWaveGenerator::setFrequency(double frequency) {
    this->frequency = frequency;
}

void SinWaveGenerator::setPhase(double phase) {
    this->phase = phase;
}

double SinWaveGenerator::getAmplitude() const {
    return amplitude;
}

double SinWaveGenerator::getFrequency() const {
    return frequency;
}

double SinWaveGenerator::getPhase() const {
    return phase;
}