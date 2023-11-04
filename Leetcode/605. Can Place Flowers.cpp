/*Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
*/

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len = flowerbed.size();
    int count = 0;

    for (int i = 0; i < len; ++i) {
        if (
            flowerbed[i] == 0
            and (i == 0 or flowerbed[i - 1] == 0)
            and (i == len - 1 or flowerbed[i + 1] == 0)
        ) {
            flowerbed[i] = 1;
            count++;
        }

        if (count >= n) return true;
    }

    return false;
}

/////////////////////////////////////
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = -1, curr = -1;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                prev = curr;
                curr = i;
                if (prev == -1) n -= (curr - prev - 1) / 2;
                else n -= (curr - prev - 2) / 2;
            }
        }

        if (curr == -1) n -= (flowerbed.size() + 1) / 2;
        else n -= (flowerbed.size() - curr - 1) / 2;

        return n <= 0;
    }
};