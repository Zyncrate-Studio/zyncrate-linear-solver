#include <iostream>
#include <vector>
#include "../include/solver.hpp"



int main(){

  std::vector<double>A(row*col, 0.0);
  A[0]=0;A[1]=2;A[2]=1;
  A[3]=3;A[4]=7;A[5]=13;
  A[6]=1;A[7]=1;A[8]=5;
  //Gaussian_Elimination(A);
  //ALU(A,L,U);
  PALU(A);
  return 0;
}  
