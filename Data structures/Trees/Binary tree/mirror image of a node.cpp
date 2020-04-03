/*You are given a binary tree rooted at 1. You have to find the mirror image of any node qi about node 1. If it doesn't exist then print -1.
Input:
First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node , second is child node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:
For each qi print it mirror node if it exists else print -1. 
NOTE: 1 is mirror image of itself.
Constraints:
1 <= N <= 103
1<= Q <= 103

SAMPLE INPUT 
10 8
1 2 R
1 3 L
2 4 R
2 5 L
3 6 R
3 7 L
5 8 R
5 9 L
7 10 R
2
5
3
6
1
10
9
4 */

#include <iostream>
#include <string.h>
using namespace std;

const int maxn = 100001;
int indexOf[maxn], rIndexOf[maxn], nodeAtIndex[maxn], rNodeAtIndex[maxn];

int main() {
    int N, Q;
    int q, idx, ridx, par, child;
    char dir;
    
    cin >> N >> Q;
    
    memset(nodeAtIndex, -1, sizeof(nodeAtIndex));
    memset(rNodeAtIndex, -1, sizeof(rNodeAtIndex));
    
    indexOf[1] = rIndexOf[1] = nodeAtIndex[1] = rNodeAtIndex[1] = 1;
    
    for (int i = 1; i < N; ++i) {
        cin >> par >> child >> dir;
        
        if (dir == 'L') {
            idx = indexOf[par] << 1;
            ridx = rIndexOf[par] << 1 | 1;
        }
        else {
            idx = indexOf[par] << 1 | 1;
            ridx = rIndexOf[par] << 1;
        }
        
        nodeAtIndex[idx] = child;
        rNodeAtIndex[ridx] = child;
        
        indexOf[child] = idx;
        rIndexOf[child] = ridx;
    }
    
    while (Q--) {
        cin >> q;
        cout << rNodeAtIndex[indexOf[q]] << endl;
    }
}