#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 10000;
int p[MAXN];

void sieve() {
	long long i, j;
	for (i = 2; i * i <= MAX; i++) {
		if (!p[i]) {
			p[i] = i;
			for (j = 2 * i; j <= MAX; j += i)  // assign the value p to all the multiples of p.Here p is a prime no.
				p[j] = i;
		}
	}
	while (i <= MAXN) {
		if (!p[i]) p[i] = i;
		i++;
	}
}

vector<int> factorise(int n) {
	vector<int> res;
	while (n > 1) {
		res.push_back(p[n]);
		n /= p[n];
	}
	return res;
}

int main() {
	int n;
	vector<int> factors;
	sieve();
	do {
		cin >> n;
		factors = factorise(n);
		for (int i = 0; i < factors.size(); i++) cout << factors[i] << " ";
		cout << endl;
		factors.clear();
	} while (n);
	return 0;
}
