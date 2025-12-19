#include "SimilarityMeasures.h"
#include <stdexcept>

double euclidean_distance(const std::vector<double>& series1, const std::vector<double>& series2) {
    if (series1.size() != series2.size()) {
        throw std::invalid_argument("Series must have the same length for euclidean distance");
    }
    
    double sum = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        double diff = series1[i] - series2[i];
        sum += diff * diff;
    }
    
    return std::sqrt(sum);
}

double dynamic_time_warping(const std::vector<double>& series1, const std::vector<double>& series2) {
    int n = series1.size();
    int m = series2.size();
    
    std::vector<std::vector<double>> dtw(n + 1, std::vector<double>(m + 1, 
        std::numeric_limits<double>::infinity()));
    
    dtw[0][0] = 0.0;
    
    for (int i = 1; i <= n; ++i) {
        dtw[i][0] = std::numeric_limits<double>::infinity();
    }
    for (int j = 1; j <= m; ++j) {
        dtw[0][j] = std::numeric_limits<double>::infinity();
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            double cost = std::pow(series1[i-1] - series2[j-1], 2);
            dtw[i][j] = cost + std::min({
                dtw[i-1][j],
                dtw[i][j-1],
                dtw[i-1][j-1]
            });
        }
    }
    
    return std::sqrt(dtw[n][m]);
}