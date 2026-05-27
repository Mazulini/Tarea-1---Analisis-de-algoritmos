#ifndef MULT_MATRIX_DIVIDE_CONQUER_H
#define MULT_MATRIX_DIVIDE_CONQUER_H

#include <vector>


/**
 * @class Multiplicación de Matrices Strassen
 * @brief Multiplicación de matrices usando Divide&Conquer Strassen
 * 
 * Complejidad: O(n^log2(7))
 */
class Mult_matrix_divide_conquer{
    private:
        
        std::vector<std::vector<int>> A;                // Matriz A
        std::vector<std::vector<int>> B;                // Matriz B

        /**
         * @brief Algoritmo Strassen.
         * @param A Matriz A.
         * @param B Matriz B.
         * @return Matriz resultante de la multiplicación C.
         */
        std::vector<std::vector<int>> strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);

        /**
         * @brief Suma de matrices.
         * @param A Matriz A.
         * @param B Matriz B.
         * @return Matriz resultante de la suma C.
         */
        std::vector<std::vector<int>> add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
        
        /**
         * @brief Resta de matrices.
         * @param A Matriz A.
         * @param B Matriz B.
         * @return Matriz resultante de la resta C.
         */
        std::vector<std::vector<int>> restar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
        
        /**
         * @brief Función que crea y retorna una matriz cuadrada de cualquier tamaño
         * @param length Dimensión de la matriz.
         * @return Matriz C cuadrada de dimensiones length*length
         */
        std::vector<std::vector<int>> inicializar(int length);
        
        /**
         * @brief Función para combinar submatrices.
         * @param C11 Matriz C11.
         * @param C12 Matriz C12.
         * @param C21 Matriz C21.
         * @param C22 Matriz C22.
         * @return Matriz C completa.
         */
        std::vector<std::vector<int>>  combine(std::vector<std::vector<int>>& C11, std::vector<std::vector<int>>& C12, std::vector<std::vector<int>>& C21, std::vector<std::vector<int>>& C22);
        
        /**
         * @brief Función para separa una matriz en submatrices.
         * @param A Matriz que va a ser separada.
         * @param A11 Submatriz A11.
         * @param A12 Submatriz A12.
         * @param A21 Submatriz A21.
         * @param A22 Submatriz A22.
         */
        void split(const std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& A11, std::vector<std::vector<int>>& A12, std::vector<std::vector<int>>& A21, std::vector<std::vector<int>>& A22);
    
    public:
        /**
         * @brief Constructor
         * @param A Matriz A.
         * @param B Matriz B.
         */
        Mult_matrix_divide_conquer(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
        
        /**
         * @brief Multiplicación de las matrices
         * 
         * Esta función se encarga de inicializar la multiplicación de la matriz A y B.
         */
        std::vector<std::vector<int>> multiply();

        /**
         * @brief Funcion que imprime la matriz A.
         */
        void print_A();
        
        /**
         * @brief Funcion que imprime la matriz B.
         */
        void print_B(); 

        /**
         * @brief Funcion que imprime la matriz resultante C.
         */
        void print_result(const std::vector<std::vector<int>>& C);
};

#endif