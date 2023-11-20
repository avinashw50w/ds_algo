/*Given an array of integers, check if a subset exists whose sum is target.
NOTE: each element of the array can be taken only once.
*/
class Sol {
	vector<int> dp;
	vector<int> a;
public: 
	int subsetSumTopDownUtil(int pos, int sum) {
		if (sum == 0) return true;
		if (sum < 0) return false;
		int &res = dp[sum];
		if (res) return res;

		for (int i=pos; i<a.size(); ++i) {
			res |= subsetSumTopDownUtil(i+1, sum-a[i]);
		}
		return res;
	}
	// works even if array elements contain -ve numbers. But targetSum should be +ve 
	// T: O(N*targetSum)
	int subsetSumTopDown(vector<int> a, int targetSum) {
		this->a = a;
		dp = vector<int(targetSum+1, 0);
		return subsetSumTopDownUtil(0, targetSum);
	}

	// find a path that leads to targetSum, 
	// and once the path is found then backtrack the path and store it
	bool subsetSumPathUtil(int pos, int sum, vector<int> &path ) {
		if (sum == 0) return true;
		if (sum < 0) return false;
		
		if (dp.count(sum)) return dp[sum];

		for (int i = pos; i < a.size(); ++i) {
			if (subsetSumPathUtil(i+1, sum-a[i], path)) {
				path.push_back(a[i]);
				dp[sum] = path;
				return true;
			}
		}
		return false;
	}

	// works for both a[i] +ve or -ve and targetSum >= 0
	// T: O(N*targetSum)
	vector<int> subsetSumPath(vector<int> a, int targetSum) {
		vector<int> path;
		this->a = a;
		unordered_map<int, vector<int> dp; // {sum, path}
		subsetSumPathUtil(0, targetSum, path);
		return path;
	}

	// works only if a[i] >= 0 and targetSum >= 0
	// T: O(N*targetSum)
	int subsetSumBottomUp(vector<int> a, int targetSum) {
		int n = a.size();
		dp = vector<int(targetSum+1, 0);
		dp[0] = 1;

		for (int i = 0; i < n; i++)	{// for all the numbers of the array
			for (int j = targetSum; j >= a[i]; j--) {// for sums ranging b/w a[i] to S
				dp[j] |= dp[j - a[i]];
			}
		}
		return dp[targetSum];
	}

	// works only if a[i] >= 0 and targetSum >= 0
	// T: O(N)
	int subsetSumBitmask(vector<int> a, int targetSum) {
		// let the total sum of the elemets of the array a be S
		bitset<targetSum> bit;

		bit.reset();  // reset all bits to 0
		bit[0] = 1; // 0th bit will be 1 indicating that sum 0 is possible (ie, when no element is chosen)

		// bit[i] will indicate that a subset sum of i is possible or not
		for (int i = 0; i < n; ++i) {
			bit |= (bit << a[i]);
		}

		return bit[targetSum];
	}

	// works for both a[i] +ve or -ve and targetSum can be either +ve or -ve;
	// T: O(2^N * N)
	int subsetSumBitmask2(vector<int> a, int targetSum) {
		int n = a.size();
		for (int i = 0; i < 1<<n; ++i) {
			int subsetSum = 0;
			for (int j = 0; j < n; ++j) {
				if (i>>j&1) subsetSum += a[j];
			}
			if (subsetSum == target) return true;
		}

		return false;
	}

	int solve(int target) {
		vector<int> a = {1,2,3,-4,6,5};
		return subsetSumTopDown(a, target);
	}
}


// here S is the total sum of the array
// dp[k] indicates whether any subset of sum k exists in the array or not
// Special NOTE: if the elements are in infinite supply, then just reverse the jth loop : for (j = a[i]; j <= S; ++j)

//////////////////////////////////////////////////////////////////////////////////////////////
// bottom up //
bool isSubset(int a[], int n, int sum) {
	bool subset[n + 1][sum + 1];
	for (int i = 0; i <= n; i++) subset[i][0] = true; //  if sum = 0 ,then it is possible to get it via an empty subset
	for (int i = 1; i <= sum; i++) subset[0][i] = false; //  if the set is empty, and sum is positive then it is not possible to get the sum

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sum; j++) {
				if (j < a[i - 1]) subset[i][j] = subset[i - 1][j];

				else subset[i][j] = subset[i - 1][j] || subset[i - 1][j - a[i - 1]];
			}
		}
		return subset[n][sum];
	}

//  lets say we have a set = { 2,3,7,8,10 } and we want sum =11
/*  if we have sum 2 and set 3 , here sum is less than 3 , so we go to previous set ie 2 , and assign it the value at 2.the value at 2 may be true or false
depending on whether it was possible to get sum=2 from element 2.

if we have sum =9 and set =7 , here sum> set by 2 . then we have two choices : 1. we assign it the value of the previous set 3 and set 3 will have value true or false
depending on whether it is possible to get sum 9 from elements {2,3}.
2.we pick the element 7 and now the difference is (9-7)=2 ,and then we go the previous elements and assign it the value where sum is 2.this value will be true or false depending on
whether it was possible to get sum 2 from the previous elements.*/




