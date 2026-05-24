#include <iostream>
#include <vector>
#include <chrono>
#include "Mult_matrix_classic.h"

int main() {
    std::vector<std::vector<int>> A = {{1, 1}, {1, 1}};
    std::vector<std::vector<int>> B = {{1, 1}, {1, 1}};

    Mult_matrix_classic calculadora(A, B);

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