/*Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of 
the array to the very right. You can only see the k numbers in the window. Each time the sliding 
window moves right by one position. Your job is to output the median array for each window in 
the original array.*/
class Solution {
    set<array<int, 2>> minheap;
    set<array<int, 2>, greater<array<int, 2>>> maxheap;
public:
    void rebalance() {
        if (maxheap.size() > minheap.size()) {
            minheap.insert(*maxheap.begin());
            maxheap.erase(*maxheap.begin());
        }
    }
    
    double getMedian(int k, vector<int> nums) {
        if (k & 1) {
            return (double) nums[(*minheap.begin())[1]];
        }
        else {
            return ((double) nums[(*minheap.begin())[1]] + nums[(*maxheap.begin())[1]]) / 2;
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                minheap.erase({ nums[i-k], i - k });
                maxheap.erase({ nums[i-k], i - k });
            }
            
            minheap.insert({ nums[i], i });
            maxheap.insert(*minheap.begin()); minheap.erase(*minheap.begin());
            
            rebalance();
            
            if (i >= k - 1) res.push_back(getMedian(k, nums));
        }
            
        return res;
    }
};