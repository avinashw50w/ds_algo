/* Problem: A knight's tour is a sequence of moves of a knight on a chessboard such that the knight visits every square only once.
   Given that the Knight starts from one corner of the chessboard. */

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 8

using namespace std;

int dx[] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int dy[] = { 1, 2,  2,  1, -1, -2, -2, -1 };

int sol[N][N];

void printSol(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)
			cout << sol[i][j] <<" ";
		cout << endl;
	}
}
bool Safe(int x,int y){
	return (x>=0 and x<N and y>=0 and y<N and sol[x][y]==-1);
}

bool solve(int x,int y,int move) {
	if(move == N*N) return true;

	for(int i=0;i<8;++i){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(!Safe(nx,ny)) continue;
		sol[nx][ny] = move;
		if(solve(nx,ny,move+1))   // if next move is a valid move then return true.	
			return true;
		else
			sol[nx][ny] = -1;     // otherwise, set the sol[nx][ny] to -1
	}
	return false;
}

int main() {
	memset(sol,-1,sizeof sol);
	sol[0][0] = 0;

	if(solve(0,0,1)) printSol();

	else cout << "NO SOLUTION EXISTS...";

	return 0;
}


/* 
Output:
  0  59  38  33  30  17   8  63
 37  34  31  60   9  62  29  16
 58   1  36  39  32  27  18   7
 35  48  41  26  61  10  15  28
 42  57   2  49  40  23   6  19
 47  50  45  54  25  20  11  14
 56  43  52   3  22  13  24   5
 51  46  55  44  53   4  21  12

 */
