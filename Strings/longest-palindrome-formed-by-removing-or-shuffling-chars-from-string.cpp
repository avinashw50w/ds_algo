/*Find longest palindrome formed by removing or shuffling chars from string
Given a string, find the longest palindrome that can be constructed by removing or shuffling characters from the string. 
Return only one palindrome if there are multiple palindrome strings of longest length.

The idea is to use above observation in our solution. As shuffling of characters is allowed, order of characters doesn’t matter in the input string. 
We first get frequency of each character in the input string. Then all characters having even occurrence (say 2n) in the input string will be 
part of the output string as we can easily place n characters in ‘beg’ string and the other n characters in the ‘end’ string (by preserving 
the palindromic order). For characters having odd occurrence (say 2n + 1), we fill ‘mid’ with one of all such characters. and remaining 2n 
characters are divided in halves and added at beginning and end.*/

string longestPalindrome(string s) {

	int n = s.lenght();

	int cnt[26] = {};

	REP(i, 0, n) cnt[s[i]-'a']++;


	string beg = "", mid = "", end = "";

	REP(i, 0, 26) {

		if(cnt[i] & 1) {

			mid = i+'a';
			// decrement the character freq to make
            // it even and consider current character
            // again
			cnt[i--]--;
		}

		else {

			REP(j, 0, cnt[i]/2) 
				beg += j+'a';
		}
	}

	end = beg;

	reverse(end.begin(), end.end());

	return (beg + mid + end);
}