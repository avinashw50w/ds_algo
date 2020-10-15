// given an array of integers find for each element a[i] in the array the number of elements smaller than a[i]
// which are lying on the right side of it
// eg input : 2 7 5 3 0 8 1
// output   : 2 4 3 2 0 1 0

// time complexity: O(NlogN)
// an interesting problem : new year chaos (in competitive problems folder in this directory)
const int maxn = 1e5 + 5;
int bit[maxn];

void update(int i, int x) {
    for (; i < maxn; i += (i & -i)) bit[i] += x;
}

int sum(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

vector<int> solve(vector<int> a) {

    int zeroes = 0, N = a.size();
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());

    // update array elements to be in the range [1, N]
    for (int i = 0; i < N; ++i) {
        int d = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        a[i] = d + 1;
    }

    vector<int> res(N);
    res[N - 1] = 0;

    update(a[N - 1], 1);

    for (int i = N - 2; i >= 0; --i) {
        update(a[i], 1);
        res[i] = sum(a[i] - 1);
    }

    return res;
}

////////////////////////////////////////////////////////
// another method using multiset
// complexity: O(N^2) , the distance function takes O(N)
// works better than the naive algorithm in the average case.
void solve1(int a[], int N) {
    multiset<int> s;
    s.insert(a[N - 1]);

    int res[N];
    memset(res, 0, sizeof(res));

    for (int i = N - 1; i >= 0; --i) {
        s.insert(a[i]);
        int l = distance(s.begin(), s.lower_bound(a[i]));
        res[i] = l;
    }

    for (int i = 0; i < N; ++i) cout << res[i] << " ";
}
// a brute force solution
vector<int> solve(vector<int> a) {
    int n = a.size();
    vector<int> res(n, 0);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                res[i]++;
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    solve(a, N);

    return 0;
}

