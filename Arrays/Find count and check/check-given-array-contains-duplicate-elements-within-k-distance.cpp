/*Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. 
Write a function that returns true if array contains duplicates within k distance.

Examples:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.*/

bool find(int A[], int N, int K) {

	set<int> st;

	REP(i, 0, N) {

		if(st.count(A[i])) return true;

		st.insert(A[i]);

		if(i >= K) st.erase(st.find(A[i-K]));
	}

	return false;
}