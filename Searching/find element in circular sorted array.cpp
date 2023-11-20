/*Find an element in a sorted rotated array.
eg. 4 5 6 7 1 2 3
*/

class Solution {
public:
	int search(vector<int>& a, int target) {
		int l = 0, r = a.size() - 1;
		while (l <= r) {
			int mid = l + (r-l)/2;
			if (a[mid] == target) return mid;
            // first sorted half
			if (a[mid] >= a[0]) {
				if (a[l] <= target and target < a[mid]) r = mid-1;
				else l = mid + 1;
			} else {
				if ( a[mid] < target and target <= a[r]) l = mid + 1;
				else r = mid-1;
			}
		}

		return -1;
	}
};

// another way


int SearchCircularArray(int A[],int n,int x){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low + high) / 2;
		
		if(A[mid] == x) return mid;     
		
		if(A[mid] <= A[high]){    // if a[mid..high] is sorted
			if(A[mid] < x && x <= A[high])
				low = mid + 1;
			else 
			high = mid - 1;
		}
		else {           //  if a[low..mid] is sorted
			if(A[low] <= x && x < A[mid])
				high = mid - 1;
			else 
			low = mid + 1;
		}
	}
	return -1;
}

/* Let's say array is like this : 5 6 7 8 9 1 2 3 4    

Notice that the leftmost value (here 5) will always be greater than the rightmost value (here 4) */
