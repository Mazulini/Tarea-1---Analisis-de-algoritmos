#include <iostream>
#include <vector>
#include <stdexcept>
#include "../include/Mult_matrix_hybrid.h"
#include "../include/Mult_matrix_classic.h"

Mult_matrix_hybrid::Mult_matrix_hybrid(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, int n0) {
    this->A = A;
    this->B = B;
    this->n0 = n0;
}

std::vector<std::vector<int>> Mult_matrix_hybrid::multiply() {
    return hybrid_strassen(this->A, this->B);
}

// Método recursivo para la multiplicación híbrida
std::vector<std::vector<int>> Mult_matrix_hybrid::hybrid_strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();

    // Si la submatriz es menor a n0, resolvemos con el algoritmo clásico
    if (n < n0) {
        Mult_matrix_classic classic(A, B);
        return classic.multiply();
    }

    // Caso base: matriz de dimensiones 1x1.
    if (n == 1) {
        std::vector<std::vector<int>> C(1, std::vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Crear las submatrices
    int mid = n / 2;

    std::vector<std::vector<int>> A11 = inicializar(mid);
    std::vector<std::vector<int>> A12 = inicializar(mid);
    std::vector<std::vector<int>> A21 = inicializar(mid);
    std::vector<std::vector<int>> A22 = inicializar(mid);
    std::vector<std::vector<int>> B11 = inicializar(mid);
    std::vector<std::vector<int>> B12 = inicializar(mid);
    std::vector<std::vector<int>> B21 = inicializar(mid);
    std::vector<std::vector<int>> B22 = inicializar(mid);

    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    // Cálculo de los productos de Strassen
    std::vector<std::vector<int>> M1 = hybrid_strassen(add(A11, A22), add(B11, B22));
    std::vector<std::vector<int>> M2 = hybrid_strassen(add(A21, A22), B11);
    std::vector<std::vector<int>> M3 = hybrid_strassen(A11, restar(B12, B22));
    std::vector<std::vector<int>> M4 = hybrid_strassen(A22, restar(B21, B11));
    std::vector<std::vector<int>> M5 = hybrid_strassen(add(A11, A12), B22);
    std::vector<std::vector<int>> M6 = hybrid_strassen(restar(A21, A11), add(B11, B12));
    std::vector<std::vector<int>> M7 = hybrid_strassen(restar(A12, A22), add(B21, B22));

    // Reconstrucción
    std::vector<std::vector<int>> C11 = add(restar(add(M1, M4), M5), M7);
    std::vector<std::vector<int>> C12 = add(M3, M5);
    std::vector<std::vector<int>> C21 = add(M2, M4);
    std::vector<std::vector<int>> C22 = add(restar(add(M1, M3), M2), M6);

    // Retornar la combinación de las matrices
    return combine(C11, C12, C21, C22);
}


std::vector<std::vector<int>> Mult_matrix_hybrid::inicializar(int length) {
    // Crear una matriz de length*length
    std::vector<std::vector<int>> matrix(length, std::vector<int>(length, 0));
    
    return matrix;
};


std::vector<std::vector<int>> Mult_matrix_hybrid::add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B){
    // Se crea la matriz temp

    std::vector<std::vector<int>> temp = Mult_matrix_hybrid::inicializar(A.size());

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            temp[i][j] = A[i][j] + B[i][j];
        }
    }

    return temp;
};


std::vector<std::vector<int>> Mult_matrix_hybrid::restar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B){
    // Se crea la matriz temp
    std::vector<std::vector<int>> temp = Mult_matrix_hybrid::inicializar(A.size());

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            temp[i][j] = A[i][j] - B[i][j];
        }
    }

    return temp;
};

void Mult_matrix_hybrid::split(const std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& A11, std::vector<std::vector<int>>& A12, std::vector<std::vector<int>>& A21, std::vector<std::vector<int>>& A22){
    int mid = A.size() / 2;

    for(int i = 0; i < mid; i++) {

        for(int j = 0; j < mid; j++) {

            // Superior izquierda
            A11[i][j] = A[i][j];

            // Superior derecha
            A12[i][j] = A[i][j + mid];

            // Inferior izquierda
            A21[i][j] = A[i + mid][j];

            // Inferior derecha
            A22[i][j] = A[i + mid][j + mid];
        }
    }
};

std::vector<std::vector<int>> Mult_matrix_hybrid::combine(std::vector<std::vector<int>>& C11, std::vector<std::vector<int>>& C12, std::vector<std::vector<int>>& C21, std::vector<std::vector<int>>& C22){
    int mid = C11.size();

    int real_length = mid * 2;

    std::vector<std::vector<int>> C = Mult_matrix_hybrid::inicializar(real_length);

    for(int i = 0; i < mid; i++) {

        for(int j = 0; j < mid; j++) {

            // Superior izquierda
            C[i][j] = C11[i][j];

            // Superior derecha
            C[i][j + mid] = C12[i][j];

            // Inferior izquierda
            C[i + mid][j] = C21[i][j];

            // Inferior derecha
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
};
        
void Mult_matrix_hybrid::print_result(const std::vector<std::vector<int>>& C) {
    std::cout << "Matriz resultado (C):\n";
    for (size_t i = 0; i < C.size(); ++i) {
        for (size_t j = 0; j < C[i].size(); ++j) {
            std::cout << C[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Mult_matrix_hybrid::print_A() {
    std::cout << "Matriz A:\n";
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Mult_matrix_hybrid::print_B() {
    std::cout << "Matriz B:\n";
    for (size_t i = 0; i < B.size(); ++i) {
        for (size_t j = 0; j < B[i].size(); ++j) {
            std::cout << B[i][j] << "\t";
        }
        std::cout << "\n";
    }
}