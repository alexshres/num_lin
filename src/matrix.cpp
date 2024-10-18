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
