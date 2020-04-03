#include <bits/stdc++.h> 
using namespace std; 

vector<int> solve(vector<vector<int>> mat, int K) {
	int N = mat.size();
	vector<int> res;
	int dp[N][N];
	memset(dp, 0, sizeof(dp));

	int sum = 0;

	for (int i = 0; i < N; ++i) {
		sum = 0;
		for (int j = 0; j < K; ++j)
			sum += mat[i][j];
		dp[i][0] = sum;

		for (int j = K; j < N; ++j) {
			sum += mat[i][j] - mat[i][j-K];
			dp[i][j-K+1] = sum;
		}
	}

	for (int j = 0; j <= N-K; ++j) {
		sum = 0;
		for (int i = 0; i < K; ++i)
			sum += dp[i][j];
		res.push_back(sum);

		for (int i = K; i < N; ++i) {
			sum += dp[i][j] - dp[i-K][j];
			res.push_back(sum);
		}
	}

	return res;
}
// Driver program to test above function 
int main() 
{ 
    vector<vector<int>>mat = {{1, 1, 1, 1, 1}, 
                     {2, 2, 2, 2, 2}, 
                     {3, 3, 3, 3, 3}, 
                     {4, 4, 4, 4, 4}, 
                     {5, 5, 5, 5, 5}, 
                    }; 
    int k = 3; 
    vector<int> res = solve(mat, k); 
    for (int i: res) cout << i << endl;
    return 0; 
} 