/*Given an array of size n that has the following specifications:

Each element in the array contains either a policeman or a thief.
Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from the policeman.
We need to find the maximum number of thieves that can be caught.

Examples:

Input : arr[] = {'P', 'T', 'T', 'P', 'T'},
            k = 1.
Output : 2.
Here maximum 2 thieves can be caught, first
policeman catches first thief and second police-
man can catch either second or third thief.An efficient solution is to use a greedy algorithm. But which greedy property
to use can be tricky. We can try using: “For each policeman from the left catch the nearest possible thief.” This works for example three given above but fails for example two as it outputs 2 which is incorrect.
We may also try: “For each policeman from the left catch the farthest possible thief”. This works for example two given above but fails for example three as it outputs 2 which is incorrect. A symmetric argument can be applied to show that traversing for these from the right side of the array also fails. We can observe that thinking irrespective of the
policeman and focusing on just the allotment works:

1. Get the lowest index of policeman p and thief t. Make an allotment
if |p-t| <= k and increment to the next p and t found.
2. Otherwise increment min(p, t) to the next p or t found.
3. Repeat above two steps until next p and t are found.
4. Return the number of allotments made.*/

int solve(vector<char> a, int k) {
	vector<int> police, thief;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 'P') police.push_back(i);
		else thief.push_back(i);
	}

	int i = 0, j = 0;
	while (i < police.size() and j < thief.size()) {
		if (abs(police[i] - thief[j]) <= k) {
			ans++;
			i++;
			j++;
		}
		else if (police[i] < thief[j]) i++;
		else j++;
	}
}