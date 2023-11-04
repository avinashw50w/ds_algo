/*Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Idea: incrementing n-1 elements by 1 means decrementing the remaining element by 1.*/

int minMoves(vector<int>& a) {
    int mn = *min_element(a.begin(), a.end());
    int moves = 0;
    for (int e : a) moves += e - mn;
    return moves;
}