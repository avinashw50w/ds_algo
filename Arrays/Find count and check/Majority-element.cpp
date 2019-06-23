/*Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element).

Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE as follows:

       I/P : 3 3 4 2 4 4 2 4 4
       O/P : 4 

       I/P : 3 3 4 2 4 4 2 4
       O/P : NONE
METHOD 3 (Using Moore’s Voting Algorithm)
This is a two step process.
1. Get an element occurring most of the time in the array. This phase will make sure that if there is a 
majority element then it will return that only.
2. Check if the element obtained from above step is majority element.

1. Finding a Candidate:
The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm 
is if we cancel out each occurrence of an element e with all the other elements that are different from e then e 
will exist till end if it is a majority element.

findCandidate(a[], size)
1.  Initialize index and count of majority element
     maj_index = 0, count = 1
2.  Loop for i = 1 to size – 1
    (a) If a[maj_index] == a[i]
          count++
    (b) Else
        count--;
    (c) If count == 0
          maj_index = i;
          count = 1
3.  Return a[maj_index]*/

int findCandidate(int a[], int n) {
	int count = 1, maj_idx = 0;

	for(int i = 1; i < n; ++i) {
		if(a[maj_idx] == a[i]) 
			count++;
		else count--;

		if(count == 0) {
			count = 1;
			maj_idx = i;
		}
	}
	return a[maj_idx];
}

int findMajorityElement(int a[], int n) {
	int cand = findCandidate(a, n);

	int cnt = 0;

	for(int i = 0; i < n; ++i) 
		if(a[i] == cand)
			cnt++;

	if(cnt > n/2) return cand;
	else return -1; 
}

////////////////////////////////////////////////////////////////////
/* If the array is sorted, and we need to chech whether a given number is majority element or not,
then we can simply do binary search and find the majority element */

bool isMajority(int a[], int n, int x) {
	/* Find the index of first occurrence of x in arr[] */
	int i = firstOccurence(a, 0, n-1, x);
	/* If element is not present at all, return false*/
	if(i == -1) return false;
	/* check if the element is present more than n/2 times */
	if((i+n/2 < n)and (a[i+n/2] == x)) return true;
	
	else return false;
}

int firstOccerence(int a[], int l, int h, int x) {
	int mid, ans = -1;
	while(l <= r) {
		mid = (l+r)>>1;
		
		if(x <= a[mid]){
			ans = mid;
			h = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}

