/*Given a sorted array where every number appears twice except for one. Find that no.

IDEA: 
eg 2 2 3 3 4 5 5 6 6
notice that before 4, every pair's starting index is even. But after 4, the starting index becomes odd
So if mid is odd, decrement it to make it even and check if a[mid] == a[mid+1]. If true, then we have to 
look right, l = mid+2. Otherwise move r to mid
Repeat until l = r
*/


int solve(vector<int> a) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = l + (r-l)/2;
        if (mid&1) mid--;
        if (a[mid] == a[mid+1]) l = mid+2;
        else r = mid;
    }

    return a[l];
}