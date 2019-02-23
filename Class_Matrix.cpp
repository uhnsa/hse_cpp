#include <vector>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <utility>

using i32 = int32_t;

template <typename T>
class Matrix {
public:
    Matrix() = default;

    Matrix(const std::vector<std::vector<T>>& other)
    : row_{other.size()}, column_{other.front().size()}
    {
        matrix_.reserve(row_ * column_);
        for (const auto& row : other) {
            for (const auto& element : row) {
                matrix_.push_back(element);
            }
        }
    }

    const T& operator[] (size_t row) const {
        return matrix_[row];
    }

    T& operator[] (size_t row) {
        return matrix_[row];
    }

    const std::pair<size_t, size_t> size() const {
        return {row_, column_};
    }

    Matrix& operator += (const Matrix& other) {
        for (size_t i = 0; i < row_ * column_; ++i) {
            matrix_[i] += other[i];
        }
        return *this;
    }

    template <typename V>
    Matrix& operator *= (const V& value) {
        for (size_t i = 0; i < row_ * column_; ++i) {
            matrix_[i] *= value;
        }
        return *this;
    }

    Matrix& operator *= (const Matrix& other) {
        assert(column_ == other.size().first);
        Matrix transpose_other = other.transposed();
        Matrix new_matrix;
        new_matrix.matrix_.resize(row_ * other.size().second);
        size_t number = 0;
        for (size_t i = 0; i < row_; ++i) {
            for (size_t j = 0; j < other.size().second; ++j) {
                for (size_t k = 0; k < column_; ++k) {
                    new_matrix[number] +=
                    matrix_[k + column_ * i] * transpose_other[k + column_ * j];
                }
                ++number;
            }
        }
        matrix_ = std::move(new_matrix.matrix_);
        column_ = other.size().second;
        return *this;
    }

    Matrix& transpose() {
        Matrix transpose_matrix;
        transpose_matrix.matrix_.reserve(column_ * row_);
        for (size_t i = 0; i < column_; ++i) {
            for (size_t j = 0; j < row_; ++j) {
                transpose_matrix.matrix_.push_back(matrix_[i + column_ * j]);
            }
        }
        matrix_ = std::move(transpose_matrix.matrix_);
        std::swap(row_, column_);
        return *this;
    }

    Matrix transposed() const {
        Matrix transposed_matrix;
        transposed_matrix.matrix_ = matrix_;
        transposed_matrix.row_ = row_;
        transposed_matrix.column_ = column_;
        transposed_matrix.transpose();
        return transposed_matrix;
    }

    typename std::vector<T>::iterator begin() {
        return matrix_.begin();
    }

    typename std::vector<T>::const_iterator begin() const {
        return matrix_.begin();
    }

    typename std::vector<T>::const_iterator cbegin() const {
        return matrix_.cbegin();
    }

    typename std::vector<T>::iterator end() {
        return matrix_.end();
    }

    typename std::vector<T>::const_iterator end() const {
        return matrix_.end();
    }

    typename std::vector<T>::const_iterator cend() const {
        return matrix_.cend();
    }

private:
    size_t row_{0};
    size_t column_{0};
    std::vector<T> matrix_;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.size().first * matrix.size().second; ++i) {
        if (i % matrix.size().second == 0 && i != 0) {
            out << '\n';
        }
        if (i % matrix.size().second) {
            out << '\t';
        }
        out << matrix[i];
    }
    return out;
}

template <typename T>
Matrix<T> operator + (const Matrix<T>& first, const Matrix<T>& second) {
    Matrix<T> new_matrix = first;
    new_matrix += second;
    return new_matrix;
}

template <typename T, typename V>
Matrix<T> operator * (const Matrix<T>& matrix, const V& value) {
    Matrix<T> new_matrix = matrix;
    new_matrix *= value;
    return new_matrix;
}

template <typename T>
Matrix<T> operator * (const Matrix<T>& first, const Matrix<T>& second) {
    Matrix<T> new_matrix = first;
    new_matrix *= second;
    return new_matrix;
}
