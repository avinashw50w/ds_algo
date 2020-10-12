/*Replace every element with the greatest element on right side
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array.
Since there is no element next to the last element, replace it with -1. For example, if the array is {16, 17, 4, 3, 5, 2},
then it should be modified to {17, 5, 5, 5, 2, -1}.

A tricky method is to replace all elements using one traversal of the array. The idea is to start from the rightmost element,
move to the left side one by one, and keep track of the maximum element. Replace every element with the maximum element.*/

void nextGreatest(vector<int> &a) {
    int n = a.size();
    int max_from_right = a[n - 1];
    a[n - 1] = -1;

    for (int i = 0; i < n; ++i) {
        int t = a[i];
        a[i] = max_from_right;
        max_from_right = max(max_from_right, t);
    }
}

/*Output:
The modified array is:
17 5 5 5 2 -1
*/