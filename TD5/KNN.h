#ifndef KNN_H
#define KNN_H

#include "TimeSeriesDataset.h"
#include "SimilarityMeasures.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

class KNN {
    private:
        int k;
        std::string similarity_measure;
        
        double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2);
        int predictLabel(const std::vector<double>& testSeries, const TimeSeriesDataset& trainData);
        
    public:
        KNN(int k, const std::string& similarity_measure);
        
        double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& ground_truth);
        
        int getK() const { return k; }
        std::string getSimilarityMeasure() const { return similarity_measure; }
};

#endif