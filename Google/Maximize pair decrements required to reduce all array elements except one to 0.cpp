/*Maximize pair decrements required to reduce all array elements except one to 0
Given an array arr[] consisting of N distinct elements, the task is to find the maximum number 
of pairs required to be decreased by 1 in each step, such that N – 1 array elements are reduced 
to 0 and the remaining array element is a non-negative integer.*/

int solve(vector<int> a) {
    priority_queue<int> pq;
    for (int e: a) pq.push(e);

    int ans = 0;
    while (pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();

        if (--x != 0) pq.push(x);
        if (--y != 0) pq.push(y);

        cnt++;
    }
    
    return cnt;
}