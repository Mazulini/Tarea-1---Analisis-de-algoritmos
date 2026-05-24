#include <iostream>
#include <vector>
#include <chrono>
#include "Mult_matrix_divide_conquer.h"

int main() {
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    std::vector<std::vector<int>> B = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    Mult_matrix_divide_conquer calculadora(A, B);

    auto start = std::chrono::high_resolution_clock::now(); 

    std::vector<std::vector<int>> resultado = calculadora.multiply();

    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start; 

    std::cout << "Tiempo de multiplicacion: " << elapsed.count() << " segundos\n\n";

    calculadora.print_A();
    calculadora.print_B();
    calculadora.print_result(resultado);

    return 0;
}