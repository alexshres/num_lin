#include <iostream>
#include "Eigen/Dense"
#include "matrix.h"


void pprintMat(const Matrix& amatrix);

int main()
{
    
    std::vector<std::vector<double>> mat = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };

    Matrix my_matrix(mat);

    std::cout << "Original matrix: \n";

    pprintMat(my_matrix);

    Matrix result = my_matrix.transpose();


    std::cout << "Original matrix transposed: \n";
    pprintMat(result);

    return 0;
}

void pprintMat(const Matrix& amatrix)
{
    for (int r = 0; r < amatrix.rows(); ++r) {
        std::cout << "[";

        for (int c = 0; c < amatrix.cols(); ++c) {
            std::cout << amatrix[r][c];

            if (c != amatrix.rows() - 1) 
                std::cout << ", ";
        }

        std::cout << "]" << std::endl;
    }

    return;
}

