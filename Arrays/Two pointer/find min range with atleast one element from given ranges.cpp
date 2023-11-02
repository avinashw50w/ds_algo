/*Given three sorted arrays of variable length,
Find minimum range with at-least one element from each of the given arrays, 
efficiently compute the minimum range with at-least one element from each of the arrays.*/

using pair<int,int> = pii;
using vector<int> = vi;

pii find(vi &a, vi &b, vi &c) {

    pii res;
    int i = 0, j = 0, k = 0;
    int range = INT_MAX;

    while (i < a.size() && j < b.size() && k < c.size()) {
        int low = min({a[i], b[j], c[k]});
        int high = max({a[i], b[j], c[k]});

        if (range > high - low) {
            range = high - low;
            res = {low, high};
        }

        if (a[i] == low) i++;
        else if (b[j] == low) j++;
        else k++;
    }

    return res;
}