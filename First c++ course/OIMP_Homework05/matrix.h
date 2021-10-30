#include <iostream>

template <typename T>
class Matrix {
private:
    T ** data;
    size_t rows, columns;

public:
    Matrix(size_t m, size_t n): rows(m), columns(n) {
        data = new T * [rows];
        size_t i = 0;
        try {
            for (; i != rows; ++i)
                data[i] = new T[columns];
        } catch (...) {
            for (size_t k = 0; k != i; ++k)
                delete [] data[k];
            delete [] data;
            throw;
        }
    }

    T* operator[](size_t i) {
        return data[i];
    }
    const T* operator[](size_t i) const {
        return data[i];
    }

    size_t GetRows() const {
        return rows;
    }

    size_t GetColumns() const {
        return columns;
    }

    ~Matrix() {
        for (size_t i = 0; i != rows; ++i)
            delete [] data[i];
        delete [] data;
    }

    Matrix<T>& operator=(Matrix<T>&& right) {
        std::swap(data, right.data);
        std::swap(rows, right.rows);
        std::swap(columns, right.columns);
        return *this;
    }

    Matrix<T>(Matrix<T>&& right) {
        data = right.data;
        right.data = nullptr;
        rows = right.rows;
        right.rows = 0;
        columns = right.columns;
        right.columns = 0;
    }

    Matrix<T>(const Matrix<T>& right) = delete;

    Matrix<T>& operator=(const Matrix<T>& right) = delete;
};


template <typename T>
Matrix<T> FillMatrix(size_t m, size_t n) {
    Matrix<T> A(m, n);
    for (size_t i = 0; i != m; ++i)
        for (size_t j = 0; j != n; ++j)
            A[i][j] = i + j;
    return A;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& A) {
    for (size_t i = 0; i != A.GetRows(); ++i) {
        for (size_t j = 0; j != A.GetColumns(); ++j)
            out << A[i][j] << " ";
        out << "\n";
    }
    return out;
}