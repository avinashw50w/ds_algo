/*You and your friend are playing the game Mortal Kombat XI. You are trying to pass a challenge tower. There are 𝑛 bosses in this tower, numbered from 1 to 𝑛. The type of the 𝑖-th boss is 𝑎𝑖. If the 𝑖-th boss is easy then its type is 𝑎𝑖=0, otherwise this boss is hard and its type is 𝑎𝑖=1.

During one session, either you or your friend can kill one or two bosses (neither you nor your friend can skip the session, so the minimum number of bosses killed during one session is at least one). After your friend session, your session begins, then again your friend session begins, your session begins, and so on. The first session is your friend's session.

Your friend needs to get good because he can't actually kill hard bosses. To kill them, he uses skip points. One skip point can be used to kill one hard boss.

Your task is to find the minimum number of skip points your friend needs to use so you and your friend kill all 𝑛 bosses in the given order.

For example: suppose 𝑛=8, 𝑎=[1,0,1,1,0,1,1,1]. Then the best course of action is the following:

your friend kills two first bosses, using one skip point for the first boss;
you kill the third and the fourth bosses;
your friend kills the fifth boss;
you kill the sixth and the seventh bosses;
your friend kills the last boss, using one skip point, so the tower is completed using two skip points.
You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤2⋅104) — the number of test cases. Then 𝑡 test cases follow.

The first line of the test case contains one integer 𝑛 (1≤𝑛≤2⋅105) — the number of bosses. The second line of the test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤1), where 𝑎𝑖 is the type of the 𝑖-th boss.

It is guaranteed that the sum of 𝑛 does not exceed 2⋅105 (∑𝑛≤2⋅105).

Output
For each test case, print the answer: the minimum number of skip points your friend needs to use so you and your friend kill all 𝑛 bosses in the given order.

Example
inputCopy
6
8
1 0 1 1 0 1 1 1
5
1 1 1 1 0
7
1 1 1 1 0 0 1
6
1 1 1 1 1 1
1
1
1
0
outputCopy
2
2
2
2
1
0*/

int main() {
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		/**
		 * him[i] = the minimum # of skip points need to kill all the bosses from i..n if it's our friend's turn
		 * us[i]  =                     .........                                      if it's our turn
		 */
		vector<int> him(n + 2, 0), us(n + 2, 0);

		for (int i = n - 1; i >= 0; --i) {
			{	// calculate him[i]
				him[i] = us[i + 1] + a[i];
				him[i] = min(him[i], us[i + 2] + a[i] + a[i + 1]);
			}
			{	// calculate us[i]
				us[i] = him[i + 1];
				us[i] = min(us[i], him[i + 2]);
			}
		}

		// since out friend started first, so the ans will be him[0]
		cout << him[0] << "\n";
	}
}