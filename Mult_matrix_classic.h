#ifndef MULT_MATRIX_CLASSIC_H
#define MULT_MATRIX_CLASSIC_H

#include <vector>

class Mult_matrix_classic {
private:
    std::vector<std::vector<int>> A;
    std::vector<std::vector<int>> B;

public:
    Mult_matrix_classic(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    std::vector<std::vector<int>> multiply();
    void print_A();
    void print_B(); 
    void print_result(const std::vector<std::vector<int>>& C);
};

#endif