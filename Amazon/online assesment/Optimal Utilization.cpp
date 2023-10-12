/* https://cybergeeksquad.co/2023/03/optimal-utilization-solution-amazon-oa.html
Given 2 lists a and b. Each element is a pair of integers where the first integer represents the unique id and 
the second integer represents a value. Your task is to find an element from a and an element form b such that 
the sum of their values is less or equal to target and as close to target as possible. 
Return a list of ids of selected elements. If no pair is possible, return an empty list.

input:
a = [[1, 2], [2, 4], [3, 6]]
b = [[1, 2]]
target = 7
Output: [2, 1]
*/

auto comp = [](auto &a auto &b) { return a[1] < b[1]; };

vector<int> solve(vector<vector<int>> a, vector<vector<int>> b, int target) {
	sort(a.begin(), a.end(), comp);
	sort(b.begin(), b.end(), comp);
	vector<int> res(2, -1);

	int n = a.size(), m = b.size(), i = 0, j = m-1;

	int maxSum = INT_MAX;

	while (i < n and j >= 0) {
		int sum = a[i][1] + b[j][1];
		if (sum > target) j--;
		else {
			if (sum > maxSum) {
				maxSum = sum;
				res[0] = a[i][0];
				res[1] = b[j][0];
			}
			a++;
		}
	}

	return res;
}
