#include <iostream>
using namespace std;

struct PalindromicTree {

	const int MAXN = 1e5;
	const int CHARSZ = 26;

	int s[MAXN], len[MAXN], link[MAXN], to[MAXN][CHARSZ];

	int N, last, sz;

	void init() 
	{
		sz = last = 1, N = 0;
		s[0] = -1;
		len[1] = -1;
		link[0] = link[1] = 1;
	}

	void getLink(v) 
	{
		while(s[N] != s[N - len[v] - 1]) v = link[v];
		return v;
	}

	void add(int c)
	{
		s[++N] = c;
		int curr = getLink(last);

		if(!to[curr][c])
		{
			link[++sz] = to[getLink(link[curr])][c];
			len[sz] = len[curr] + 2;
			to[curr][c] = sz;
		}

		last = to[curr][c];
	}
}

