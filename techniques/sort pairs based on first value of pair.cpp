#include <vector>
#include <pair>
#include <algorithm>

using namespace std;

...

vector<pair<int, int>> a;
sort(a.begin(), a.end());


/*
STL Pairs already have the less than (and other relational) operator defined for them. 
The behavior is such that a < b iff a.first < b.first || a.first == b.first && a.second < b.second
*/
