/*Div2-250 :
You’re required to count the number of equal-valued pairs in an array. Get the frequency of each value, divide by two and sum that up.*/

#include<vector>
#include<map>
using namespace std;
 
class Chopsticks {
public:
    int getmax(vector <int> length);
};
int Chopsticks::getmax(vector <int> length) {
    map<int, int> freq;
    for (int i = 0; i < length.size(); ++i)
        freq[length[i]]++;
    int ans = 0;
    for (map<int, int>::iterator itr = freq.begin(); itr != freq.end(); ++itr)
        ans += itr->second / 2;
    return ans;
}

/*Div2 – 500
A simple simulation problem. You’re given a list of commands a that you’re required to follow T times. Output the manhattan distance 
you have travelled. Each command is an integer that determines the distance you have to travel and the rotation you have to do. 
After following command i, you have travelled a distance of a[i] and rotated an angle of 90 * a[i] to the right.
The naieve solution is acceptable.*/

#include <vector>
#include <cmath>
using namespace std;
typedef long long int64;
 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
class RobotHerbDiv2 {
public:
    int getdist(int T, vector<int> a);
};
int RobotHerbDiv2::getdist(int T, vector<int> a) {
    int x = 0, y = 0, d = 0;
    for (int j = 0; j < T; ++j) {
        for (int i = 0; i < a.size(); ++i) {
            x += a[i] * dx[d];
            y += a[i] * dy[d];
            d += a[i], d %= 4;
        }
    }
    return abs(x) + abs(y);
}

/*Div2 – 1000
Given a tree R , count the number of its subtrees (a subtree here is any tree r \subseteq R ).
Think of this recursively; If we have a tree rooted at node R  with m  children and each child C_i  has T(C_i)  possible subtrees, 
we need to find is T(R) .

T(R) =                                                     (R)'s subtrees =
 1                                                              +(R) only
 +T(C_1)+T(C_2)+T(C_3)...+T(C_m)                                +(R) with 1 child C_i
 +T(C_1)T(C_2)+T(C_1)T(C_3)...+T(C_{m-1})T(C_m)                 +(R)  with  2 children C_i C_j
 +...                                                           +...
 +T(C_1)T(C_2)T(C_3)T(C_4)...T(C_{m-1})T(C_m)                   +(R) with m children C_1 C_2 ... C_m
 = (1 + T(C_1)) (1 + T(C_2)) ... (1 + T(C_m))  	                = computable version  
We use this last formula recursively to get the number of possible trees rooted at R  as a function of its children. 
If we sum that up on all the nodes in the tree, we have counted all the possible subtrees rooted at any node.*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
 
typedef long long int64;
 
class CentaurCompanyDiv2 {
    vector<map<int, int> > graph;
    long long *dp;
    long long rec(int n);
public:
    long long count(vector<int> a, vector<int> b);
};
long long CentaurCompanyDiv2::rec(int n) {
    if (dp[n])
        return dp[n];
    long long ans = 1;
    for (map<int, int>::iterator itr = graph[n].begin();
                itr != graph[n].end(); ++itr)
        ans *= 1 + rec(itr->first);
    return dp[n] = ans;
}
long long CentaurCompanyDiv2::count(vector<int> a, vector<int> b) {
    graph = vector<map<int, int> >(a.size() + 1);
    for (int i = 0; i <= a.size(); ++i)
        graph[i].clear();
    for (int i = 0; i < a.size(); ++i)
        graph[a[i] - 1][b[i] - 1] = 1;
    dp = (long long *) malloc(graph.size() * sizeof(long long));
    memset(dp, 0, sizeof dp);
    long long ans = 0;
    for (int i = 0; i < graph.size(); ++i)
        ans += rec(i);
    return ans + 1;
}
