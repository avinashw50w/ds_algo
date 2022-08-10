/*Given an array A of positive integers of size N, where each value represents
number of chocolates in a packet. Each packet can have variable number of chocolates.
There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having
packet with maximum chocolates and student having packet with minimum chocolates is minimum.

IDEA: sort the array
for each position i find the minimum of a[i+k-1] - a[i]*/

int solve(vector<int> a, int M) {
    int N = a.size();
    sort(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 0; i + M - 1 < N; ++i) {
        ans = min(ans, a[i + M - 1] - a[i]);
    }
    return ans;
}