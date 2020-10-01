/*Vova decided to clean his room. The room can be represented as the coordinate axis 𝑂𝑋. There are 𝑛 piles of trash in the room, coordinate of the 𝑖-th pile is the integer 𝑝𝑖. All piles have different coordinates.

Let's define a total cleanup as the following process. The goal of this process is to collect all the piles in no more than two different 𝑥 coordinates. To achieve this goal, Vova can do several (possibly, zero) moves. During one move, he can choose some 𝑥 and move all piles from 𝑥 to 𝑥+1 or 𝑥−1 using his broom. Note that he can't choose how many piles he will move.

Also, there are two types of queries:

0 𝑥 — remove a pile of trash from the coordinate 𝑥. It is guaranteed that there is a pile in the coordinate 𝑥 at this moment.
1 𝑥 — add a pile of trash to the coordinate 𝑥. It is guaranteed that there is no pile in the coordinate 𝑥 at this moment.
Note that it is possible that there are zero piles of trash in the room at some moment.

Vova wants to know the minimum number of moves he can spend if he wants to do a total cleanup before any queries. He also wants to know this number of moves after applying each query. Queries are applied in the given order. Note that the total cleanup doesn't actually happen and doesn't change the state of piles. It is only used to calculate the number of moves.

For better understanding, please read the Notes section below to see an explanation for the first example.

Input
The first line of the input contains two integers 𝑛 and 𝑞 (1≤𝑛,𝑞≤105) — the number of piles in the room before all queries and the number of queries, respectively.

The second line of the input contains 𝑛 distinct integers 𝑝1,𝑝2,…,𝑝𝑛 (1≤𝑝𝑖≤109), where 𝑝𝑖 is the coordinate of the 𝑖-th pile.

The next 𝑞 lines describe queries. The 𝑖-th query is described with two integers 𝑡𝑖 and 𝑥𝑖 (0≤𝑡𝑖≤1;1≤𝑥𝑖≤109), where 𝑡𝑖 is 0 if you need to remove a pile from the coordinate 𝑥𝑖 and is 1 if you need to add a pile to the coordinate 𝑥𝑖. It is guaranteed that for 𝑡𝑖=0 there is such pile in the current set of piles and for 𝑡𝑖=1 there is no such pile in the current set of piles.

Output
Print 𝑞+1 integers: the minimum number of moves Vova needs to do a total cleanup before the first query and after each of 𝑞 queries.

Examples
inputCopy
5 6
1 2 6 8 10
1 4
1 9
0 6
0 10
1 100
1 50
outputCopy
5
7
7
5
4
8
49*/

/**
 * let the coordinates of the piles be p0 < p1 < p2 < ... < pn-1
 * the minimum no of moves required to sweep all the piles into one place = pn-1 - p0,
 * how ? keep sweeping the piles from the right end to the left end, and since in one move we can sweep the
 * pile at x to x-1 to the left, so a total of (pn-1 - p0) moves are needed
 *
 * Now to move all the piles into two points:
 * find a border position i, such that all the piles from p0 ... pi-1 are moved to one point
 * and the remaining piles from pi ... pn-1 are moved to the other point
 * so we need a total of (pi-1 - p0) + (pn-1 - pi) moves
 * (pn-1 - p0) - (pi - pi-1) moves
 * the first part (pn-1 - p0) is a constant, the only variable part is (pi - pi-1)
 * so we need to maintain the consecutive coordinates difference when a new coordinate is added or removed
 */
int main() {
	int n, q;
	cin >> n >> q;
	set<int> p;
	multiset<int> d;

	auto Add = [&](int x) {
		auto ret = p.insert(x);
		assert(ret.second);

		auto it = ret.first;
		if (it != p.begin() and next(it) != p.end()) {
			d.erase(d.find(*next(it) - *prev(it)));
		}

		if (next(it) != p.end()) {
			d.insert(*next(it) - *it);
		}

		if (it != p.begin()) {
			d.insert(*it - *prev(it));
		}
	}

	auto Remove = [&](int x) {
		auto it = p.find(x);
		assert(it != p.end());

		if (next(it) != p.end()) {
			d.erase(d.find(*next(it) - *it));
		}

		if (it != p.begin()) {
			d.erase(d.find(*it - *prev(it)));
		}

		if (it != p.begin() and next(it) != p.end()) {
			d.insert(*next(it) - *prev(it));
		}

		p.erase(it);
	}

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		Add(x);
	}

	for (int qq = 0; qq <= q; ++qq) {

		if (d.empty()) {
			cout << 0 << "\n";
		}
		else {
			int max_p = *prev(p.end());
			int min_p = *p.begin();
			int max_d = *prev(d.end());
			cout << max_p - min_p - max_d << "\n";
		}
		if (qq == q) break;

		int t, x;
		cin >> t >> x;
		if (t == 0) {
			Remove(x);
		}
		else {
			Add(x);
		}
	}
}