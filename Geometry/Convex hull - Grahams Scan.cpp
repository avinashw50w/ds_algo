/*We have discussed Jarvis’s Algorithm for Convex Hull. Worst case time complexity of Jarvis’s Algorithm is O(n^2). 
Using Graham’s scan algorithm, we can find Convex Hull in O(nLogn) time. Following is Graham’s algorithm

Let points[0..n-1] be the input array.

1) Find the bottom-most point by comparing y coordinate of all points. If there are two points with same y value, 
then the point with smaller x coordinate value is considered. Let the bottom-most point be P0. Put P0 at first position in output hull.

2) Consider the remaining n-1 points and sort them by polor angle in counterclockwise order around points[0]. 
If polor angle of two points is same, then put the nearest point first.

3 After sorting, check if two or more points have same angle. If two more points have same angle, then remove all same angle points 
except the point farthest from P0. Let the size of new array be m.

4) If m is less than 3, return (Convex Hull not possible)

5) Create an empty stack ‘S’ and push points[0], points[1] and points[2] to S.

6) Process remaining m-3 points one by one. Do following for every point ‘points[i]’
        4.1) Keep removing points from stack while orientation of following 3 points is not counterclockwise (or they don’t make a left turn).
            a) Point next to top in stack
            b) Point at the top of stack
            c) points[i]
         4.2) Push points[i] to S

5) Print contents of S*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define x first
#define y second

typedef pair<int,int> pii;

pii p0;

pii nextToTop(stack<pii> &S)
{
    pii p = S.top();
    S.pop();
    pii res = S.top();
    S.push(p);
    return res;
}

int sqDist(pii p1, pii p2) {
    return pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2);
}

int orientation(pii p, pii q, pii r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool comp(pii p1, pii p2) {
    int o = orientation(p0, p1, p2);

    if(o == 0) 
        return (sqDist(p0, p1) <= sqDist(p0, p2)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void convexHull(pii p[], int n) {
    // Find the bottommost left point
    int ymin = p[0].y, min = 0;
    for(int i = 1; i < n; ++i) {
        int y = p[i].y;
        if(y < ymin or (y == ymin and p[i].x < p[min].x))
        {
            y = ymin;
            min = i;
        }
    }

    swap(p[0], p[min]);

    p0 = p[0];

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted ouput if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    sort(p+1, p+n, comp);

    // If two or more points make same angle with p0,
    // Remove all but the one that is farthest from p0
    // Remember that, in above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, p[i], p[i+1]) == 0) i++;

       p[m++] = p[i];
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3) return;

    // Create an empty stack and push first three points
    // to it.
    stack<pii> S;
    S.push(p[0]);
    S.push(p[1]);
    S.push(p[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), p[i]) != 2)
         S.pop();
      S.push(p[i]);
    }

    // Now stack has the output points, print contents of stack
    while (!S.empty())
    {
       pii p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
    }
}

int main() {

    pii points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int n = sizeof(points)/sizeof(points[0]);
    
    convexHull(points, n);
}

//////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int px, int py) {
        x = px, y = py;
    }
};

vector<Point> P;
vector<Point> CH;

double cross(const Point& o, const  Point& a, const Point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare_position(const Point& a, const Point& b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

bool compare_angle(const Point& a, const Point& b)
{
    return cross(P[0], a, b) > 0;
}

void findConvexHull()
{
    swap(P[0], *min_element(P.begin(), P.end(), compare_position));
  
    sort(P.begin(), P.end(), compare_angle);
  
    P.push_back(P[0]);
    CH.push_back(P[0]);
    CH.push_back(P[1]);

    for(int i = 2; i < P.size(); ++i) {
        while(CH.size() >= 2 && cross(CH[ CH.size() - 2 ], CH[ CH.size() - 1 ] , P[i]) < 0) CH.pop_back();

        CH.push_back(P[i]);
    }
}

int main()
{
    P.push_back(Point(100, 0));
    P.push_back(Point(0, 0));
    P.push_back(Point(0, 100));
    P.push_back(Point(100, 100));
    P.push_back(Point(50, 50));
    P.push_back(Point(30, 40));
    findConvexHull();
    vector<Point>::iterator it;

    for(it = CH.begin(); it != CH.end(); ++it)
        printf("%d %d\n", it->x, it->y);

    return 0;
}