/*Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.

 

Example 1:

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]*/

class RecentCounter {
    vector<int> v;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int x = v.size() - distance(v.begin(), lower_bound(v.begin(), v.end(), t-3000));
        v.push_back(t);
        return x+1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/////////////////////////////////////////////////////////////////////////
/*We only care about the most recent calls in the last 3000 ms, so let's use a data structure that keeps only those.

Algorithm O(N)

Keep a queue of the most recent calls in increasing order of t. When we see a new call with time t, remove all calls that occurred before t - 3000.*/

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() < t-3000) q.pop();
        
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
