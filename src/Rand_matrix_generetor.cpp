#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include "../include/Rand_matrix_generator.h"

// Genera enteros (ej: entre 1 y 100)
std::vector<std::vector<int>> Rand_matrix_generator :: generarMatrizEnteros(int n, int min, int max) {
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = dist(gen);
        }
    }
    return matriz;
}

// Genera decimales (ej: entre 0.0 y 1.0)
std::vector<std::vector<double>> Rand_matrix_generator :: generarMatrizDecimales(int n, double min, double max) {
    std::vector<std::vector<double>> matriz(n, std::vector<double>(n));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min, max);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = dist(gen);
        }
    }
    return matriz;
}

// Genera enteros largos (long long)
std::vector<std::vector<long long>> Rand_matrix_generator :: generarMatrizLongLong(int n, long long min, long long max) {
    std::vector<std::vector<long long>> matriz(n, std::vector<long long>(n));
    std::random_device rd;
    
    // Usamos la versión de 64 bits del motor Mersenne Twister para long long
    std::mt19937_64 gen(rd()); 
    std::uniform_int_distribution<long long> dist(min, max);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = dist(gen);
        }
    }
    return matriz;
}

std::vector<std::vector<int>> Rand_matrix_generator :: generarMatrizTriangularSuperior(int n, int min, int max) {
    // Inicializamos la matriz directamente llenando todas las celdas con 0
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n, 0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    // Llenamos solo la parte superior (incluyendo la diagonal)
    for (int i = 0; i < n; ++i) {
        // Fíjate que 'j' empieza en 'i' en lugar de 0
        for (int j = i; j < n; ++j) {
            matriz[i][j] = dist(gen);
        }
    }
    return matriz;
}
/*
    std::vector<std::vector<int>> matrizA = generarMatrizEnteros(n, 1, 100);
    std::vector<std::vector<double>> matrizB = generarMatrizDecimales(n, 0.0, 1.0);
    std::vector<std::vector<long long>> matrizLL = generarMatrizLongLong(n, 1LL, 9000000000000000000LL);
    td::vector<std::vector<double>> matrizSuperior = generarMatrizTriangularSuperior(n, -10.0, 10.0);
*/