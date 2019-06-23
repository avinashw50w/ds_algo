/*Given three numbers a, b and m. All are int range of long long int. Find (a * b) mod m.

Note that multiplying a with b directly can lead to a result which is out of range of long long int.

Idea : (a * b) % m = (a * b/2) % m + (a * b/2) % m. 
So we can calculate a * b recursively*/

typedef long long ll;

ll multiply(ll a, ll b, ll m) {
	if (b == 0) return 0;

	ll x = multiply(a, b>>1, m);

	x = (x + x) % m;

	if (b & 1) x = (x + a) % m;

	return x % m;
}