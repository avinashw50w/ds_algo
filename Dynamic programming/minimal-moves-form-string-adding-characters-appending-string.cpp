/*Minimal moves to form a string by adding characters or appending string itself
Given a string S, we need to write a program to check if it is possible to construct
 the given string S by performing any of the below operations any number of times. In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. We need to write a 
program to print the minimum steps required to form the string.

Examples:

Input : aaaaaaaa
Output : 4 
Explanation: move 1: add 'a' to form "a"
move 2: add 'a' to form "aa"
move 3: append "aa" to form "aaaa" 
move 4: append "aaaa" to form "aaaaaaaa" 

Input: aaaaaa
Output: 4 
Explanation: move 1: add 'a' to form "a"
move 2: add 'a' to form "aa"
move 3: add 'a' to form "aaa" 
move 4: append "aaa" to form "aaaaaa" 

Input: abcabca
Output: 5  */

/*The idea to solve this problem is to use Dynamic Programming to count the minimum number of moves. 
Create an array named dp of size n, where n is the length of the input string. dp[i] stores the 
minimum number of moves that are required to make substring (0…i). 
According to the question there are two moves that are possible:

dp[i] = min(dp[i], dp[i-1] + 1) which signifies addition of characters.
dp[i*2+1] = min(dp[i]+1, dp[i*2+1]), appending of string is done if s[0…i]==s[i+1..i*2+1]
The answer will be stored in dp[n-1] as we need to form the string(0..n-1) index-wise.*/


/* for reaching the state i, there are two choices:
come from state i-1 by adding a character

for reaching a state 2*i + 1, we must have come from state i by copying the string[0..i], there is one 
extra condition to check here, which is the string [0..i] and string[i+1...2i+1] should be equal
*/
int solve(string s) {

	int n = s.size();

	int dp[n];
	fill(dp, dp+n, INT_MAX);

	dp[0] = 1;
	string s1 = "", s2 = "";
	s1 += s[0];

	for (int i = 1; i < n; ++i) {

		s1 += s[i];
		s2 += s.substr(i+1, i+1);

		dp[i] = min(dp[i], dp[i-1] + 1);

		if (s1 == s2)
			dp[i*2 + 1] = min(dp[i*2 + 1], 1 + dp[i]);
	}

	return dp[n-1];
}