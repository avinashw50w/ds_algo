/*Given a string S of length N containing only lowercase english letters, 
find the subtring of the maximum length which contains only vowels*/

#include <iostream>
using namespace std;

int main() {
	string S;

	cin >> S;

	int N = S.length();

	int ans = 0, cnt = 0;

	for(int i = 0; i < N; ++i) {
		char c = S[i];
		if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
			cnt++;
			ans = max(ans, cnt);
		}
		else {
			cnt = 0;
		}
	}

	cout << ans << endl;
}