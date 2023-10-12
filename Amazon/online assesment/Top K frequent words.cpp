/* https://cybergeeksquad.co/2023/03/top-k-frequent-words-solution-amazon-oa.html
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. 
If two words have the same frequency, then the word with the lower alphabetical order comes first.

Input:  [“i”, “love”, “leetcode”, “i”, “love”, “coding”], k = 2
Output:  [“i”, “love”]

explanation:
- “i” and “love” are the two most frequent words.
- Note that “i” comes before “love” due to a lower alphabetical order.
*/


auto cmp = [](auto &a, auto &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<string> solve(vector<string> words) {
	unordered_map<string, int> mp;
	for (string word: words) mp[word]++;

	vector<pair<string, int>> sortedWords(mp.begin(), mp.end());

	sort(sortedWords.begin(), sortedWords.end(), cmp);

	vector<string> res;
	for (int i = 0; i < k; ++i) {
		res.push_back(sortedWords[i].first);
	}

	return res;
}