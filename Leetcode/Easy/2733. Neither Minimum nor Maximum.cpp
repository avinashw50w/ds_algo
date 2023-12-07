/*Given an integer array nums containing distinct positive integers, find and return any number from the 
array that is neither the minimum nor the maximum value in the array, or -1 if there is no such number.

Return the selected integer.*/
class Solution {
public:
    int findNonMinOrMax(vector<int>& a) {
        int n = a.size();
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());
        for (int e: a) {
            if (e != mn and e != mx) return e;
        }
        return -1;
    }
};