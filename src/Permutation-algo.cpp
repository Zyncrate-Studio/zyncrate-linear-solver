#include "solver.hpp"
#include <iostream>
#include <vector>


std::vector<double>U;
std::vector<double>P(row*col,0.0);
std::vector<double>L(row*col,0.0);

/*void AV(){
  // P matrix
  P[0]=1;P[1]=0;P[2]=0;
  P[3]=0;P[4]=1;P[5]=0;
  P[6]=0;P[7]=0;P[8]=1;

  // L matrix 
  L[0]=1;L[1]=0;L[2]=0;
  L[3]=0;L[4]=1;L[5]=0;
  L[6]=0;L[7]=0;L[8]=1;
}*/


void AV(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			int index=i*col+j;
			if(i==j){
				P[index]=1;
				L[index]=1;
			}else{
				P[index]=0;
				L[index]=0;
			}
		}
	}
}

void PALU(std::vector<double>&A){
	U=A;
	AV();
	int swap_row;// the row replacing the bad row
	int swap_col;
	int current_row; // this is where the error occurs
	int current_col;
	std::vector<double>buffer(row*col,0.0); // to hold swap row-col value
	// first loop through to scan the matrix
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			int index= i*col+j;
			if(i==j && U[index]==0){
				current_row=i;
				current_col=j;
				// accounts for bounds in the matrix 					
				if(i-1<0){
					swap_row=i+1;
					swap_col=j; 
				}
				// check swap row and column and take to buffer
				int target_col_prev=j-1;
				int target_col= swap_col;
				int target_col_forw=swap_col+1;
				if(U[swap_row*col+current_col]!=0){
					if(target_col_prev>=0 && target_col_forw<=col){
						// holds the swap row of U matrix
						buffer.push_back(U[swap_row*col+target_col_prev]);
						buffer.push_back(U[swap_row*col+target_col]);
						buffer.push_back(U[swap_row*col+target_col_forw]);
						// holds the swap row of P matrix 	
						buffer.push_back(P[swap_row*col+target_col_prev]);
						buffer.push_back(P[swap_row*col+target_col]);
						buffer.push_back(P[swap_row*col+target_col_forw]);
					}else{
						std::cerr<<"Error in buffer operation";
					}
				}

			}
		}
	}

	//Take from A and put the current row in U beware of bounds
	// figure out a way to handle if j is 0 or 2 in a 3x3 matrix later on 
	int target_col1=swap_col;
	int target_col1_dforw=swap_col+1+1;
	int target_col1_forw=swap_col+1;

	// U matrix
	U[swap_row*col+target_col1]=A[current_row*col+target_col1];
	U[swap_row*col+target_col1_forw]=A[current_row*col+target_col1_forw];
	U[swap_row*col+target_col1_dforw]=A[current_row*col+target_col1_dforw]; 

	// P matrix 
	P[swap_row*col+target_col1]=L[current_row*col+target_col1];
	P[swap_row*col+target_col1_forw]=L[current_row*col+target_col1_forw];
	P[swap_row*col+target_col1_dforw]=L[current_row*col+target_col1_dforw];

	// pass the other value from the buffer

	// U matrix
	U[current_row*col+target_col1]=buffer[0];
	U[current_row*col+target_col1_forw]=buffer[1];
	U[current_row*col+target_col1_dforw]=buffer[2];

	// P matrix
	P[current_row*col+target_col1]=buffer[3];
	P[current_row*col+target_col1_forw]=buffer[4];
	P[current_row*col+target_col1_dforw]=buffer[5];

	// Gaussian Elimination Loop 
	Optimized_ALU(A,L,U);

}