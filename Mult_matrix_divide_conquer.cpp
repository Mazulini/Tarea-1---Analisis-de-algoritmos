#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
#include "Mult_matrix_divide_conquer.h"

Mult_matrix_divide_conquer::Mult_matrix_divide_conquer(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    this->A = A;
    this->B = B;
};

// Inicializador
std::vector<std::vector<int>> Mult_matrix_divide_conquer::multiply(){
    return strassen(this->A, this->B);
}


/*
---------------- Algoritmo de Strassen --------------------------

idea es dividir la matrix en 4 matrices.

A = [ 0 1 ]                 A11 = [0], A12 = [1]
    [ 2 3 ]                 A21 = [2], A22 = [3]

Lo mismo con B para despues calcular 7 multiplicaciones:
P1, P2, P3, P4, P5, P6, P7 y combinar todas esas combinaciones en un C.

*/

std::vector<std::vector<int>> Mult_matrix_divide_conquer::strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    // Validar si es matriz unitaria pa, caso base :v
    if (A.size() == 1){
        std::vector<std::vector<int>> C(1, std::vector<int>(1));        // Matriz de 1x1
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Encontrar mitad
    std::vector<std::vector<int>> C = Mult_matrix_divide_conquer::inicializar(A.size());
    int mid = A.size() / 2;                                             // Son base 2, entonces no hay que preocuparse, leer enunciado

    // Creacion de las matrices TA RE FEO
    std::vector<std::vector<int>> A11 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> A12 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> A21 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> A22 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> B11 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> B12 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> B21 = Mult_matrix_divide_conquer::inicializar(mid);
    std::vector<std::vector<int>> B22 = Mult_matrix_divide_conquer::inicializar(mid);

    // Dividir las partes
    Mult_matrix_divide_conquer::split(A, A11, A12, A21, A22);
    Mult_matrix_divide_conquer::split(B, B11, B12, B21, B22);

    // Se supone que ahora viene la multiplicación de las matrices
    std::vector<std::vector<int>> M1 = Mult_matrix_divide_conquer::strassen(Mult_matrix_divide_conquer::add(A11, A22), Mult_matrix_divide_conquer::add(B11, B22));
    std::vector<std::vector<int>> M2 = Mult_matrix_divide_conquer::strassen(Mult_matrix_divide_conquer::add(A21,A22), B11);
    std::vector<std::vector<int>> M3 = Mult_matrix_divide_conquer::strassen(A11, Mult_matrix_divide_conquer::restar(B12, B22));
    std::vector<std::vector<int>> M4 = Mult_matrix_divide_conquer::strassen(A22, Mult_matrix_divide_conquer::restar(B21, B11));
    std::vector<std::vector<int>> M5 = Mult_matrix_divide_conquer::strassen(Mult_matrix_divide_conquer::add(A11, A12), B22);
    std::vector<std::vector<int>> M6 = Mult_matrix_divide_conquer::strassen(Mult_matrix_divide_conquer::restar(A21, A11), Mult_matrix_divide_conquer::add(B11, B12));
    std::vector<std::vector<int>> M7 = Mult_matrix_divide_conquer::strassen(Mult_matrix_divide_conquer::restar(A12, A22), Mult_matrix_divide_conquer::add(B21, B22));

    // Reconstruccion
    std::vector<std::vector<int>> C11 = Mult_matrix_divide_conquer::add(Mult_matrix_divide_conquer::restar(Mult_matrix_divide_conquer::add(M1, M4), M5), M7);
    std::vector<std::vector<int>> C12 = Mult_matrix_divide_conquer::add(M3, M5);
    std::vector<std::vector<int>> C21 = Mult_matrix_divide_conquer::add(M2, M4);
    std::vector<std::vector<int>> C22 = Mult_matrix_divide_conquer::add(Mult_matrix_divide_conquer::restar(Mult_matrix_divide_conquer::add(M1, M3), M2), M6);

    // Arrojar C
    return Mult_matrix_divide_conquer::combine(C11, C12, C21, C22);
};

/*
Solo crea una matrix de tamaño NxN
*/
std::vector<std::vector<int>> Mult_matrix_divide_conquer::inicializar(int length) {
    std::vector<std::vector<int>> matrix(length, std::vector<int>(length, 0));
    return matrix;
};

    /*
    Suma de matrices
    */
    std::vector<std::vector<int>> Mult_matrix_divide_conquer::add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B){
        // Se crea la matriz temp

        std::vector<std::vector<int>> temp = Mult_matrix_divide_conquer::inicializar(A.size());

        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp[i].size(); j++) {
                temp[i][j] = A[i][j] + B[i][j];
            }
        }

        return temp;
    };

/*
Resta de matrices
*/
std::vector<std::vector<int>> Mult_matrix_divide_conquer::restar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B){
    // Se crea la matriz temp
    std::vector<std::vector<int>> temp = Mult_matrix_divide_conquer::inicializar(A.size());

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            temp[i][j] = A[i][j] - B[i][j];
        }
    }

    return temp;
};

void Mult_matrix_divide_conquer::split(const std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& A11, std::vector<std::vector<int>>& A12, std::vector<std::vector<int>>& A21, std::vector<std::vector<int>>& A22){
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

std::vector<std::vector<int>> Mult_matrix_divide_conquer::combine(std::vector<std::vector<int>>& C11, std::vector<std::vector<int>>& C12, std::vector<std::vector<int>>& C21, std::vector<std::vector<int>>& C22){
    int mid = C11.size();

    int real_length = mid * 2;

    std::vector<std::vector<int>> C = Mult_matrix_divide_conquer::inicializar(real_length);

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
        
void Mult_matrix_divide_conquer::print_result(const std::vector<std::vector<int>>& C) {
    std::cout << "Matriz resultado (C):\n";
    for (size_t i = 0; i < C.size(); ++i) {
        for (size_t j = 0; j < C[i].size(); ++j) {
            std::cout << C[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Mult_matrix_divide_conquer::print_A() {
    std::cout << "Matriz A:\n";
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Mult_matrix_divide_conquer::print_B() {
    std::cout << "Matriz B:\n";
    for (size_t i = 0; i < B.size(); ++i) {
        for (size_t j = 0; j < B[i].size(); ++j) {
            std::cout << B[i][j] << "\t";
        }
        std::cout << "\n";
    }
}