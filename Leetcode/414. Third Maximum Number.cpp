/*Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]
Output: 1

Example 1:
Input: [1,1,2]
Output: 2

Example 1:
Input: [1,2,-2147483648]
Output: -2147483648


Explanation: The third maximum is 1.*/

int thirdMax(vector<int>& nums) {

    long long first = nums[0], second = -INF, third = -INF;

    for (int i = 1; i < nums.size(); ++i) {
        int e = nums[i];
        if (e > first) {
            third = second;
            second = first;
            first = e;
        }
        else if (second < e and e < first) {
            third = second;
            second = e;
        }
        else if (third < e and e < second) {
            third = e;
        }
    }

    return third == -INF ? (int)first : (int)third;
}