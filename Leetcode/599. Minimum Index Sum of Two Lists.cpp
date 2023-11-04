/*Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.



Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp1, mp2;
        vector<string> res;

        for (int i = 0; i < list1.size(); ++i) mp1[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i)
            if (mp1.count(list2[i])) mp2[list2[i]] = mp1[list2[i]] + i;

        int mn = INT_MAX;
        for (auto e : mp2) mn = min(mn, e.second);
        for (auto e : mp2) if (e.second == mn) res.push_back(e.first);
        return res;
    }
};