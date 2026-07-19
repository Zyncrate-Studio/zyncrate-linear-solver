#include <iostream>
#include <vector>
#include "../include/solver.hpp"




void Gaussian_Elimination(std::vector<std::vector<double>>& A){
   int multiplier=0;
   for(int i=0;i<row-1;i++){
     for(int j=0; j<col-1;j++){
       if(i==j && A[i][j]!=0){
        // prev=i;
         if(A[i+1][j]!=0 && A[i][j]<A[i+1][j]){
           multiplier=A[i+1][j]/A[i][j];
           // tricky part to carry out the Elimination
           for(int incr=0;j+incr<col;incr++){
             A[i+1][j+incr]= A[i+1][j+incr] - (multiplier*( A[i][j+incr]));
           }
         }else{
           continue;
         }

        }
     }
   }
}


