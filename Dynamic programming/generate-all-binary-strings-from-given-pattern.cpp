/*Generate all binary strings from given pattern
Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters, generate all binary strings that can be formed by replacing each wildcard character by ‘0’ or ‘1’.

Input str = "1??0?101"
Output: 
        10000101
        10001101
        10100101
        10101101
        11000101
        11001101
        11100101
        11101101 */

// Method 1 : Recursion 


void printStr(string s, int idx) {
	if(idx == s.size()) {
		cout << s << endl;
		return;
	}

	if(s[idx] == '?') {

		s[idx] = '0';
		printStr(s, idx+1);

		s[idx] = '1';
		printStr(s, idx+1);
	}

	printStr(s, idx+1);
}

int main() {
	string str = "1??0?101";

	printStr(str, 0);
}

///////////////////////////////////////////////////////////////////
// Method 2: using queue

void solve(string s) {
	queue<string> q;
	q.push(s);

	while(!q.empty()) {

		string str = q.front();
		q.pop();

		size_t idx = str.find('?');

		if(idx != string::npos) {

			str[idx] = '0';
			q.push(str);

			str[idx] = '1';
			q.push(str);
		}

		else cout << str << endl;`
	}
}