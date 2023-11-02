/*
Given an array of positive(non zero) and -ve integers representing the id of a book to be added to the inventory.
When a[i] is +ve, the book is added and when its -ve then it is removed from the inventory.
Return the maximum copies of any book in the inventory after each update.
*/

// use set to update the maximum
int solve(vector<int> updates) {
	set<array<int,2>> st;
	unordered_map<int, int> freq;
	int n = update.size();

	for (int e: update) {
		if (e > 0) {
			freq[e]++;
			st.insert({freq[e], e});
		} else {
			st.erase({freq[e], e});
			freq[e]--;
			st.insert({freq[e], e});
		}
	}

	return (*st.rbegin())[0];
}