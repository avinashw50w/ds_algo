/*Find an element in a sorted rotated array.
eg. 4 5 6 7 1 2 3
*/
// this solution works if array has distinct elements
class Solution {
public:
	int search(vector<int>& a, int target) {
		int l = 0, r = a.size() - 1;
		while (l <= r) {
			int mid = l + (r-l)/2;
			if (a[mid] == target) return mid;
            // first sorted half
			if (a[l] <= a[mid]) {
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

// For array containing duplicates
// eg. [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1], x = 13
class Solution {
public:
	bool search(vector<int>& a, int x) {
		int n = a.size();
		int l=0,r=n-1;
		while (l<=r) {
			int mid = (l+r)/2;
			if (a[mid] == x) return true;
			if (a[l] == a[mid] and a[r] == a[mid]) {
				l++;
				r--;
			}
			else if (a[l] <= a[mid]) {
				if (a[l] <= x and x < a[mid]) r = mid-1;
				else l = mid+1;
			} else {
				if (a[mid+1] <= x and x <= a[r]) l = mid+1;
				else r = mid-1;
			}
		}
		return false;
	}
};
