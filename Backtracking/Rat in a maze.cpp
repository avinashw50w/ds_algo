
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define N 4
int maze[N][N] = { {1, 0, 0, 0},
        		   {1, 1, 0, 1},
        		   {0, 1, 0, 0},
        		   {1, 1, 1, 1} };
int sol[N][N]; 

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };      		 

void printSol(){
	for(int i=0;i<N;++i){	
		for(int j=0;j<N;++j)
			cout << sol[i][j] <<" ";
		cout << endl;
	}
}
bool Safe(int x,int y){
	return (x>=0 and x<N and y>=0 and y<N and maze[x][y]==1);
}  

bool solve(int x,int y) {
	if(x==N-1 and y==N-1){
		sol[x][y] = 1;
		return true;
	} 
	for(int i=0;i<2;++i){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(!Safe(nx,ny)) continue;
		sol[nx][ny] = 1;
		if(solve(nx,ny))		
			return true;
		else
			sol[nx][ny] = 0;
	}
	return false;
}

int main(){
	sol[0][0] = 1;
	if(solve(0,0))
		printSol();
	else 
		cout << "NO SOLUTION EXISTS...";

	return 0;
}
