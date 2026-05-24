#ifndef MULT_MATRIX_HYBRID_H
#define MULT_MATRIX_HYBRID_H

#include <vector>

class Mult_matrix_classic;
class Mult_matrix_divide_conquer;

class Mult_matrix_hybrid {
private:
    std::vector<std::vector<int>> A;
    std::vector<std::vector<int>> B;
    int n0;
public:
    Mult_matrix_hybrid(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, int n0);
    std::vector<std::vector<int>> multiply();
    std::vector<std::vector<int>> hybrid_strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    std::vector<std::vector<int>> add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    std::vector<std::vector<int>> restar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    std::vector<std::vector<int>> inicializar(int length);
    std::vector<std::vector<int>> combine(std::vector<std::vector<int>>& C11, std::vector<std::vector<int>>& C12, std::vector<std::vector<int>>& C21, std::vector<std::vector<int>>& C22);
    void split(const std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& A11, std::vector<std::vector<int>>& A12, std::vector<std::vector<int>>& A21, std::vector<std::vector<int>>& A22);
    void print_A();
    void print_B();
    void print_result(const std::vector<std::vector<int>>& C);
};

#endif