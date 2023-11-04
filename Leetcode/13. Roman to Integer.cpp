/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.*/

class Solution {
public:
	int romanToInt(string s) {
		int ans = 0;
		unordered_map<char, int> mp;
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;

		int i = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			ans += mp[s[i]];
			if (i < s.size() - 1) {
				if (s[i] == 'I' and s[i + 1] == 'V') ans = ans - 6 + 4;
				if (s[i] == 'I' and s[i + 1] == 'X') ans = ans - 11 + 9;
				if (s[i] == 'X' and s[i + 1] == 'L') ans = ans - 60 + 40;
				if (s[i] == 'X' and s[i + 1] == 'C') ans = ans - 110 + 90;
				if (s[i] == 'C' and s[i + 1] == 'D') ans = ans - 600 + 400;
				if (s[i] == 'C' and s[i + 1] == 'M') ans = ans - 1100 + 900;
			}
		}
		return ans;
	}
};

// another simple approach

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
		unordered_map<char, int> mp;
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;
		// cases IV, IX
		// XL, XC
		// CD, CM
		// in each of these case the first char value is less than the second second char value
		// and its contribution to the sum is mp[second char] - mp[first char]
        for (int i = 0; i < s.length(); ++i) {
            if (mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        }

        return ans;
    }
};