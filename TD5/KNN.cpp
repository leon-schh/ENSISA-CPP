#include "KNN.h"
#include <stdexcept>

KNN::KNN(int k, const std::string& similarity_measure) : k(k), similarity_measure(similarity_measure) {}

double KNN::calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) {
    if (similarity_measure == "euclidean_distance") {
        return euclidean_distance(series1, series2);
    } else if (similarity_measure == "dtw") {
        return dynamic_time_warping(series1, series2);
    } else {
        throw std::invalid_argument("Unknown similarity measure: " + similarity_measure);
    }
}

int KNN::predictLabel(const std::vector<double>& testSeries, const TimeSeriesDataset& trainData) {
    const auto& trainData_vec = trainData.getData();
    const auto& trainLabels = trainData.getLabels();
    
    std::vector<std::pair<double, int>> distances;
    distances.reserve(trainData_vec.size());
    
    for (size_t i = 0; i < trainData_vec.size(); ++i) {
        double distance = calculateDistance(testSeries, trainData_vec[i]);
        distances.push_back(std::make_pair(distance, trainLabels[i]));
    }
    
    std::sort(distances.begin(), distances.end(), 
              [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
                  return a.first < b.first;
              });
    
    std::map<int, int> votes;
    for (int i = 0; i < k && i < (int)distances.size(); ++i) {
        votes[distances[i].second]++;
    }
    
    int predictedLabel = distances[0].second;
    int maxVotes = -1;
    
    for (const auto& vote : votes) {
        if (vote.second > maxVotes) {
            maxVotes = vote.second;
            predictedLabel = vote.first;
        }
    }
    
    return predictedLabel;
}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& ground_truth) {
    const auto& testData_vec = testData.getData();
    
    if (testData_vec.size() != ground_truth.size()) {
        throw std::invalid_argument("Test data size must match ground truth size");
    }
    
    int correctPredictions = 0;
    int totalPredictions = testData_vec.size();
    
    for (size_t i = 0; i < testData_vec.size(); ++i) {
        int predictedLabel = predictLabel(testData_vec[i], trainData);
        if (predictedLabel == ground_truth[i]) {
            correctPredictions++;
        }
    }
    
    return static_cast<double>(correctPredictions) / totalPredictions;
}