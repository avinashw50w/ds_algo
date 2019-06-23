/* Given an array a and its size n containing elements from 1 to n, some operations are done on the array:
1. pick a number and move it to the left one element at a time. lets say if n=8 and 5 is moved two times then
the array config will be 1,2,5,3,4,6,7,8, and the cost of moving the element will be 2
2. you cannot move an element more than 2 times. If the given config is such that an element is moved
more than 2 times, print 'Too chaotic'

q: an array of integers
Input Format

The first line contains an integer t, the number of test cases.

Each of the next t pairs of lines are as follows: 
- The first line contains an integer t, the number of people in the queue 
- The second line has n space-separated integers describing the final state of the queue.

Constraints
1 <= t <= 10
1 <= n <= 1e5

Output Format

Print an integer denoting the minimum number of operations needed to get the queue into its final state. 
Print Too chaotic if the state is invalid, i.e. it requires a person to have bribed more than  people.

Sample Input

2
5
2 1 5 3 4
5
2 5 1 3 4
Sample Output

3
Too chaotic */

const int maxn = 1e5 + 5;
int N, A[maxn];
int ans, invalid;

void init() {
	ans = invalid = 0;
	for (int i = 0; i < maxn; i++) {
		b[i] = 0;
	}
}

void upd(int x) {
	for (int i = x; i < maxn; i += (i&-i))
		b[i]++;
}

int getSum(int x) {
	int res = 0;
	for (int i = x; i > 0; i -= (i&-i))
		res += b[i];

	return res;
}


int main() {
	int T; cin >> T;

	while(T--) {
		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> A[i];

		for (int i = N-1; i >= 0; --i) {
			ans += getSum(a[i]);

			if (d > 2) invalid++;

			upd(a[i]);
		}

		if (invalid) {
			cout << "Too chaotic\n";
		} else {
			cout << ans << endl;
		}
	}	
}