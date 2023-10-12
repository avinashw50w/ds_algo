/*
https://cybergeeksquad.co/2023/03/shopping-patterns-solution-amazon-oa.html
You are given an undirected graph. You are given an integer n which is the number of nodes in the graph 
and an array edges, where each edges[i] = [u, v] indicates that there is an undirected edge between u and v.
A connected trio is a set of 3 nodes where there is an edge between every pair of them.
The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
Return the minimum  degree of a connected trio in the graph, or -1 if the graph has no connected trios.
*/

class Solution {
public:
    
    bool visited[401][401];
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>>adj(n+1);
        
        memset(visited,false,sizeof(visited));
        
        int degree[n+1];
        for(int i=0;i<n+1;i++)
            degree[i]=0;
        
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            visited[start][end]=true;
            visited[end][start]=true;
            
            degree[start]++;
            degree[end]++;
        }
        
        int result = INT_MAX;
        
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    if(connected(i,j,k)){
                        int count = 0;
                        count+=degree[i]-2;
                        count+=degree[j]-2;
                        count+=degree[k]-2;
                        result=min(result,count);
                    }
                }
            }
        }
        
        return result==INT_MAX ? -1: result;
    }
    
    bool connected(int i,int j,int k){
        if(!visited[i][j] || !visited[i][k])
            return false;
        
        if(!visited[j][i] || !visited[j][k])
            return false;
        
        if(!visited[k][i] || !visited[k][j])
            return false;
        
        return true;
    }
};