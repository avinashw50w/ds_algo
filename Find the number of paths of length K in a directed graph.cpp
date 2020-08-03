/*Given a directed, unweighted graph with N vertices and an integer K. The task is to find the number
of paths of length K for each pair of vertices (u, v). Paths don’t have to be simple i.e. vertices
and edges can be visited any number of times in a single path.
The graph is represented as adjacency matrix where the value G[i][j] = 1 indicates that there is an
edge from vertex i to vertex j and G[i][j] = 0 indicates no edge from i to j.

Approach: It is obvious that given adjacency matrix is the answer to the problem for the case k = 1.
It contains the number of paths of length 1 between each pair of vertices.
Let’s assume that the answer for some k is Matk and the answer for k + 1 is Matk + 1.

(Matk+1)[i][j] = ∑p = 1 to N Matk[i][p]*G[p][j]

It is easy to see that the formula computes nothing other than the product of the matrices Matk and G i.e. Matk + 1 = Matk * G

Thus, the solution of the problem can be represented as Matk = G * G * … * G(k times) = Gk*/


#include <bits/stdc++.h>
using namespace std;

#define N 3

// Function to multiply two matrices
void multiply(int a[][N], int b[][N], int res[][N])
{
    int mul[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < N; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
    }

    // Storing the multiplication result in res[][]
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res[i][j] = mul[i][j];
}

// Function to compute G raised to the power n
void power(int G[N][N], int res[N][N], int n)
{

    // Base condition
    if (n == 1) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res[i][j] = G[i][j];
        return;
    }

    // Recursion call for first half
    power(G, res, n / 2);

    // Multiply two halves
    multiply(G, G, res);

    // If n is odd
    if (n % 2 != 0)
        multiply(res, G, res);
}

// Driver code
int main()
{
    int G[N][N] = { { 1, 1, 1 },
                    { 0, 0, 1 },
                    { 0, 1, 0 } };

    int k = 2, res[N][N];

    power(G, res, k);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
} 
