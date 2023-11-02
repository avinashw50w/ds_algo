/*Given an array of distinct intergers. Find all unique subsets that sum to target.
We can an element only once
sol: use backtracking
iterate through each of the element and for each element we can either pick it or ignore it
To get only unique subsets:
since all array elements are distinct, the subsets will be unique
*/
vector<vector<int>> ans;

void solve(int pos, vector<int> res, int sum) {
    if (sum == 0) {
        ans.push_back(res);
        return;
    }
    if (pos >= a.size() or sum < 0) return; // optional check

    for (int i = pos; i < a.size(); ++i) {
        res.push_back(a[i]);
        // pick the ith element and solve for next
        solve(i + 1, res, sum - a[i]);
        // ignore the ith element and solve for next
        res.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& a, int target) {
    solve(0, {}, target);

    return ans;
}

// another approach by bitmasking
vector<vector<int>> solve(vector<int> a, int target) {
    int n = a.size();
    int mask = 1<<n;
    vector<vector<int>> ans;
    
    for (int i = 0; i < mask; ++i) {
        vector<int> res;
        for (int j = 0; j < n; ++j) {
            if (i>>j&1) res.push_back(a[j]);
        }
        ans.push_back(res);
    }

    return ans;
}

//////////////////////////////////////////////////////////////////
/* Same as above but we can pick an element multiple times.
sol: use backtracking
iterate through each of the element and for each element we can either pick it or ignore it.
If we pick it we can pick it again.
To get only unique subsets:
since all array elements are distinct, the subsets will be unique*/
vector<vector<int>> ans;

void solve(int pos, vector<int> res, int sum) {
    if (sum == 0) {
        ans.push_back(res);
        return;
    }
    if (pos >= a.size() or sum < 0) return; // optional check

    for (int i = pos; i < a.size(); ++i) {
        res.push_back(a[i]);
        // don't solve for i+1, coz we can pick ith element again
        solve(i, res, sum - a[i]);
        res.pop_back();
    }
}

//////////////////////////////////////////////////////////////////
/*
variation: 
array elements are not distinct
we can pick elements only once

Sol: same as the first one, but since array elements can contain duplicates, the subsets may not be unique

eg. a = [2,3,2,2,1], target = 4
one subset can be [1st ele, 3rd ele] or [1st elem, 4th ele], [3rd elem, 4th ele] all these subsets are [2,2]
To avoid duplicate subsets
- sort the array so that all the duplicates come together. [1,2,2,2,3]
- if we pick 2 at index 1 and solved for next, then in the next iteration if we pick 2 at index 2 again
  and solve for next, then it will lead to a duplicate subset. So if the previous element is same then continue the
  iteration instead of solving for next
*/

vector<vector<int>> ans;

void solve(int pos, vector<int> res, int sum) {
    if (sum == 0) {
        ans.push_back(res);
        return;
    }
    if (pos >= a.size() or sum < 0) return; // optional check

    for (int i = pos; i < a.size(); ++i) {
        // ignore if the curr element is same as prev
        if (i > pos and a[i] == a[i-1]) continue;
        res.push_back(a[i]);
        solve(i + 1, res, sum - a[i]);
        res.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& a, int target) {
    sort (a.begin(), a.end());
    
    solve(0, {}, target);

    return ans;
}

/*
crux: 
if array elements are distinct then all generated subsets will be unique
if array elements are not distict then to generate unique subsets
    - sort the array
    - dont pick an element if the prev element is same as the curr one
*/