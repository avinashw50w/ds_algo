/*There is a hotel with M floors. ith floor of the hotel has infinite identical rooms, each room can 
accommodate C[i] people (Two rooms of same floor are indifferentiable and have same capacity while two 
rooms of different floors have different capacity).
There is one rule:
Any room on tth floor will accommodate exactly C[i] people (not less or more).

Now N identical people come for accommodation. You can assign any of them to any room of any floor 
following the mentioned rule.

Way of assigning:
If we have 5 people and 3 floors. Let's say floor 1 has room capacity 1 and floor 2 has room capacity 2, then:
(1,2,2) is a way of assigning people. This means we assign one person out of those 5 people to any room of floor 1. The remaining 4 people are assigned to two rooms of floor 2, each room accommodating 2 people.
We will consider (1,2,2), (2,1,2), (2,2,1) as the same ways as we can't differentiate between them.

You have to tell number of different ways of accommodating N people.
Two ways are considered different if one way is not a permutation of other way.

Input Format:
First line consists of two integers M and N, denoting number of floors and number of people respectively.
Second line consists of M space separated integers denoting capacity of floors. ith integer denotes 
capacity of ith floor.

Output Format:
Print the number of different ways of accommodating people.
Since the number of ways can be large, print the answer modulo .

Input Constraints:
SAMPLE INPUT 
3 5
1 2 3
SAMPLE OUTPUT 
5
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
	int N, M;
	cin >> M >> N;

	int C[M];
	for (int i = 0; i < M; ++i) cin >> C[i];

	ll dp[N+1] = {0};
	dp[0] = 1;

	for (int i = 0; i < M; ++i) 
		for (int j = C[i]; j <= N; ++j) {
		    dp[j] += dp[j-C[i]];
		    dp[j] %= mod;
		}
			

	cout << dp[N] << endl;
}