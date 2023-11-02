/* https://cybergeeksquad.co/2023/03/two-sum-unique-pairs-solution-amazon-oa.html
Write a function that takes a list of numbers and a target number, and then returns the number of 
unique pairs that add up to the target number. [X, Y] and [Y, X] are considered the same pair, and not unique.
*/

int solve(vector<int> a, int target) {
	unordered_set<int> seen;
	int pairs = 0;

	for (int e: a) {
		if (seen.count(target-e) == 0) {
			pairs++;
			seen.insert(target-e);
		}
		seen.insert(e);
	}

	return pairs;
}