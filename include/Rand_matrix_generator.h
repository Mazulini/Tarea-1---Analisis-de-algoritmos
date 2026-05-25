#ifndef RAND_MATRIX_GENERATOR_H
#define RAND_MATRIX_GENERATOR_H

#include <vector>

class Rand_matrix_generator{
    public:
        std::vector<std::vector<int>> generarMatrizEnteros(int n, int min, int max);
        std::vector<std::vector<double>> generarMatrizDecimales(int n, double min, double max);
        std::vector<std::vector<long long>> generarMatrizLongLong(int n, long long min, long long max);
        std::vector<std::vector<int>> generarMatrizTriangularSuperior(int n, int min, int max);
};

#endif
