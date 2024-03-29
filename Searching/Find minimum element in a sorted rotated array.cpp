/*Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.*/

/* take example : 1 2 3 4 5 6 7 8 9 ==> after rotation : 5 6 7 8 9 1 2 3 4 . Notice that the previous element of the 
 minimum element is always greater than it. So, simply binary the number whose previous number is greater than it. 

IDEA: 
for any rotated array, all the elements in the left half will be >= all the elements in the right half
eg. 4 5 6 7 | 0 1 2
so let's say we are at index mid,
now to determine which half we are at, check if a[mid] >= a[n-1]
if true then we are on the left half, otherwise right half
 */

class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size(), l = 0, r = n-1;
        if(a[l] <= a[r])
            return a[l];
        while(l <= r){
            int mid = l+(r-l)/2;
            if (a[mid] > a[mid+1])
                return a[mid+1];
            else if (a[mid] < a[mid-1])
                return a[mid];
            else if (a[mid] >= a[n-1])
                l = mid+1;
            else
                r = mid-1;
        }
        return a[0];
    }
};

// recursive
int solve(vector<int> a, int l, int r) {
    if (l == r) return a[l];
    if (l + 1 == r) return min(a[l], a[r]);
    if (a[l] < a[r]) return a[l];
    int mid = (l + r) >> 1;
    // when all elements from l to r are same
    if (a[l] == a[mid] and a[l] == a[r]) {
        return min(solve(a, l + 1, mid), solve(a, mid + 1, r));
    }
    // since a[l] < a[r] has been checked above, means here a[l] >= a[r],
    // means l is on the first half
    // if l and mid are both on the first half, then search ahead of mid
    if (a[l] <= a[mid]) return solve(a, mid + 1, r);
    return solve(a, l + 1, mid);
}

int findMin(vector<int> &a) {
    solve(a, 0, a.size() - 1);
}

class Solution {
public:
    // but worst is O(n)
    int findMin(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int mid = l + (r-l)/2;
            // case a[mid] < a[r] : 4 4 5 6 1 2 3
            //                              ^
            //                              mid
            // here we can't decrement mid because it can be the min element
            if (a[mid] < a[r]) r = mid;
            else if (a[mid] > a[r]) l = mid + 1;
            else r--;
        }
        
        return a[l];
    }
};
