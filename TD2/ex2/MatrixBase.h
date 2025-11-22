#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <iostream>

class MatrixBase {
protected:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t rows, size_t cols);
    MatrixBase(const std::vector<std::vector<double>>& data);

    void addElement(size_t row, size_t col, double value);
    double getElement(size_t row, size_t col) const;

    size_t getRows() const;
    size_t getCols() const;

    virtual void Display(std::ostream& os) const;
    
    virtual double getDeterminant() const = 0;
    
    virtual ~MatrixBase() = default;
};

#endif
