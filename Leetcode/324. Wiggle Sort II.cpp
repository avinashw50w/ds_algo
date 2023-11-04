/*Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.*/
class Solution {
public:
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
};