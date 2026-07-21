#pragma once 
#include <vector>


inline int row=3;
inline int col=3;

void Gaussian_Elimination(std::vector<std::vector<double>>&A);
void ALU(std::vector<std::vector<double>>&A);
void Optimized_ALU(std::vector<double>& A, std::vector<double>& L, std::vector<double>& U);
void PALU(std::vector<double>&A);