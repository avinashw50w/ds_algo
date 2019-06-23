/*Abridged problem statement: You are given a simple arithmetic expression which consists of only
addition and subtraction operators, i.e. 1 - 2 + 3 - 4 - 5. You are free to put any parentheses
to the expression anywhere and as many as you want as long as the expression is still valid. How
many different numbers can you make? The answer for simple expression above is 6:
1 - 2 + 3 - 4 - 5 = -7 			1 - (2 + 3 - 4 - 5) = 5
1 - (2 + 3) - 4 - 5 = -13 		1 - 2 + 3 - (4 - 5) = 3
1 - (2 + 3 - 4) - 5 = -5 		1 - (2 + 3) - (4 - 5) = -3
The expression consists of only 2 ≤ N ≤ 30 non-negative numbers less than 100, separated by
addition or subtraction operators. There is no operator before the first and after the last number.


To solve this problem, we need to make three observations:
1. We only need to put an open bracket after a ‘-’ (negative) sign as it will reverse the meaning of
subsequent ‘+’ and ‘-’ operators;
2. You can only put X close brackets if you already use X open brackets – we need to store this
information to process the subproblems correctly;
3. The max value is 100 + 100 + ... 100 (30 times) = 3000 and the min value is 100 - 100 - ... -
100 (29 times) = -2800 – this information needs to be stored, as we will see below.
The DP states that are easier to identify:
1. ‘idx’ – the current position being processed, we need to know where we are now.
2. ‘open’ – number of open brackets, we need this information in order to produce valid expression.

But these two states are not unique yet. For example, this partial expression: ‘1-1+1-1...’ has
state idx=3 (indices: 0,1,2,3 have been processed), open=0 (cannot put close bracket anymore),
which sums to 0. Then, ‘1-(1+1-1)...’ also has the same state idx=3, open=0 and sums to 0. But
‘1-(1+1)-1...’ has the same state idx=3, open=0, but sums to -2. This DP state is not yet unique.
So we need additional value to distinguish them, i.e. the value ‘val’, to make these states unique.
We can represent all possible states of this problem with bool state[idx][open][val], a
3-D array. As ‘val’ ranges from -2800 to 3000 (5801 distinct values), the number of states is
30×30×5801 ≈ 5M with only O(1) processing per state – fast enough. The code is shown below:*/

int N, num[30], sig[30];
int used[7001], dp[30][30][3000];

void solve(int idx, int open, int val) {
	if(dp[idx][open][val+3500]) // 3500 is added in case the value is -ve(the min value of val can be -3000)
		return;

	dp[idx][open][val] = 1;

	if(idx == N) {
		used[val+3500] = 1;
		return;
	}

	int nval = val + num[idx] * sig[idx] * ((open&1 == 0) ? 1 : -1);

	if(sig[idx] == -1) // put an open parenthesis only if the sign is -ve
		solve(idx+1, open+1, nval);

	// close an open parenthesis(if any)
	if(open > 0)
		solve(idx+1, open-1, nval);

	// do nothing
	solve(idx+1, open, nval);
}

// The solution is all the values in array ‘used’,
// offset by -3500, that are flagged as true.

for(int i = 0; i < 7001; ++i) if(used[i]) cout << i-3500 << endl;