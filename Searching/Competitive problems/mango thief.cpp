/*IN A VILLAGE THERE IS A MERCHANT WHO OWNS MANY MANGO TREES ( M ) AND EACH MANGO TREE HAS BOUNDARY WHICH HAS SOME HEIGHT (H) . THERE ARE SOME CHILDREN ( N ) IN THE VILLAGE WHO WANT TO STEAL MANGO BUT FOR STEALING HE HAS TO CLEAR THE BOUNDARY.

NOW , YOU WILL BE GIVEN THE JUMPING POWER OF ALL THE CHILDREN AND HEIGHT OF EACH BOUNDRY WITH NUMBER OF MANGOES ON THE TREE.

YOU HAVE TO CALCULATE HOW MANY MANGOES THE CHILDREN IS GOING TO STEAL.

INPUT :
    FIRST LINE WILL CONTAIN TWO INTEGER  N AND M SHOWING NUMBER OF CHILDREN AND NUMBER OF MANGO TREE RESPECTIVELY.
    NEXT LINE WILL GIVE THE JUMPING POWER OF EACH CHILDREN .
    NEXT M LINE WILL GIVE BOUNDARY HEIGHT AND NUMBERS OF MANGOES AVAILABLE IN EACH M MANGO TREE.


OUTPUT :
    FOR EACH CHILDREN YOU HAVE TO PRINT MAXIMUM NUMBER OF MANGOES HE CAN STEAL.

CONSTRAINTS:

 0 < M < 100000

 0 < N < 100000

SAMPLE INPUT
5 4
1 4 2 3 5
0 5
8 20
3 3
2 9
SAMPLE OUTPUT
5 17 14 17 17
Explanation
FOR 1 HE CAN ONLY ACCESS BOUNDRY WITH 0 HEIGHT - 5
FOR 4 HE CAN  ACCESS BOUNDRY WITH 0,2,3 HEIGHT - 5+3+9 = 17
FOR 2 HE CAN  ACCESS BOUNDRY WITH 0,2 HEIGHT - 5+9 = 14
FOR 3 HE CAN  ACCESS BOUNDRY WITH 0,2,3 HEIGHT - 5+3+9 = 17
FOR 5 HE CAN  ACCESS BOUNDRY WITH 0,2,3 HEIGHT - 5+3+9 = 17*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;
typedef pair<int, int> pp;
int main() {
    int N, M;

    cin >> N >> M;

    vector<int> c(N), s(M);
    vector<pair<int, int>> m;

    for (int &x : c) scanf("%d", &x);

    for (int i = 0; i < M; ++i) {
        int height, mangoes;
        cin >> height >> mangoes;
        m.push_back({height, mangoes});
    }

    sort(m.begin(), m.end());

    int sum = 0;
    for (int i = 0; i < M; ++i) {
        sum += m[i].second;
        s[i] = sum;
    }

    for (int x : c) {
        int idx = upper_bound(m.begin(), m.end(), pp(x, 0),
        [](const pp & a, const pp & b) { return a.first < b.first; }) - m.begin();

        if (idx != -1) cout << s[idx - 1] << " ";
        else cout << -1 << " ";
    }
}