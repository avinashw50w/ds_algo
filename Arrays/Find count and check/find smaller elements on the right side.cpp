// given an array of integers find for each element a[i] in the array the number of elements smaller than a[i] 
// which are lying on the right side of it
// eg input : 2 7 5 3 0 8 1
// output   : 2 4 3 2 0 1 0  

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int bit[maxn];

void update(int i, int x) {
    for (; i < maxn; i += (i & -i)) bit[i] += x;
}

int sum(int i) {
    int res = 0;
    for (; i > 0; i -= (i&-i)) res += bit[i];
    return res;
}


void solve(int a[], int N){
    
    int s = 0;
    int b[N];
    memset(b, 0, sizeof(b));
    b[N-1] = 0;
    
    update(a[N-1], 1);
    for (int i = N-2; i >= 0; --i) {
        if (a[i] != 0) {
            update(a[i], 1);
          	
            b[i] = sum(a[i]-1) + s;
        }
        else s++;
    }

    for (int i=0;i<N;++i) cout <<b[i]<<" ";
}

////////////////////////////////////////////////////////
// another method using multiset

void solve1(int a[], int N) {
    multiset<int> s;
    s.insert(a[N-1]);

    int res[N];
    memset(res, 0, sizeof(res));

    for (int i=N-1; i >= 0; --i) {
        s.insert(a[i]);
        int l = distance(s.begin(), s.lower_bound(a[i]));
        res[i] = l;
    }

    for (int i = 0; i < N; ++i) cout << res[i] <<" ";
}

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    solve(a, N);

    return 0;
}

