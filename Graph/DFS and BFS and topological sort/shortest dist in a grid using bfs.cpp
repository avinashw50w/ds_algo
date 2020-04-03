#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define pb emplace_back

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int V[5][5];
int dist[5][5];
int grid[5][5]={{1,2,3,-1,5},
				{6,7,-1,999,-1},
				{11,12,13,14,15},
				{23,99,999,45,22},
				{13,45,32,56,23}};
void bfs(pii s)
{
	queue<pii> q;
	q.push(s);
	int f=0;
	memset(dist, oo, sizeof(dist));
	dist[0][0]=0;
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if(V[x][y]) continue;
		V[x][y] = 1;
			
		for(int i=0;i<4;i++){
			
			int nx=x+dx[i] , ny=y+dy[i];
			
			if(nx>=0 && nx<5 && ny>=0 && ny<5 && grid[nx][ny]!=-1)
			{						
				if(!V[nx][ny]) 
				{
					if(dist[nx][ny] == oo || dist[nx][ny] > dist[x][y] + 1) 
					{
						dist[nx][ny] = dist[x][y] + 1
						q.push(pii(nx,ny));
					}
					
					if(grid[nx][ny]==999) { 
                        f=1;cout<<"found at ("<<nx<<","<<ny<<")"<<endl; 
                        cout<<"shortest dist :"<<dist[nx][ny]<<endl;
                    }
				}
			}
		}
	}
	if(f==0)
	cout<<"not found";
}
int main(){
	
	bfs(pii(0,0));
	return 0;
}
