/*Given an array of N positive integers. We are allowed to remove element from either of the two ends 
i.e from the left side or right side of the array. Each time we remove an element, score is increased 
by value of element * (number of element already removed + 1). 
The task is to find the maximum score that can be obtained by removing all the element.

Examples:

Input : arr[] = { 1, 3, 1, 5, 2 }.
Output : 43
Remove 1 from left side (score = 1*1 = 1)
then remove 2, score = 1 + 2*2 = 5
then remove 3, score = 5 + 3*3 = 14
then remove 1, score = 14 + 1*4 = 18
then remove 5, score = 18 + 5*5 = 43.

Input :  arr[] = { 1, 2 }
Output : 5.*/

/*The idea is to use Dynamic Programming. Make a 2D matrix named dp[][] initialised with 0, 
where dp[i][j] denote the maximum value of score from index from index ito index j of the array. 
So, our final result will be stored in dp[0][n-1].
Now, value for dp[i][j] will be maximum of arr[i] * (number of element already removed + 1) + 
dp[i+ 1][j] or arr[j] * (number of element already removed + 1) + dp[i][j – 1].*/

const int maxn = 100;
int dp[maxn][maxn];

int solve(int a[], int l, int r, int turn) {

	if (l == r) 
		return a[l] * turn;

	if (dp[l][r] != 0) return dp[l][r];

	dp[l][r] = max(a[l] * turn + solve(a, l+1, r, turn+1), a[r] * turn + solve(a, l, r-1, turn+1));

	return dp[l][r];
}