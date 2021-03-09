// custom comparator in set
auto cmp = [](int a, int b) {return a > b;};
set < int, decltype(cmp) > st(cmp);

// priority queue
// max heap
priority_queue<int> q;
// min heap
priority_queue<int, vector<int>, greater<int>> q;
// for custom type T
// custom comparator in priority queue
auto cmp = [](const auto &a, const auto &b) { return a.val > b.val; };
priority_queue<T, vector<T>, decltype(cmp)> q(cmp);


// map is faster than unordered_map if unordered_map is not resized initially.

array<int, 3> a = { 1, 2, 3 };
// a[0] = 1, a[2] = 2, a[3] = 3

vector<array<int, 3>> v;
v.push_back({ 1, 2, 3 });
// c++17, output: 1 2 3
for (auto [a, b, c] : v) cout << a << " " << b << " " << c << endl;
// c++11
for (auto e : v) cout << e[0] << " " << e[1] << " " << e[2];