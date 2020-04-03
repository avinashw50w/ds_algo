/*Temple Offerings
Consider a devotee wishing to give offerings to temples along a mountain range. The temples are located in a row at 
different heights. Each temple should receive at least one offering. If two adjacent temples are at different altitudes, 
then the temple that is higher up should receive more offerings than the one that is lower down. 
If two adjacent temples are at the same height, then their offerings relative to each other does not matter. 
Given the number of temples and the heights of the temples in order, find the minimum number of offerings to bring.

Examples:

Input  : 3
         1 2 2
Output : 4
All temples must receive at-least one offering.
Now, the second temple is at a higher altitude
compared to the first one. Thus it receives one
extra offering. 
The second temple and third temple are at the 
same height, so we do not need to modify the 
offerings. Offerings given are therefore: 1, 2,
1 giving a total of 4.

Input  : 6
         1 4 3 6 2 1
Output : 10
We can distribute the offerings in the following
way, 1, 2, 1, 3, 2, 1. The second temple has to 
receive more offerings than the first due to its 
height being higher. The fourth must receive more
than the fifth, which in turn must receive more 
than the sixth. Thus the total becomes 10.*/

// O(n^2) solution

int solve(int height[], int n) {

	int sum = 0;

	for (int i = 0; i < n; ++i) {
		int left = 0, right = 0;

		// go to left while height keeps decreasing
		for (int j = i-1; j >= 0; --j) {
			if (height[j] < height[j+1]) left++;
			else break;
		}

		// go to right while height keeps on decreasing
		for (int j = i+1; j < n; ++j) {
			if (height[j-1] > height[j]) right++;
			else break;
		}

		sum += max(left, right) + 1;
	}

	return sum;
}


//////////////////////////////////////////////////////////
// O(n) solution

int solve(int height[], int n) {

	int sum = 0;

	pair<int,int> dp[n];

	dp[0].first = 1;
	dp[n-1].second = 1;

	for (int i = 1; i < n; ++i) {
		if (height[i-1] < height[i]) 
			dp[i].first = dp[i-1].first + 1;
		else
			dp[i].first = 1;
	}

	for (int i = n-2; i >= 0; --i) {
		if (height[i] > height[i+1])
			dp[i].second = dp[i+1].second + 1;
		else 
			dp[i].second = 1;
	}

	for (int i = 0; i < n; ++i)
		sum += max(dp[i].first, dp[i].second);

	return sum;
}