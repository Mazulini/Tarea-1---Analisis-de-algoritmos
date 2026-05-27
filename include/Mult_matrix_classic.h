#ifndef MULT_MATRIX_CLASSIC_H
#define MULT_MATRIX_CLASSIC_H

#include <vector>

/**
 * @class Multiplicación de matrices clásica 
 * @brief Calcula la multiplicación de matrices de manera clásica.
 * 
 * Esta clase es una multiplicacion dem atrices simple, la de toda la vida con una complejidad temporal bastante alta. 
 * Complejidad: O(n³)
 */

class Mult_matrix_classic {
private:
    std::vector<std::vector<int>> A;            // Matriz A
    std::vector<std::vector<int>> B;            // Matriz B

public:
    /**
     * @brief Constructor de la clase.
     * @param A Matriz A.
     * @param B Matriz B.
     */
    Mult_matrix_classic(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    
    /**
     * @brief Función que inicia la multiplicación.
     * @return Matriz C con el resultado de la multiplicación.
     */
    std::vector<std::vector<int>> multiply();

    /**
     * @brief Función que imprime la matriz A.
     */
    void print_A();
    
    /**
     * @brief Función que imprime la matriz B.
     */
    void print_B();
    
    /**
     * @brief Función que imprime la matriz resultante C.
     */
    void print_result(const std::vector<std::vector<int>>& C);
};

#endif