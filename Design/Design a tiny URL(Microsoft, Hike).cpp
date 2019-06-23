/*Design a system that takes big URLs like “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and 
converts them into a short 6 character URL. It is given that URLs are stored in database and every URL has an associated integer id.  
So your program should take an integer id and generate a 6 character long URL. 

A URL character can be one of the following
1) A lower case alphabet [‘a’ to ‘z’], total 26 characters
2) An upper case alphabet [‘A’ to ‘Z’], total 26 characters
3) A digit [‘0′ to ‘9’], total 10 characters

There are total 26 + 26 + 10 = 62 possible characters.

So the task is to convert an integer (database id) to a base 62 number where digits of 62 base are 
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

Input:

The first line of input contains an integer T denoting the number of test cases.

And the second line consists of a long integer.


Output:

Print the shortened string in the first line and convert the shortened string back to ID 
(to make sure that your conversion works fine) and print that in the second line.

Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 4,294,967,295

Input:

1
12345

Output:

dnh
12345  */ 
#include <bits/stdc++.h>
using namespace std;

const char* toURL(int N) {

	string l = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string res = "";
	while(N) {
		res = l[N % 62] + res;
		N /= 62;
	}

	return res.c_str();
}

int toID(const char *s) {
	int mul = 1, res = 0;

	for(int i = strlen(s)-1; i >= 0; --i) {
		int c;
		if('a'<=s[i] and s[i]<='z') c = s[i]-'a';
		else if('A'<=s[i] and s[i]<='Z') c = s[i]-'A'+26;
		else c = s[i]-'0'+26+26;
		
		res += mul*c;
		mul *= 62;
	}

	return res;
}

int main() {
	const char *s = toURL(12345);
	cout << s << endl;

	int id = toID(s);
	cout << id << endl;
}