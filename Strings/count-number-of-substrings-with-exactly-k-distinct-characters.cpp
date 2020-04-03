/*Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters.
The problem can be solved in O(n*n). Idea is to maintain a hash table while generating substring 
and checking the number of unique characters using that hash table.
The implementation below assume that the input string contains only characters from ‘a’ to ‘z’.*/

int countSubstring(string s) {

	int n = s.length();

	int cnt[26] = {};

	int res = 0, unique;

	REP(i, 0, n) {
		memset(cnt, 0, sizeof(cnt));
		unique = 0;

		REP(j, i, n) {

			if(cnt[s[j]-'a'] == 0) unique++;

			cnt[s[j]-'a']++;

			if(unique == k) res++;
		}
	}

	return res;
}

/* (Further Optimization):
The above code resets count array “cnt[]” in every iteration of outer loop. This can be very costly for large alphabet size. 
We can modify the above program such that cnt[] is not reset every time. Following is the way :*/

memset(cnt, 0, sizeof(cnt));

REP(i, 0, n) {
		
		unique = 0;

		REP(j, i, n) {

			if(cnt[s[j]-'a'] == i) unique++;

			cnt[s[j]-'a'] = i + 1;

			if(unique == k) res++;
		}
	}
