/*Given an integer target and an array arr[] consisting of N positive integers where arr[i]
denotes the time required to score 1 point for the ith array element, the task is to find the
minimum time required to obtain the score target from the given array.
eg. a = [2, 3, 4] target = 20
output : 20
explanation: at T=20, total score = 20/2 + 20/3 + 20/4 = 10 + 6 + 5 = 21 <= 20
*/

int solve(vector<int> a, int target) {
	int sum = 0, t = 0;

	while (sum < target) {
		t++;
		sum = 0;
		for (int e : a) sum += t / e;
	}

	return t;
}

//////////////////////////////////
// optimise space by taking frequency map

int solve(vector<int> a, int target) {
	unordered_map<int, int> f;
	for (int e : a) f[e]++;

	int sum = 0, t = 0;
	while (sum < target) {
		sum = 0;
		t++;
		for (auto p : f)
			sum += p.second * (t / p.first);
	}

	return t;
}