#include <iostream>
#include <vector>
#include "../include/solver.hpp"



int main(){

  std::vector<std::vector<double>> A(row, std::vector<double>(col, 0.0));
  A[0][0]=1;A[0][1]=2;A[0][2]=1;
  A[1][0]=3;A[1][1]=8;A[1][2]=2;
  A[2][0]=0;A[2][1]=4;A[2][2]=9;
  Gaussian_Elimination(A);
  //ALU(A,L,U);
  return 0;
}  
