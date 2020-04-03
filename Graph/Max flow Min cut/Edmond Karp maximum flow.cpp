/*This C++ program implements the Edmonds_Karp Algorithm which is used to compute 
the maximum flow between the sink and source vertex. 
It is the same as the Ford-Fulkersson Algorithm except that it uses breadth first search to reduce time complexity.
Here is the source code of the C++ program to display the maximum flow by 
giving the sink and source nodes as input along with the directed graph. 
This C++ program is successfully compiled and run on DevCpp, a C++ compiler.The program output is given below.

/*
 * C++ Program to Implement The Edmonds-Karp Algorithm
 */
#include<cstdio>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
#include<conio.h>
 
using namespace std; 
 
int capacities[10][10];
int flowPassed[10][10];
vector<int> graph[10];
int par[10];       
int currentPathCapacity[10];  
 
int bfs(int source, int sink)
{
    memset(par, -1, sizeof(par));
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
 
    queue<int> q;
    q.push(source);
 
    par[source] = -2;
    currentPathCapacity[source] = INT_MAX;
 
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(par[v] == -1)
            {
                if(capacities[u][v] - flowPassed[u][v] > 0)
                {
                    par[v] = u;
                    currentPathCapacity[v] = min(currentPathCapacity[u], capacities[u][v] - flowPassed[u][v]);
                    if(v == sink)
                    {
                        return currentPathCapacity[sink];
                    }
                    q.push(v);
                }
            }
        }
    }
    return 0;
}
 
int edmondsKarp(int source, int sink)
{
    int maxFlow = 0;
    while(true)
    {
        int flow = bfs(source, sink);
        if (flow == 0) 
        {
            break;
        }
        maxFlow += flow;
        int currentNode = sink;
        while(currentNode != source)
        {
            int previousNode = par[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }
    }
    return maxFlow;
}

int main()
{
    int nodes, edges;
    cout << "enter the number of nodes and edges\n";
    cin >> nodes >> edges;
 
    int source, sink;
    cout << "enter the source and sink\n";
    cin >> source >> sink;
 
    for(int edge = 0; edge < edges; edge++)
    {
        cout<<"enter the start and end vertex alongwith capacity\n";
        int u, v, capacity;
        cin >> u >> v >> capacity;
 
        capacities[u][v] = capacity;
        graph[u].push_back(v);
 
        graph[v].push_back(u);
    }
 
    int maxFlow = edmondsKarp(source, sink);
 
    cout << "Max Flow is: " << maxFlow << endl;
 
    getch();
}
