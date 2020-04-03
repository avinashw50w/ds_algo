/*Given an unsorted array, find the lenght of the longest subsequence of consecutive numbers in the array.

eg. [4, 1, 2, 5, 6],  ans = 3 [4,5,6] */

int fun(int a[], int N)
{
	set<int> st;

	for(int i = 0; i < N; ++i) st.insert(a[i]);

	int ans = 0;

	for(int i: st)
	{
		if(st.count(i-1)) continue;

		int len = 0;
		while(st.count(i++)) len++;

		ans = max(ans, len);
	}
}

// Time complexity : O(nlogn)
// Space complexity : O(n)

// Time complexity can be reduced by using a hash table instead of set.