/*Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.



Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4*/

// IDEA: store all the leaf values in a set. At each step pick top two nos(smallest two)
// from the set, then add their product to sum variable. Then remove the smallest no from
// the set. Keep repeating this until set has only one element left;

int solve(vector<int> a) {
    int n = a.size();
    set<int> st;
    for (int e : a) st.insert(e);
    int sum = 0;

    while (st.size() > 1 ) {
        auto a = *st.begin();
        auto b = *(st.begin() + 1);
        sum += a * b;
        st.erase(st.begin());
    }

    return sum;
}

/////////////////////////////////////

class Solution {
    const int INF = 1e9;
public:
    int mctFromLeafValues(vector<int>& a) {
        int n = a.size();

        int sum = 0;

        while (a.size() > 1) {
            int min_prod = INF, min_index = 0;

            for (int i = 1; i < a.size(); ++i) {
                if (min_prod > a[i - 1]*a[i]) {
                    min_prod = a[i - 1] * a[i];
                    min_index = a[i - 1] < a[i] ? i - 1 : i;
                }
            }

            sum += min_prod;
            a.erase(a.begin() + min_index);
        }

        return sum;
    }
};