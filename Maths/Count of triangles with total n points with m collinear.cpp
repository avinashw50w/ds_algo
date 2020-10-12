/*Count of triangles with total n points with m collinear
Last Updated: 19-06-2018
There are ‘n’ points in a plane, out of which ‘m’ points are co-linear. Find the number of triangles formed by the points as vertices ?

Examples :

Input :  n = 5, m = 4
Output : 6
Out of five points, four points are
collinear, we can make 6 triangles. We
can choose any 2 points from 4 collinear
points and use the single point as 3rd
point. So total count is 4C2 = 6

Input :  n = 10, m = 4
Output : 116*/

Number of triangles = nC3 – mC3