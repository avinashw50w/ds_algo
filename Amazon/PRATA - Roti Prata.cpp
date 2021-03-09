/*The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed
for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8).
A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R
minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example
if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins
an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes
also he can cook only 3 pratas as he does not have enough time for the 4th prata). The
webmaster wants to know the minimum time to get the order done. Please write a program to help
him out.



Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first
line of the test case we have P the number of prata ordered. In the next line the first integer
denotes the number of cooks L and L integers follow in the same line each denoting the rank of
a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.
IDEA: binary search the time required
*/

const int maxn = 51;
int rank[maxn];
int p;
// check if p pratas can be made in m time
bool check(int m) {
	int pratas = 0;
	for (int i = 0; i < cooks; ++i) {
		int time = 0, j = 1;
		while (time + j * rank[i] <= m) {
			time += j * rank[i];
			pratas++;
			j++;
		}
	}

	return pratas >= p;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> p;
		cin >> cooks;
		int mx = -1e9;
		for (int i = 0; i < cooks; ++i) {
			cin >> rank[i];
			mx = max(mx, rank[i]);
		}

		int l = 0, r = (1000 * (1001) / 2) * 8; // 8 + 2*8 + 3*8 + ... + 1000*8

		while (l < r) {
			int m = l + (r - l) / 2;
			if (check(m)) r = m;
			else l = m + 1;
		}

		return l;
	}
}