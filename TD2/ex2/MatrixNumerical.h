#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template<typename T>
class MatrixNumerical : public MatrixBase {
private:
    std::vector<std::vector<T>> numData;

public:
    MatrixNumerical();
    MatrixNumerical(size_t rows, size_t cols);
    MatrixNumerical(const std::vector<std::vector<T>>& data);

    void addElement(size_t row, size_t col, T value);
    T getElement(size_t row, size_t col) const;

    double getDeterminant() const override;
    
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    
    // 
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;

    MatrixNumerical<T> getInverse() const;

    static MatrixNumerical<T> getIdentity(size_t size);

    void Display(std::ostream& os) const override;

private:
    MatrixNumerical<T> getCofactor(size_t p, size_t q, size_t n) const;
    double determinantHelper(size_t n) const;
    MatrixNumerical<T> adjugate() const;
};

#endif
