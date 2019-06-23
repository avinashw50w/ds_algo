/*Facebook Hacker Cup 2015 Round 1
Since you crave state-of-the-art technology, you've just purchased a phone with a great new feature: autocomplete!

Your phone's version of autocomplete has some pros and cons. On the one hand, it's very cautious. It only autocompletes a 
word when it knows exactly what you're trying to write. On the other hand, you have to teach it every word you want to use.

You have N distinct words that you'd like to send in a text message in order. Before sending each word, you add it to your 
phone's dictionary. Then, you write the smallest non-empty prefix of the word necessary for your phone to autocomplete the word. 
This prefix must either be the whole word, or a prefix which is not a prefix of any other word yet in the dictionary.

What's the minimum number of letters you must type to send all N words?

Input
Input begins with an integer T, the number of test cases. For each test case, there is first a line containing the integer N. 
Then, NN lines follow, each containing a word to send in the order you wish to send them.

Output
For the ithith test case, print a line containing Case #i: followed by the minimum number of characters you need to type 
in your text message.

Constraints
1≤T≤100
1≤N≤100000

The N words will have a total length of no more than 1000000 characters. 
The words are made up of only lower-case alphabetic characters. 
The words are pairwise distinct. 

NOTE: The input file is about 10-20MB.

Explanation of Sample
In the first test case, you will write h, he, l, hil, hill, for a total of 1+2+1+3+4=11 characters.

Sample Input
Copy
5
5
hi
hello
lol
hills
hill*/

#include <iostream>
using namespace std;

const int maxn = 1e6 + 2;
int trie[maxn][26+2];

void solve() {
	memset(trie, 0, sizeof(trie));

	int N; cin >> N;
	string word;
	int ans = 0, num = 1;

	while(N--) {
		cin >> word;

		int node = 0, idx = 0;

		while(trie[node][word[idx] - 'a'] && idx < word.size()) {
			node = trie[node][word[idx] - 'a'];
			ans++; idx++;
		}

		if(idx < word.size()) ans++;

		for(; idx < word.size(); ++idx) {
			node = trie[node][word[idx] - 'a'] = num++;
		}
	}

	cout << ans << endl;
}

int main() {
	int T; cin >> T;

	while(T--)
	{
		solve();
	}
}