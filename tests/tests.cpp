#include <iostream>
#include <vector>
#include "../include/solver.hpp"


std::vector<std::vector<double>>A;
//std::vector<std::vector<double>>L;
//std::vector<std::vector<double>>U;


void Setmtrx(A){
  //setup matrix values
  // A
  A[0][0]=1;A[0][1]=2;A[0][2]=1;
  A[1][0]=3;A[1][1]=8;A[1][2]=2;
  A[2][0]=0;A[2][1]=4;A[2][2]=9;

  //L
  //L[0][0]=1;L[1][1]=1;//L[2][2]=1;
 
  //U=A;
} 

void Displaymtrx(A){
  for(int i=0; i<row;i++){
    for(int j=0; j<col;j++){
      std::cout<<A[i][j]<<" ";
    }
    std::cout<<"\n";
  }
} 

int main(){
  Gaussian_Elimination(A);
  //ALU(A,L,U);
  return 0;
}  
