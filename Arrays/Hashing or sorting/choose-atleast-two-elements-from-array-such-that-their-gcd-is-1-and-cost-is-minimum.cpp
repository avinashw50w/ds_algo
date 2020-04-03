/*Choose atleast two elements from array such that their GCD is 1 and cost is minimum
Given two integer arrays arr[] and cost[] where cost[i] is the cost of choosing arr[i]. 
The task is to choose a subset with at least two elements such that the GCD of all the elements 
from the subset is 1 and the cost of choosing those elements is as minimum as possible then print the minimum cost.

Examples:

Input: arr[] = {5, 10, 12, 1}, cost[] = {2, 1, 2, 6}
Output: 4
{5, 12} is the required subset with cost = 2 + 2 = 4

Input: arr[] = {50, 100, 150, 200, 300}, cost[] = {2, 3, 4, 5, 6}
Output: -1
No subset possible with gcd = 1

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: Add GCD of any two elements to a map, now for every element arr[i] calculate its 
gcd with all the gcd values found so far (saved in the map) and update map[gcd] = min(map[gcd],
 map[gcd] + cost[i]). If in the end, map doesn’t contain any entry for gcd = 1 
 then print -1 else print the stored minimum cost.*/

int solve(int a[], int cost[], int n) {
	map<int,int> mp; // [gcd] => [cost] mapping
	m[0] = 0;
	int gcd;

	for (int i = 0; i < n; ++i) {
		for (auto it: m) {
			gcd = __gcd(a[i], it.first);

			if (m.count(gcd))
				m[gcd] = min(m[gcd], it.second + cost[i]);
			else
				m[gcd] = it.second + cost[i];
		}
	}

	return m[1] == 0 ? -1 : m[1];
}

