#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
	cin >> n >> m;
	vector<vector<int>> pre1(n + 1, vector<int>(m + 1));
	vector<vector<int>> pre2(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char ch;
			cin >> ch;
			pre1[i][j] = pre1[i][j - 1] + pre1[i - 1][j] - pre1[i - 1][j - 1];
			pre2[i][j] = pre2[i][j - 1] + pre2[i - 1][j] - pre2[i - 1][j - 1];
			if((i + j) & 1){
				pre1[i][j] += (ch == '1');
				pre2[i][j] += (ch == '0');
			}else{
				pre1[i][j] += (ch == '0');
				pre2[i][j] += (ch == '1');
			}
		}
	}
	
// 	for(int i = 1; i <= n; i++){
// 		for(int j = 1; j <= m; j++){
// 			cout <<pre1[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
	int ans = 0;
	
	for (int i = 0; i <= n; ++i) {
	    for (int j = 0; j <= m; ++j) {
	        if (i>=8 and j >= 8) {
	            if ((pre1[i][j] - pre1[i-8][j] - pre1[i][j-8] + pre1[i-8][j-8] == 64) or 
	            pre2[i][j] - pre2[i-8][j] - pre2[i][j-8] + pre2[i-8][j-8] == 64) {
	                ans++;
	            }
	        }
	    }
	}
    cout << ans << endl;
}