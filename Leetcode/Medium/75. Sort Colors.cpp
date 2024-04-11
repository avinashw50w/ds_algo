/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.*/
class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1, m = 0;
        while (m <= r) {
            if (a[m] == 0) swap(a[m++], a[l++]);
            else if (a[m] == 1) m++;
            else swap(a[m], a[r--]);
        }
    }
};