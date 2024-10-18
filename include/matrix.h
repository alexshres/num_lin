#ifndef MATRIX_H
#define MATRIX_H

#include "Eigen/Dense"
#include <vector>

class Matrix {
    private:
        std::vector<std::vector<double>> data;

    public:
        Matrix(int rows, int cols);
        Matrix(const std::vector<std::vector<double>>& data);


        int rows() const;
        int cols() const;

        std::vector<double>& operator[](int index);
        const std::vector<double>& operator[](int index) const;


        // Basic Operations
        Matrix transpose() const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(double scalar) const;
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;


        // Numerical methods
        bool LU_decomposition(Matrix& L, Matrix& U) const;
        void QR_decomposition(Matrix& Q, Matrix& R) const;
        bool cholesky_decomposition(Matrix& L) const;
        std::vector<double> solve(const std::vector<double>& b) const;
        std::vector<double> JacobiMethod(const std::vector<double>& b, int maxIterations, double tol) const;
        double powerIteration(std::vector<double>& eigenvector, int maxIterations, double tol) const;
        double conditionNumber() const;
};






#endif // MATRIX_H
