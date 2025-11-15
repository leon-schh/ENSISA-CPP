#include "MatrixBase.h"
#include <stdexcept>

MatrixBase::MatrixBase() : rows(0), cols(0) {}

MatrixBase::MatrixBase(size_t rows, size_t cols) 
    : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

MatrixBase::MatrixBase(const std::vector<std::vector<double>>& data) 
    : data(data) {
    rows = data.size();
    cols = (rows > 0) ? data[0].size() : 0;
}

void MatrixBase::addElement(size_t row, size_t col, double value) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index hors limites");
    }
    data[row][col] = value;
}

double MatrixBase::getElement(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index hors limites");
    }
    return data[row][col];
}

size_t MatrixBase::getRows() const {
    return rows;
}

size_t MatrixBase::getCols() const {
    return cols;
}

void MatrixBase::Display(std::ostream& os) const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            os << data[i][j];
            if (j < cols - 1) os << " ";
        }
        os << "\n";
    }
}
