/*Can we do it in a single pass and O(1) extra space?
The idea is to start from left side of one array and right side of another array.

1) Initialize a variable diff as infinite (Diff is used to store the
   difference between pair and x).  We need to find the minimum diff.
2) Initialize two index variables l and r in the given sorted array.
       (a) Initialize first to the leftmost index in ar1:  l = 0
       (b) Initialize second  the rightmost index in ar2:  r = n-1
3) Loop while l < m and r >= 0
       (a) If  abs(ar1[l] + ar2[r] - sum) < diff  then
           update diff and result
       (b) Else if(ar1[l] + ar2[r] <  sum )  then l++
       (c) Else r--
4) Print the result. */

void printClosest(vector<int> a1, vector<int> a2, int x) {
  int n = a1.size(), m = a2.size();
  int diff = INT_MAX;
  int res_l, res_r, l = 0, r = m - 1;

  while (l < n and r >= 0) {
    if (abs(a[l] + a[r] - x) < diff) {
      diff = abs(a[l] + a[r] - x);
      res_l = l;
      res_r = r;
    }

    if (a[l] + a[r] < x) l++;
    else r--;
  }

  cout << "The closest pair is [" << a1[res_l] << ", " << a2[res_r] << "]\n";
}

