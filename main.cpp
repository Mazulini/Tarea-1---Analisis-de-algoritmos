#include <iostream>
#include <vector>
#include <chrono>
#include "include/Mult_matrix_classic.h"
#include "include/Mult_matrix_divide_conquer.h"
#include "include/Mult_matrix_hybrid.h"

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

    // --- 1. DIVIDE & CONQUER ---
    std::cout << "--- PRUEBA DIVIDE & CONQUER (STRASSEN) ---\n";
    Mult_matrix_divide_conquer calc_dc(A, B);

    auto start = std::chrono::high_resolution_clock::now(); 
    std::vector<std::vector<int>> resultado_dc = calc_dc.multiply();
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start; 

    std::cout << "Tiempo de multiplicacion: " << elapsed.count() << " segundos\n\n";
    calc_dc.print_A();
    calc_dc.print_B();
    calc_dc.print_result(resultado_dc);
    std::cout << "\n";

    // --- 2. CLÁSICO ---
    std::cout << "--- PRUEBA CLASICA ---\n";
    Mult_matrix_classic calc_classic(A, B);

    start = std::chrono::high_resolution_clock::now(); 
    std::vector<std::vector<int>> resultado_classic = calc_classic.multiply();
    end = std::chrono::high_resolution_clock::now(); 
    elapsed = end - start; 

    std::cout << "Tiempo de multiplicacion: " << elapsed.count() << " segundos\n\n";
    calc_classic.print_A();
    calc_classic.print_B();
    calc_classic.print_result(resultado_classic);
    std::cout << "\n";

    // --- 3. HÍBRIDO ---
    std::cout << "--- PRUEBA HIBRIDA ---\n";
    int n0 = 0;
    Mult_matrix_hybrid calc_hybrid(A, B, n0);


    start = std::chrono::high_resolution_clock::now(); 
    std::vector<std::vector<int>> resultado_hybrid = calc_hybrid.multiply();
    end = std::chrono::high_resolution_clock::now(); 
    elapsed = end - start; 

    std::cout << "Tiempo de multiplicacion: " << elapsed.count() << " segundos\n\n";
    calc_hybrid.print_A();
    calc_hybrid.print_B();
    calc_hybrid.print_result(resultado_hybrid);
    std::cout << "\n";

    return 0;
}