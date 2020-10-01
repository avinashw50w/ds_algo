/**You are playing a computer game. In this game, you have to fight 𝑛 monsters.

To defend from monsters, you need a shield. Each shield has two parameters: its current durability 𝑎 and its defence rating 𝑏. Each monster has only one parameter: its strength 𝑑.

When you fight a monster with strength 𝑑 while having a shield with current durability 𝑎 and defence 𝑏, there are three possible outcomes:

if 𝑎=0, then you receive 𝑑 damage;
if 𝑎>0 and 𝑑≥𝑏, you receive no damage, but the current durability of the shield decreases by 1;
if 𝑎>0 and 𝑑<𝑏, nothing happens.
The 𝑖-th monster has strength 𝑑𝑖, and you will fight each of the monsters exactly once, in some random order (all 𝑛! orders are equiprobable). You have to consider 𝑚 different shields, the 𝑖-th shield has initial durability 𝑎𝑖 and defence rating 𝑏𝑖. For each shield, calculate the expected amount of damage you will receive if you take this shield and fight the given 𝑛 monsters in random order.

Input
The first line contains two integers 𝑛 and 𝑚 (1≤𝑛,𝑚≤2⋅105) — the number of monsters and the number of shields, respectively.

The second line contains 𝑛 integers 𝑑1, 𝑑2, ..., 𝑑𝑛 (1≤𝑑𝑖≤109), where 𝑑𝑖 is the strength of the 𝑖-th monster.

Then 𝑚 lines follow, the 𝑖-th of them contains two integers 𝑎𝑖 and 𝑏𝑖 (1≤𝑎𝑖≤𝑛; 1≤𝑏𝑖≤109) — the description of the 𝑖-th shield.

Output
Print 𝑚 integers, where the 𝑖-th integer represents the expected damage you receive with the 𝑖-th shield as follows: it can be proven that, for each shield, the expected damage is an irreducible fraction 𝑥𝑦, where 𝑦 is coprime with 998244353. You have to print the value of 𝑥⋅𝑦−1mod998244353, where 𝑦−1 is the inverse element for 𝑦 (𝑦⋅𝑦−1mod998244353=1).*/

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }

	ModInt operator/=(ModInt rhs) {
		static const ll inv2 = ModInt(2).inv().x;
		ll i = (rhs.x == 2 ? inv2 : rhs.inv().x);
		x = x * i % MOD; return *this;
	}
	ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
	ModInt inv() { return pow(MOD - 2); }
	ModInt pow(ll n) const {
		ModInt r = 1, t = x;
		for (; n; n >>= 1, t *= t) if (n & 1) r *= t;
		return r;
	}
};
typedef ModInt<998244353> Mint;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	for (int &x : d) cin >> x;

	sort(d.begin(), d.end());
	vector<Mint> prefix(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		prefix[i + 1] = prefix[i] + d[i];
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		int pos = (int) (lower_bound(d.begin(), d.end(), b) - d.begin());
		int strong_monsters = n - pos;

		if (strong_monsters < a) {
			cout << 0 << "\n";
			continue;
		}
		/**
		 * a strong monster is one who can deal damage and reduce the value of "a" by 1
		 * if no of strong monsters >= a, then we can get damage only after encountering "a" strong monsters
		 * because each strong monster reduces the value of "a" by 1 and when a = 0, then we receive damage
		 * So, the probability of getting damage from a strong monster, pi = (strong_monsters - a) / strong_monsters
		 * the expected damage recieved after fighting ith strong monster = d[i] * pi
		 * by linearity of expectation, the damage recieved after fighting all the strong monsters =
		 * (sum of damages dealt by the strong monsters) * pi
		 */
		Mint damage_from_strong_monsters = (prefix[n] - prefix[pos]) * (strong_monsters - a) / strong_monsters;
		/**
		 * A weak monster can deal damage only if it comes after the ath strong monster
		 * we have to find the probability that a weak monster comes after the ath strong monster
		 * if there are x no of strong monsters, then there are x + 1 positions in between these strong monsters
		 * where a weak monster can come.
		 * probability that a weak monster comes after the ath strong monster = (x + 1 - a) / (x + 1)
		 * now the expected damage from weak monsters = (sum of damages by all weak monsters) * (x + 1 - a) / (x + 1)
		 */
		Mint damage_from_weak_monsters = prefix[pos] * (strong_monsters - a + 1) / (strong_monsters + 1);

		cout << damage_from_weak_monsters + damage_from_strong_monsters << " \n";
	}
}

//////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 2e5 + 5;
int n, m, i, d[N], a, b, inv[N], ps[N], ss[N];
int main() {
	for (i = 1; i < N; ++i) inv[i] = i == 1 ? 1 : 1ll * (mod - mod / i) * inv[mod % i] % mod;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) scanf("%d", d + i);
	sort(d + 1, d + n + 1);
	for (i = 1; i <= n; ++i) ps[i] = (ps[i - 1] + d[i]) % mod;
	for (i = n; i; --i) ss[i] = (ss[i + 1] + d[i]) % mod;
	for (; m--;) {
		scanf("%d%d", &a, &b);
		b = d + n + 1 - lower_bound(d + 1, d + n + 1, b);
		a = a > b ? 0 : (1ll * inv[b + 1] * (b + 1 - a) % mod * ps[n - b]
		                 + 1ll * inv[b] * (b - a) % mod * ss[n - b + 1]) % mod;
		printf("%d\n", a);
	}
}