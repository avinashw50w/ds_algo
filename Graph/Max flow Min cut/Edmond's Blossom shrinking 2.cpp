/*Given a graph G = (V,E), a matching M in G is a set of pairwise non-adjacent edges; that is, no two edges share a common vertex. 
A maximum matching is a matching that contains the largest possible number of edges. There may be many maximum matchings. 
The matching number of a graph is the size of a maximum matching. The problem is to find maximum matching of for given graph.

One of possible solutions for this problem is Blossom shrinking algorithm. An efficient implementation is described by Gabow. 
Since original Gabow's algorithm is complicated I found a way how to construct more simplified version. 
I tested it on some random graphs and found that is is only twice slower. So I think it is ok.
*/

#include <cstdlib>
#include <cstdio>
 
int G[101][101];
int VLabel[101];
int  Queue[101];
int   Mate[101];
int   Save[101];
int   Used[101];
int    Up, Down;
int        V, E;
 
void Input()
{
    scanf("%d %d\n", &V, &E);
    for (int i = 1; i <= E; i++)
    {
        int x, y;
        scanf("%d %d\n", &x, &y);
        G[x][++G[x][0]] = y;
        G[y][++G[y][0]] = x;
    }
}
 
void ReMatch(int x, int y)
{
    int m = Mate[x]; Mate[x] = y;
    if (Mate[m] == x)
    {
        if (VLabel[x] <= V)
        {
            Mate[m] = VLabel[x];
            ReMatch(VLabel[x], m);
        }
        else
        {
            int a = 1 + (VLabel[x] - V - 1) / V;
            int b = 1 + (VLabel[x] - V - 1) % V;
            ReMatch(a, b); ReMatch(b, a);
        }
    }
}
 
void Traverse(int x)
{
    for (int i = 1; i <= V; i++) Save[i] = Mate[i];
    ReMatch(x, x);
    for (int i = 1; i <= V; i++)
    {
        if (Mate[i] != Save[i]) Used[i]++;
        Mate[i] = Save[i];
    }
}
 
void ReLabel(int x, int y)
{
    for (int i = 1; i <= V; i++) Used[i] = 0;
    Traverse(x); Traverse(y);
    for (int i = 1; i <= V; i++) 
    {
        if (Used[i] == 1 && VLabel[i] < 0)
        {
            VLabel[i] = V + x + (y - 1) * V;
            Queue[Up++] = i;
        }
    }
}
 
void Solve()
{
    for (int i = 1; i <= V; i++)
        if (Mate[i] == 0)
        {
            for (int j = 1; j <= V; j++) VLabel[j] = -1;
            VLabel[i] = 0; Down = 1; Up = 1; Queue[Up++] = i;
            while (Down != Up)
            {
                int x = Queue[Down++];
                for (int p = 1; p <= G[x][0]; p++)
                {
                    int y = G[x][p];
                    if (Mate[y] == 0 && i != y)
                    {
                        Mate[y] = x; ReMatch(x, y);
                        Down = Up; break;
                    }
                    if (VLabel[y] >= 0)
                    {
                        ReLabel(x, y);
                        continue;
                    }
                    if (VLabel[Mate[y]] < 0)
                    {
                        VLabel[Mate[y]] = x;
                        Queue[Up++] = Mate[y];
                    }
                }
            }
        }
}
 
void Output()
{
    int Count = 0;
    for (int i = 1; i <= V; i++)
        if (Mate[i] > i) Count++;
    printf("Maximum matching = %d\n", Count);	
}
 
int main(int argc, char * argv[])
{
    Input(); Solve(); Output();
    return 0;
}