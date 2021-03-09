/*You are given an array and you need to find number of tripets of indices (i,j,k)
such that the elements at those indices are in geometric progression for a given common ratio
r and i < j < k.
Complete the countTriplets function in the editor below. It should return the number of triplets forming a geometric progression for a given r as an integer.

countTriplets has the following parameter(s):

arr: an array of integers
r: an integer, the common ratio*/

long countTriplets(vector<long> arr, long r) {

    unordered_map<long, long> left, right;
    long ans = 0;

    for (long x : arr) right[x]++;

    for (long x : arr) {
        right[x]--;
        if (x % r == 0) {
            ans += left[x / r] * right[x * r];
        }
        left[x]++;
    }

    return ans;
}