/*Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. 
Write a function that returns true if array contains duplicates within k distance.

Examples:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.*/

bool find(int A[], int N, int K) {

	unordered_set<int> st;

	REP(i, 0, N) {

		if(st.count(A[i])) return true;

		st.insert(A[i]);

		if(i >= K) st.erase(st.find(A[i-K]));
	}

	return false;
}

// but the above algo is O(nlogn) 
// here's O(n)
bool find(vector<int> A, int K) {

    unordered_map<int, int> mp;

    for (int i = 0; i < A.size(); ++i) {
        int x = A[i];
        if (mp.count(x) and i - mp[x] <= K) return true;

        mp[x] = i;
    }
}