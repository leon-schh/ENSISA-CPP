#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

class TimeSeriesDataset {
    private:
        bool znormalize;
        bool isTrain;
        std::vector<std::vector<double>> data;
        std::vector<int> labels;
        int maxLength;
        int numberOfSamples;
        
    public:
        TimeSeriesDataset(bool znormalize = false, bool isTrain = true);
        
        void addTimeSeries(const std::vector<double>& series, int label);
        
        const std::vector<std::vector<double>>& getData() const { return data; }
        const std::vector<int>& getLabels() const { return labels; }
        bool getZNormalize() const { return znormalize; }
        bool getIsTrain() const { return isTrain; }
        int getMaxLength() const { return maxLength; }
        int getNumberOfSamples() const { return numberOfSamples; }
        
        void setZNormalize(bool znormalize) { this->znormalize = znormalize; }
        void setIsTrain(bool isTrain) { this->isTrain = isTrain; }
};

#endif