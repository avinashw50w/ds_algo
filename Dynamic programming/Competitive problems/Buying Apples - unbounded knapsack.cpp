/*Harish went to a supermarket to buy exactly ‘k’ kilograms apples for his ‘n’ friends. The supermarket was really weird. 
The pricing of items was very different. He went to the Apples section and enquired about the prices. The salesman gave 
him a card in which he found that the prices of apples were not per kg. The apples were packed into covers, 
each containing ‘x’ kg of apples, x > 0 and ‘x’ is an integer. An ‘x’ kg packet would be valued at ‘y’ rupees. 
So, the placard contained a table with an entry ‘y’ denoting the price of an ‘x’ kg packet. 
If ‘y’ is -1 it means that the corresponding packet is not available.
Harish likes his friends a lot and so he does not want to disappoint his friends. 
So now, he will tell you how many friends he has and you have to tell him the minimum amount 
of money he has to spend for his friends.

Input
The first line of input will contain the number of test cases, C.

Each test case will contain two lines.

The first line containing N and K, the number of friends he has and the amount of Apples in kilograms which he should buy.

The second line contains K space separated integers in which the ith integer specifies the price of a ‘i’kg apple packet. 
A value of -1 denotes that the corresponding packet is unavailable.

0 < N <= 100
0 < K <= 100
0 < price <= 1000
Output
The output for each test case should be a single line containing the minimum amount of money he has to spend for his friends. 
Print -1 if it is not possible for him to satisfy his friends.

Sample I/O
Input:
2
3 5
-1 -1 4 5 -1
5 5
1 2 3 4 5

Output:
-1
5
Explanation of test cases:

1) As there are only 3 and 4kg packets in the shop, 
he will not be able to satisfy his friends as he would not be able to buy exactly 5kg of apples.

2) He can buy five 1kg packet as he has to buy 5 kg. So the min money he should spend is 5.*/

#include <iostream>
using namespace std;

const int MAXN = 101;
int p[MAXN], dp[MAXN];

int main() {
	int t; cin >> t;
	int N, K;

	while(t--) {
		cin >> N >> K;
		memset(dp, -1, sizeof(dp));

		for(int i = 1; i <= K; ++i) 
			cin >> p[i], dp[i] = p[i];

		for(int i = 2; i <= K; ++i) 
			for(int j = 1; j < i; ++j) {
				if(p[i-j] == -1 || dp[j] == -1) continue;
				if(dp[i] == -1)
					dp[i] = dp[j] + p[i-j];
				else
					dp[i] = min(dp[i], dp[j] + p[i-j]);
			}
	}

}

/*
	dp[i] store the min amount spent to buy exactly i kg of apples

	lets suppose we want to buy K kg of apples, and we have alredy bought j kg of apples, so we need (K-j) kg of apples 
	if we already the min amount to buy j kg of apples the dp[k] will be simply dp[j] + price of packet with weight (K-j) which is p[K-j]

 */

