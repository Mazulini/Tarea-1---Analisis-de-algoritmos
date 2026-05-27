#ifndef RAND_MATRIX_GENERATOR_H
#define RAND_MATRIX_GENERATOR_H

#include <vector>
/**
 * @class Generador de matrices pseudo-aleatorias.
 */
class Rand_matrix_generator{
    public:
        /**
         * @brief Generador de matrices cuadradas con números enteros.
         * @param n Dimensión de la matriz.
         * @param min Valor minimo que puede tener nuestros elementos.
         * @param max Valor máximo que puede tener nuestros elementos.
         * @return Matriz n*n llena. 
         */
        std::vector<std::vector<int>> generarMatrizEnteros(int n, int min, int max);
        
        /**
         * @brief Generador de matrices cuadradas con números decimales.
         * @param n Dimensión de la matriz.
         * @param min Valor minimo que puede tener nuestros elementos.
         * @param max Valor máximo que puede tener nuestros elementos.
         * @return Matriz n*n llena. 
         */
        std::vector<std::vector<double>> generarMatrizDecimales(int n, double min, double max);
        
        /**
         * @brief Generador de matrices cuadradas con números muy grandes (long long).
         * @param n Dimensión de la matriz.
         * @param min Valor minimo que puede tener nuestros elementos.
         * @param max Valor máximo que puede tener nuestros elementos.
         * @return Matriz n*n llena. 
         */
        std::vector<std::vector<long long>> generarMatrizLongLong(int n, long long min, long long max);
        
        /**
         * @brief Generador de matrices triangulares superior.
         * @param n Dimensión de la matriz.
         * @param min Valor minimo que puede tener nuestros elementos.
         * @param max Valor máximo que puede tener nuestros elementos.
         * @return Matriz n*n llena. 
         */
        std::vector<std::vector<int>> generarMatrizTriangularSuperior(int n, int min, int max);
};

#endif
