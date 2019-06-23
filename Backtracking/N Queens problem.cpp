#include <bits/stdc++.h>
using namespace std;

int N;  // N x N board
int x[20];  // x[c] = r  indicates the row position r of the queen placed at column c
int cnt = 0;
void print() {
	printf("Configuration : %d\n", ++cnt);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(x[j] == i) printf("Q\t");
			else printf("-\t");
		}
		printf("\n");
	}
}
// checks whether a queen can be placed at (r,c) // 
/* it can ony be placed at (r,c) iff there is no queen in row r and column < c  
   or there exists no queen diagonal to it */ 
bool safe(int row, int col){
	for(int C = 1; C < col; C++){
		if(x[C] == row || abs(x[C] - row) == abs(C - col))
			return false;
	}
	return true;
}

void N_queens(int col) {
	// base case
	if(col > N) print();
	// iterate through all the rows
	for(int row = 1; row <= N; ++row) {
		// check if the queen can be placed at column 'col' of this row
		if(!safe(row, col)) continue;
			x[col] = row;	
			
			N_queens(col + 1);
	}
}

int main() {
	N = 4;
	N_queens(1);
}
