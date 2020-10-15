/*Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using
less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

Split the numbers from 1 to n in sqrt(n) ranges so that block i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).

Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.

At least one of the ranges will contain more than sqrt(n) elements.

Do another pass and process just those elements in the oversubscribed block.

Using a hash table to keep frequencies, you’ll find a repeated element.

This is O(sqrt(n)) memory and 2 sequential passes through the stream.*/

int repeatedNumber(const vector<int> &a) {
    // n = no of unique elements
    // 1 2 3 4 3 5 , n = 5, sq = 2, blocks = 3
    int n = a.size() - 1;
    int sq = sqrt(n);
    int blocks = n / sq + 1;
    // 1 2 3 4 5 => (1,2) goes in the 1st block, (3,4) in the 2nd block and so on
    vector<int> count(blocks, 0);
    for (int i = 0; i <= n; ++i) count[(a[i] - 1) / sq]++;

    int selected_block = 0;
    for (int i = 1; i < blocks; ++i) {
        if (count[i] > sq) {
            selected_block = i;
            break;
        }
    }

    unordered_map<int, int> mp;
    for (int i = 0; i <= n; ++i) {
        if (selected_block * sq < a[i] and a[i] <= (selected_block + 1) * sq) {
            mp[a[i]]++;
            if (mp[a[i]] > 1) return a[i];
        }
    }
    return -1;
}
///////////////////////////////////////////////////////
class Solution {
public:
    int repeatedNumber(const vector<int> &V) {
        if (V.size() <= 1) return -1;
        int valueRange = V.size() - 1; // 1 to N when the size is N+1.
        int blocks = sqrt(valueRange);
        if (blocks * blocks < valueRange) blocks++;
        int count[blocks + 1];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < V.size(); i++) {
            count[(V[i] - 1) / blocks]++;
        }

        int repeatingRange = -1;
        int numRanges = ((valueRange - 1) / blocks) + 1;
        for (int i = 0; i < numRanges && repeatingRange == -1; i++) {
            if (i < numRanges - 1 || valueRange % blocks == 0) {
                if (count[i] > blocks) repeatingRange = i;
            } else {
                if (count[i] > valueRange % blocks) repeatingRange = i;
            }
        }
        if (repeatingRange == -1) return -1;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < V.size(); i++) {
            if ((V[i] - 1) / blocks == repeatingRange) count[(V[i] - 1) % blocks]++;
        }
        for (int i = 0; i < blocks; i++) {
            if (count[i] > 1) {
                return repeatingRange * blocks + i + 1;
            }
        }
        return -1;
    }
};