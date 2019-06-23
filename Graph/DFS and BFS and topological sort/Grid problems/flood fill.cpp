//  flood fill is used to label/color the connected components of a graph  //

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int N;
vi V;
vi *G;

void floodFill(int i,int color){
	if(!V[i]){
		V[i] = color;
		for_each(ALL(G[i]),floodFill);
	}
}

int main(){
	V.assign(N,0);
	G=new vi[N];
	int numComponent=0;
	for(int i=0;i<N;i++){
		if(!V[i])
			floodFill(i , ++numComponent);
	}

	for(int i=0;i<N;i++)
		printf("Vertex %d has color %d\n",i , V[i]);
}