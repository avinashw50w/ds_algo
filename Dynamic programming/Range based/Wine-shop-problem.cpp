/*Maximum profit from sale of wines
Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sale the first or the last wine in the row. However, the price of wines increases over time. Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi. For each year, your task is to print “beg” or “end” denoting whether first or last wine should be sold. Also, calculate the maximum profit from all the wines.
Input: Price of wines: 2 4 6 2 5
Output: 64
*/

vector<int> price;

int solve(int s, int e, int year) {
    if (s == e) return price[s] * year;

    int left = price[s] * year + solve(s + 1, e, year + 1);
    int right = price[e] * year + solve(s, e - 1, year + 1);

    return max(left, right);
}
// call
solve(0, N - 1, 1);

///////////////// USING DP ///////////////////
// top down
int dp[N][N];
memset(dp, -1, sizeof(dp));

int solve(int s, int e, int year) {
    if (dp[s][e] != -1) return dp[s][e];

    if (s == e) return price[s] * year;

    int left = price[s] * year + solve(s + 1, e, year + 1);
    int right = price[e] * year + solve(s, e - 1, year + 1);

    return dp[s][e] = max(left, right);
}

// bottom up
int solve2() {
    for (int i = 0; i < N; ++i) dp[i][i] = price[i] * N;
    for (int l = 2; l <= N; ++l) {
        for (int i = 0; i <= N - l; ++i) {
            int j = i + l - 1;
            int year = N - (j - i);
            int left = price[i] * year + dp[i + 1][j];
            int right = price[j] * year + dp[i][j - 1];
            dp[i][j] = max(dp[i][j], max(left, right));
        }
    }

    return dp[0][N - 1];
}

//////////////////////////////////
// To also print the order of buy and sell
int dp[N][N];
memset(dp, -1, sizeof(dp));
int order[N][N]; // value of 0 represents beginning and 1 represents end

int solve(int s, int e, int year) {
    if (dp[s][e] != -1) return dp[s][e];

    if (s == e) return price[s] * year;

    int left = price[s] * year + solve(s + 1, e, year + 1);
    int right = price[e] * year + solve(s, e - 1, year + 1);

    dp[s][e] = max(left, right);

    order[s][e] = left >= right ? 0 : 1;
    return dp[s][e];
}

void printOrder() {
    int i = 0, j = N - 1;

    while (i <= j) {
        if (order[i][j] == 0) {
            cout << "beginning ";
            i++;
        } else {
            cout << "end";
            j--;
        }
    }
}