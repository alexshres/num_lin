#include "matrix.h"

Matrix::Matrix(int rows, int cols): data(rows, std::vector<double>(cols, 0)) {}

Matrix::Matrix(const std::vector<std::vector<double>>& data): data(data) {}

int Matrix::rows() const {return data.size();}

int Matrix::cols() const {return data[0].size();}

std::vector<double>& Matrix::operator[](int index) {return data[index];}

const std::vector<double>& Matrix::operator[](int index) const {return data[index];}


Matrix Matrix::transpose() const {
    int r = rows();
    int c = cols();

    Matrix result(c, r);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            result[j][i] = data[i][j];
    }

    return result;
}


bool Matrix::LU_Decomposition(Matrix& L, Matrix& U) const {
    int n = rows();
    if (n != cols())
        throw std::invalid_argument("Matrix must be square for LU decomposition\n");

    L = Matrix(n, n);
    U = Matrix(n, n);

    for (int i = 0; i < n; ++i) {
        // Upper traingular portion
        for (int k = i; k < n; k++) {
            double sum = 0;

            for (int j = 0; j < i; ++j)
                sum += L.data[i][j] * U.data[j][k];

            U.data[i][k] = data[i][k] - sum;
        }


        // Lower traingular
        for (int k = i; k < n; ++k) {
            if (i == k)
                L.data[i][i] = 1;
            else {
                double sum = 0;

                for (int j = 0; j < i; ++j) 
                    sum += L.data[k][j] * U.data[j][i];

                if (U.data[i][i] == 0)
                    return false;   // Singular matrix
                L.data[k][i] = (data[k][i]-sum) / U.data[i][i];
            }
        }
    }

    return true;
}
