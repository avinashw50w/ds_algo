/*You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to (x+1, y), (x - 1, y), (x, y+1), (x, y-1), (x-1, y-1), (x+1,y+1), (x-1,y+1), (x+1,y-1)
You are given a sequence of points and the order in which you need to cover the points.
Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).*/

// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])

/*Approach:--
Now I will explain the logic to solve this problem.
Since we have to find minimum number of  steps to reach the last point from
first point.Starting from first point we will find the minimum number of
steps required to reach the second point. The minimum number of steps will
be nothing but the maximum value among the absolute difference of x and y
coordinates of first and second point.
For clarity suppose we want to go from point (0 ,0) to point (1, 2) so the
minimum number of moves will be (0,0)->(1,1)->(1,2) i.e. total 2 moves.
it means the number of moves =max((1-0),(2-0)) i.e. if (x1,y1)=(0,0) and
(x2,y2)=(1,2).
number of moves=max(abs(x2-x1),abs(y2-y1));
suppose X = abs(x2-x1) and Y = abs(y2-y1) , if both X and Y are positive, we will move
along the diagonal to reduce both the values by 1, until one of them becomes 0. Then the remaining dist
is covered. Actually we are moving max(X,Y) dist.
On summing up all the values for the maximum differences for all consecutive
elements we will get the final result.

Complexity=O(n)*/

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int s1 = X.size(), ans = 0;

    for (int i = 1; i < s1; i++)

    {

        ans = ans + (abs(X[i] - X[i - 1]) < abs(Y[i] - Y[i - 1]) ? abs(Y[i] - Y[i - 1]) : abs(X[i] - X[i - 1]));

    }

    return ans;
}
