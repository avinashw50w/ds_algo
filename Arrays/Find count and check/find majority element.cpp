/*Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE as follows:

       I/P : 3 3 4 2 4 4 2 4 4
       O/P : 4 

       I/P : 3 3 4 2 4 4 2 4
       O/P : NONE	
       */

/*METHOD 3 (Using Moore’s Voting Algorithm)
This is a two step process.
1. Get an element occurring most of the time in the array. This phase will make sure that if there is a majority element then it will return that only.
2. Check if the element obtained from above step is majority element.

1. Finding a Candidate:
The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is if we cancel out each occurrence of an 
element e with all the other elements that are different from e then e will exist till end if it is a majority element.*/

int findCandidate(int a[], int n) {
	int maj_idx = 0, count = 1;

	for(int i=1; i<n; ++i) {
		if(a[maj_idx] == a[i]) count++;
		else count--;

		if(count == 0) {
			maj_idx = i;
			count = 1;
		}

		return a[maj_idx];
	}
}

void Majority(int a[], int n) {
	int cand = findCandidate(a, n);

	int cnt = 0;
	for(int i=0; i<n; ++i) 
		if(a[i] == cand) cnt++;

	if(cnt >= n/2) cout << cand << endl;
	else cout << "NO Majority element\n";
}