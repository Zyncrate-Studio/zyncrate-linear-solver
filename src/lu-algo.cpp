#include <iostream>
#include "../include/solver.hpp"
#include <vector>



void ALU(std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U){   

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


void Optimized_ALU(std::vector<double>& A, std::vector<double>& L, std::vector<double>& U){   

  // Elimination Algo
 //int prev=0;
 double multiplier=0;
 for(int i=0;i<row-1;i++){
   for(int j=0; j<col-1;j++){
    int index= i*col+j;
     if(i==j && U[index]!=0){
      // prev=i;
      for(int target_row=i+1; target_row<row; target_row++){
          std::cout<<"I: "<<i<<std::endl;
          std::cout<<"J: "<<j<<std::endl;
          std::cout<<"Index: "<<index<<std::endl;
          std::cout<<"target row: "<<target_row<<std::endl;

         if(U[target_row *col+j]!=0){
           multiplier=U[target_row*col+j]/U[index];
           std::cout<<"multiplier: "<<multiplier<<std::endl;
           L[target_row*col+j]=multiplier;
           // tricky part to carry out the Elimination
           for(int incr=j;incr<col;incr++){
            //int target_col=j+incr;
            U[target_row*col+incr]= U[target_row*col+incr] - (multiplier*( U[i*col+incr]));
            std::cout<<"U[4] "<<U[4]<<std::endl;
            std::cout<<"U[5] "<<U[5]<<std::endl;
            std::cout<<"U[7] "<<U[7]<<std::endl;
            std::cout<<"U[8] "<<U[8]<<std::endl;
            std::cout<<"Done"<<std::endl;
            if(incr>=col) break;
           }
         }else{
           std::cerr<<"Error in elimination"<<std::endl;
         }
        }
      }
   }
 }
}


