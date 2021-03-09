/* Find the sum of product of all the subarrays of an array
eg. [1, 2, 3]
set sum = 0, ans = 0
when [1]: 1    sum = 1, ans = 1
when [1, 2]: 1 + 2 + 1.2
sum = prev_sum * 2 + 2 = 1.2 + 2 , ans += 1.2 + 2 = 1 + 2 + 1.2
when [1,2,3]: 1 + 2 + 3 + 1.2 + 2.3 + 1.2.3
sum = prev_sum * 3 + 3 = 1.2.3 + 2.3 + 3 ,  ans += 1.2.3 + 2.3 + 3

so formula :
sum = prev_sum * curr_element + curr_element
ans += sum
*/

int solve(vector<int> a) {
    int sum = 0, ans = 0;
    for (int e : a) {
        sum = sum * e + e;
        ans += sum;
    }

    return ans;
}