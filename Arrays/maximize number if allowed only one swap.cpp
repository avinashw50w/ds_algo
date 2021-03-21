/*Maximize a no if u r allowed to swap any pair of digits only once.
IDEA: iterate backwards and keep finding the maximum digit "maxd" so far, when encountering a 
small # than maxd, then it can be a possible pair to swap
*/

int solve(vector<int> a) {
    int maxd = -1, maxd_idx = -1, mind_idx = -1;
    int i = a.size()-1;
    while (i >= 0) {
        while (i >= 0 and a[i] > maxd) {
            maxd = a[i];
            maxd_idx = i;
            i--;
        }
        if (a[i] < maxd) {
            mind_idx = i;
        }
        i--;
    }

    if (mind_idx) {
        swap(a[mind_idx], a[maxd_idx]);
    }
    return a;
}