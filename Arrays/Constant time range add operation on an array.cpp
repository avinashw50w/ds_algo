/*Constant time range add operation on an array
Last Updated: 11-01-2019
Given an array of size N which is initialized with all zeros. We are given many range add queries, which should be applied to this array. We need to print final updated array as our result.
Examples:

N = 6
Arr = [0, 0, 0, 0, 0, 0]
rangeUpdate1 [0, 2], add 100
Arr = [100, 100, 100, 0, 0, 0]
rangeUpdate1 [1, 5], add 100
Arr = [100, 200, 200, 100, 100, 100]
rangeUpdate1 [2, 3], add 100
Arr = [100, 200, 300, 200, 100, 100]
Which is the final updated array.
This problem can be solved using segment tree with lazy updates in O(log N) time per query but we can do better here, as update operation is not given. We can process each query in constant time using this logic, when a query to add V is given in range [a, b] we will add V to arr[a] and –V to arr[b+1] now if we want to get the actual values of array we will convert the above array into prefix sum array. See below example to understand,

Arr = [0, 0, 0, 0, 0, 0]
rangeUpdate1 [0, 2], add 100
Arr = [100, 0, 0, -100, 0, 0]
rangeUpdate1 [1, 5], add 100
Arr = [100, 100, 0, -100, 0, 0, -100]
rangeUpdate1 [2, 3], add 100
Arr = [100, 100, 100, -100, -100, 0, -100]
Now we will convert above operation array to prefix sum array as shown below,
Arr = [100, 200, 300, 200, 100, 100]
Which is the final updated array.*/

const int maxn = 1e5;

struct Node {
	int l, r;
	int value;
};

vector<Node> range;
vector<int> a(maxn, 0);

for (auto p : range) {
	int l = p.l, r = p.r, val = p.value;
	a[l] += val;
	a[r + 1] -= val;
}

// take cummulative sum to get the final values in the array
for (int i = 1; i < a.size(); ++i)
	a[i] += a[i - 1];

// return the array
return a;

