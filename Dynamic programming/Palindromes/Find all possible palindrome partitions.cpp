/*Given a string, print all possible palindromic partitions
Given a string, find all possible palindromic partitions of given string.

ex:
input : nitin
Output: n i t i n
		n iti n
		nitin

We strongly recommend you to minimize your browser and try this yourself first.

Note that this problem is different from Palindrome Partitioning Problem, there the 
task was to find the partitioning with minimum cuts in input string. Here we need to print all possible partitions.

The idea is to go through every substring starting from first character, check if it is palindrome. 
If yes, then add the substring to solution and recur for remaining part. Below is complete algorithm.*/

bool isPalindrome(string S, int l, int r) {
	while(l < r) {
		if(S[l] != S[r]) return false;
		++l; --r;
	}
	return true;
}

void solve(vector< vector<string> > &allPart, vector<string> &currPart, int start, int N, string S)
{
	if(start >= N) {
		allPart.push_back(currPart);
		return;
	}

	REP(i, start, N)
	{
		if(isPalindrome(S, start, i))
		{
			currPart.push_back(S.substr(start, i-start+1));

			solve(allPart, currPart, i+1, N, S);

			currPart.pop_back();
		}
	}
}

// returns a 2D array containing all possible palidrome partitions
vector< vector<string> > allPalPartitions(string S) {

	int N = S.length();

	vector< vector<string> > allPart;
	vector< string > currPart;

	solve(allPart, currPart, 0, N, S);

	return allPart;
}
