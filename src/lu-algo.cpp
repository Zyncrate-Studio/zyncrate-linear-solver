#include <iostream>
#include "../include/solver.hpp"
#include <vector>


void ALU(std::vector<std::vector<double>>&A,std::vector<std::vector<double>>&L,std::vector<std::vector<double>>&U){   

  // Elimination Algo
 //int prev=0;
 int multiplier=0;
 for(int i=0;i<row-1;i++){
   for(int j=0; j<col-1;j++){
     if(i==j && U[i][j]!=0){
      // prev=i;
       if(U[i+1][j]!=0 && U[i][j]<U[i+1][j]){
         multiplier=U[i+1][j]/U[i][j];
         L[i+1][j]=multiplier;
         // tricky part to carry out the Elimination
         for(int incr=0;incr<col;incr++){
           U[i+1][j+incr]= U[i+1][j+incr] - (multiplier*( U[i][j+incr]));
          
         }
       }else{
         continue;
       }

      }
   }
 }
}


