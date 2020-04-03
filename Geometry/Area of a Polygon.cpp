/*
    Area of a Polygon.
    Note That:
    1) Point p[] holds the points of the polygon.
    2) Points Must be Clock-Wise(CW) or Counter-Clock-Wise(CCW)
       direction.
*/
 
#include <bits/stdc++.h>
using namespace std;
#define LL long long
 
LL n,m;
struct Point
{
    LL x,y;
};
 
LL PolygonArea(Point *p) {
    /*
        Actually this function returns area*2, so
        Actual Area=Return Value/2;
    */
    LL area=0;
    for(LL i=0;i<n;i++)
    {
        if(i==n-1) area=area+(p[i].x * p[0].y - p[0].x * p[i].y);
        else area=area+(p[i].x * p[i+1].y - p[i+1].x * p[i].y);
    }
    return abs(area) / 2;
}
 
int main()
{
    LL i,j,k,d,test,aa,bb;
    Point a[1009];
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>aa>>bb;
            a[i].x=aa;
            a[i].y=bb;
        }
        printf("Area of Polygon=%lld\n",PolygonArea(a));
    }
  