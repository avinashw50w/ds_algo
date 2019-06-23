#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

struct node{
	int num;     // number of the node
	int dist;    //  distance of the node from the source
};

int GetMinDiceThrows(int move[], int N){
	vi Vist(N,0);
	queue<node> Q;
	
	Vist[0] = 1;
	Q.push({0,0});
	node u;
	while(!Q.empty()){
		u = Q.front();
		int k = u.num;
		if(k == N-1) break;
		Q.pop();
		for(int i=k+1; i<=(k+6) && i<N; ++i){
			if(!Vist[i]){
				Vist[i] = 1;
				node v;
				v.dist = u.dist + 1;
				
				if(move[i] != -1)
					v.num = move[i];
				else
					v.num = i;
				
				Q.push(v);
			}
		}
	}
	return u.dist;	
}

int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
 
    cout << "Min Dice throws required is " << GetMinDiceThrows(moves, N);
    return 0;
}
