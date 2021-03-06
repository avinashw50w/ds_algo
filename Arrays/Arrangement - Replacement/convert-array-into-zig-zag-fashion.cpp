/*Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time.
The converted array should be in form a < b > c < d > e < f.

Example:
Input:  arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: arr[] = {3, 7, 4, 8, 2, 6, 1}

We can convert in O(n) time using an Efficient Approach. The idea is to use modified one pass of bubble sort.
Maintain a flag for representing which order(i.e. < or >) currently we need. If the current two elements are
not in that order then swap those elements otherwise not.
Let us see the main logic using three consecutive elements A, B, C. Suppose we are processing B and C currently
and the current relation is ‘<'. But we have B > C. Since current relation is ‘<' previous relation must be '>‘ i.e.,
A must be greater than B. So, the relation is A > B and B > C.
We can deduce A > C. So if we swap B and C then the relation is A > C and C < B. Finally we get the desired order A C B  */

void zigzag(vector<int> &a) {
	int n = a.size(), flag = true;
	for (int i = 0; i < n - 1; ++i) {
		if (flag) {
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		else {
			if (a[i] < a[i + 1])
				swap(a[i], a[i + 1]);
		}

		flag ^= 1;
	}
}

/// Follow up: what if the elements are not distinct 
/// eg. [1,3,2,2,3,1], ans = [2,3,1,3,1,2]
void wiggleSort(vector<int>& a) {
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    int k = b.size()-1;
    
    for (int i = 1; i < a.size(); i += 2) {
        a[i] = b[k--];
    }
    for (int i = 0; i < a.size(); i += 2) {
        a[i] = b[k--];
    }
}
