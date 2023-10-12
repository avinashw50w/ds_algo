/* https://cybergeeksquad.co/2023/03/get-encrypted-number-amazon-oa.html
You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
The triangular sum of nums  s the value of the only element present in nums after the following process terminates:
1. let nums comprise of n elements. If n == 1 end the process, otherwise create a 0-indexed array newNums of size n-1
2. assign newNums[i] as (nums[i] + nums[i+1]) % 10
3. replace nums with newNums
4. Repeat the entire process

Return the final value of nums. ie. when nums length becomes 1
*/

int solve(vector<int> nums) {
	int n = nums.size();
	if (n == 1) {
		return nums[0];
	}
	vector<int> newNums(n-1);

	for (int i = 0; i < n-1; ++i) {
		newNums[i] = (nums[i] + nums[i+1]) % 10;
	}

	return solve(newNums);
}