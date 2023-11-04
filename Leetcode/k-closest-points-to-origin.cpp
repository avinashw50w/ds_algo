/*We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]*/

class Solution {
    struct Node {
        double val;
        vector<int> point;
        Node (double v, vector<int> p) {
            val = v;
            point = p;
        }
    };
    
    struct cmp {
        bool operator()(const Node &a, const Node &b) { return a.val < b.val; }
    };
    
    double dist(int x, int y) {
        return (double)sqrt(x*x + y*y);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Node, vector<Node>, cmp> q;
        int N = points.size();
        
        for (int i = 0; i < K; ++i) {
            double d = dist(points[i][0], points[i][1]);
            q.push(Node(d, points[i]));
        }
        
        for (int i = K; i < N; ++i) {
            double d = dist(points[i][0], points[i][1]);
            if (d < q.top().val) {
                q.pop();
                q.push(Node(d, points[i]));
            }
        }
        
        vector<vector<int>> res;
        
        while(!q.empty()) res.push_back(q.top().point), q.pop();
        
        return res;
    }
};