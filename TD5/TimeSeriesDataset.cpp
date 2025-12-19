#include "TimeSeriesDataset.h"

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain) 
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

double TimeSeriesDataset::calculateMean(const std::vector<double>& series) {
    double sum = 0.0;
    for (double value : series) {
        sum += value;
    }
    return sum / series.size();
}

double TimeSeriesDataset::calculateStdDev(const std::vector<double>& series, double mean) {
    double sumSquaredDiff = 0.0;
    for (double value : series) {
        sumSquaredDiff += (value - mean) * (value - mean);
    }
    return std::sqrt(sumSquaredDiff / series.size());
}

std::vector<double> TimeSeriesDataset::normalizeSeries(const std::vector<double>& series) {
    if (!znormalize || series.empty()) {
        return series;
    }
    
    double mean = calculateMean(series);
    double stdDev = calculateStdDev(series, mean);
    
    if (stdDev == 0.0) {
        return series;
    }
    
    std::vector<double> normalizedSeries;
    normalizedSeries.reserve(series.size());
    
    for (double value : series) {
        double normalizedValue = (value - mean) / stdDev;
        normalizedSeries.push_back(normalizedValue);
    }
    
    return normalizedSeries;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> processedSeries = normalizeSeries(series);
    
    data.push_back(processedSeries);
    labels.push_back(label);
    
    if (series.size() > maxLength) {
        maxLength = series.size();
    }
    numberOfSamples++;
}