/*Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. 
Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent 
characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
      isWord(str): returns true if str is present in dictionary
                   else false.

Output:  Following words of dictionary are present
         GEEKS
         QUIZ*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;

char mat[maxn][maxn];
int vis[maxn][maxn];
set<string> dict, ans;
int X, N, M;

void solve(int x, int y, string &s)
{
	vis[x][y] = 1;
	s += mat[x][y];

	if(dict.count(s)) {
		ans.insert(s);
	}

	for(int i = x-1; i <= x+1 and i < N; ++i)
		for(int j = y-1; j <= y+1 and j < M; ++j) {
			if(i >= 0 and j >= 0 and !vis[i][j])
				solve(i, j, s);
		}

	// backtrack
	s.erase(s.length() - 1);
	vis[x][y] = 0;
}

int main() {
	int t; cin >> t;

	while(t--)
	{
		dict.clear();
		ans.clear();

		cin >> X;

		while(X--)
		{
			string s;
			cin >> s;
			dict.insert(s);
		}

		cin >> N >> M;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) cin >> mat[i][j];

		memset(vis, 0, sizeof(vis));

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) {
				string s = "";
				solve(i, j, s);
			}

		for(auto w: ans) cout << w << endl;
	}
}