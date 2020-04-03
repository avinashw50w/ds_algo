/*Method 2 (Tricky)
Following is a solution that uses O(n) extra space and solves the problem in O(n) time complexity.
Let input array be arr[] of size n and maxsize be the size of output subarray.
1) Consider all 0 values as -1. The problem now reduces to find out the maximum length subarray with sum = 0.
2) Create a temporary array sumleft[] of size n. Store the sum of all elements from arr[0] to arr[i] in sumleft[i]. This can be done in O(n) time.
3) There are two cases, the output subarray may start from 0th index or may start from some other index. 
We will return the max of the values obtained by two cases.
4) To find the maximum length subarray starting from 0th index, scan the sumleft[] and find the maximum i where sumleft[i] = 0.
5) Now, we need to find the subarray where subarray sum is 0 and start index is not 0. This problem is 
equivalent to finding two indexes i & j in sumleft[] such that sumleft[i] = sumleft[j] and j-i is maximum. 
To solve this, we can create a hash table with size = max-min+1 where min is the minimum value in the sumleft[] 
and max is the maximum value in the sumleft[]. The idea is to hash the leftmost occurrences of all different values in sumleft[]. 
The size of hash is chosen as max-min+1 because there can be these many different possible values in sumleft[]. Initialize all values in hash as -1
6) To fill and use hash[], traverse sumleft[] from 0 to n-1. If a value is not present in hash[], then store its index in hash. 
If the value is present, then calculate the difference of current index of sumleft[] and previously stored value in hash[]. 
If this difference is more than maxsize, then update the maxsize.
7) To handle corner cases (all 1s and all 0s), we initialize maxsize as -1. If the maxsize remains -1, then print there is no such subarray.*/

void findSubarray(int a[], int n) {

	int maxLen = -1;
	int sumLeft[n];

	int sumLeft[0] = (a[0] == 0)? -1: 1;
	int mini = a[0], maxx =a[0];

	for(int i = 1; i < n; ++i) {
		sumLeft[i] = sumLeft[i-1] + (a[i] == 0 ? -1: 1);
	}

	unordered_map<int,int> hash;

	for(int i = 0; i < n; ++i) {

		if(sumLeft[i] == 0) {
			maxLen = i+1;
			startIdx = 0;
		}

		if (hash.count(sumLeft[i]) == 0)
			hash[sumLeft[i]] = i;
		else {
			if(i - hash[sumLeft[i]] > maxLen) {
				maxLen = i - hash[sumLeft[i]];
				startIdx = hash[sumLeft[i]] + 1;
			}
		}
	}

	if(maxLen == -1)
		printf("No such array\n");
	else
		printf("%d to %d", startIdx, startIdx+maxLen-1);

	return maxLen;

}