/*Minimum squares to cover a rectangle
Given a rectangle with length l and breadth b, we need to find the minimum number of squares that can cover the surface of the rectangle, given that each square has a side of length a. It is allowed to cover the surface larger than the rectangle, but the rectangle has to be covered. It is not allowed to break the square.

Examples:

Input : 1 2 3
Output :1
We have a 3x3 square and we need
to make a rectangles of size 1x2.
So we need only square to cover the
rectangle.

ans = ceil(l/a) * ceil(b/a)
*/

return ((l + a - 1) / a) * ((b + a - 1) / a);

