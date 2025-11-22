#include "MatrixNumerical.h"
#include <stdexcept>
#include <cmath>

template<typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase() {}

template<typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols) 
    : MatrixBase(rows, cols), numData(rows, std::vector<T>(cols, T(0))) {}

template<typename T>
MatrixNumerical<T>::MatrixNumerical(const std::vector<std::vector<T>>& data) 
    : MatrixBase(data.size(), data.size() > 0 ? data[0].size() : 0), numData(data) {}

template<typename T>
void MatrixNumerical<T>::addElement(size_t row, size_t col, T value) {
    numData[row][col] = value;
}

template<typename T>
T MatrixNumerical<T>::getElement(size_t row, size_t col) const {
    return numData[row][col];
}

template<typename T>
void MatrixNumerical<T>::Display(std::ostream& os) const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            os << numData[i][j];
            if (j < cols - 1) os << " ";
        }
        os << "\n";
    }
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCofactor(size_t p, size_t q, size_t n) const {
    MatrixNumerical<T> temp(n - 1, n - 1);
    size_t i_temp = 0, j_temp = 0;
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i != p && j != q) {
                temp.numData[i_temp][j_temp++] = numData[i][j];
                if (j_temp == n - 1) {
                    j_temp = 0;
                    i_temp++;
                }
            }
        }
    }
    return temp;
}

template<typename T>
double MatrixNumerical<T>::determinantHelper(size_t n) const {
    if (n == 1) {
        return numData[0][0];
    }
    if (n == 2) {
        return numData[0][0] * numData[1][1] - numData[0][1] * numData[1][0];
    }
    
    double det = 0;
    int sign = 1;
    
    for (size_t f = 0; f < n; f++) {
        MatrixNumerical<T> temp = getCofactor(0, f, n);
        det += sign * numData[0][f] * temp.determinantHelper(n - 1);
        sign = -sign;
    }
    
    return det;
}

template<typename T>
double MatrixNumerical<T>::getDeterminant() const {
    return determinantHelper(rows);
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::adjugate() const {
    
    MatrixNumerical<T> adj(rows, cols);
    
    if (rows == 1) {
        adj.numData[0][0] = 1;
        return adj;
    }
    
    int sign = 1;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            MatrixNumerical<T> temp = getCofactor(i, j, rows);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj.numData[j][i] = sign * temp.determinantHelper(rows - 1);
        }
    }
    
    return adj;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    double det = getDeterminant();
    
    MatrixNumerical<T> adj = adjugate();
    MatrixNumerical<T> inverse(rows, cols);
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            inverse.numData[i][j] = adj.numData[i][j] / det;
        }
    }
    
    return inverse;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    
    MatrixNumerical<T> result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.numData[i][j] = numData[i][j] + other.numData[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    
    MatrixNumerical<T> result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.numData[i][j] = numData[i][j] - other.numData[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) const {
    
    MatrixNumerical<T> result(rows, other.cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            T sum = 0;
            for (size_t k = 0; k < cols; k++) {
                sum += numData[i][k] * other.numData[k][j];
            }
            result.numData[i][j] = sum;
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& other) const {
    return (*this) * other.getInverse();
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size) {
    MatrixNumerical<T> identity(size, size);
    for (size_t i = 0; i < size; i++) {
        identity.numData[i][i] = 1;
    }
    return identity;
}

template class MatrixNumerical<int>;
template class MatrixNumerical<double>;
template class MatrixNumerical<float>;
