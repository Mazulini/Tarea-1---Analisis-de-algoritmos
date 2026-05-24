#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
#include "Mult_matrix_classic.h"

Mult_matrix_classic::Mult_matrix_classic(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    this->A = A;
    this->B = B;
}

std::vector<std::vector<int>> Mult_matrix_classic::multiply() {
    int n1, n2, n3, n4;
    n1 = A.size();
    n2 = A[0].size();
    n3 = B.size();
    n4 = B[0].size();

    if (n2 != n3) {
        throw std::invalid_argument("El numero de columnas de A debe ser igual al numero de filas de B.");
    }

    std::vector<std::vector<int>> C;
    C.resize(n1, std::vector<int>(n4, 0));

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n4; ++j) {
            for (int k = 0; k < n2; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

void Mult_matrix_classic::print_result(const std::vector<std::vector<int>>& C) {
    std::cout << "Matriz resultado (C):\n";
    for (size_t i = 0; i < C.size(); ++i) {
        for (size_t j = 0; j < C[i].size(); ++j) {
            std::cout << C[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Mult_matrix_classic::print_A() {
    std::cout << "Matriz A:\n";
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Mult_matrix_classic::print_B() {
    std::cout << "Matriz B:\n";
    for (size_t i = 0; i < B.size(); ++i) {
        for (size_t j = 0; j < B[i].size(); ++j) {
            std::cout << B[i][j] << "\t";
        }
        std::cout << "\n";
    }
}