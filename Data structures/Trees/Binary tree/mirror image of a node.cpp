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
using namespace std;

int map[N+1], rmap[N+1], set[N+1], rset[N+1];

int main() {
	
	int N, Q;
	int a, b, index, rindex;
	char c;
	cin >> N >> Q;

	for (int i = 0; i < N+1; ++i)
		set[i] = rset[i] = -1;

	set[1] = rset[1] = map[1] = rmap[1] = 1;

	for (int i = 1; i < N; ++i) {
		
		cin >> a >> b >> c;

		if (c == 'L') {
			index = map[a] << 1;
			rindex = rmap[a] << 1 | 1;
		}
		else {
			index = map[a] << 1 | 1;
			rindex = rmap[a] << 1;
		}

		set[index] = b;
		rset[rindex] = b;

		map[b] = index;
		rmap[b] = rindex;
	}

	while(Q--) {
		cin >> a;
		cout << rset[map[a]] << endl;
	}
}