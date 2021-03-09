/*Karl loves playing games on social networking sites. His current favorite is CandyMaker, where the goal is to make candies.
Karl just started a level in which he must accumulate n candies starting with m machines and w 
workers. In a single pass, he can make m x w candies. After each pass, he can decide whether to
spend some of his candies to buy more machines or hire more workers. Buying a machine or hiring 
a worker costs p units, and there is no limit to the number of machines he can own or workers he 
can employ.

Karl wants to minimize the number of passes to obtain the required number of candies at the end of a day. Determine that number of passes.

For example, Karl starts with m=1 machine and w=2 workers. The cost to purchase or hire, p=1 and 
he needs to accumulate 60 candies. He executes the following strategy:

Make mxw = 1x2 = 2 candies. Purchase two machines.
Make 3x2 = 6 candies. Purchase 3 machines and hire 3 workers.
Make 6x5 = 30 candies. Retain all 30 candies.
Make 6x5 = 30 candies. With yesterday's production, Karl has 60 candies.
It took 4 passes to make enough candies.

Function Description:
Complete the minimumPasses function in the editor below. The function must return a long integer representing the minimum number of passes required.

minimumPasses has the following parameter(s):

m: long integer, the starting number of machines
w: long integer, the starting number of workers
p: long integer, the cost of a new hire or a new machine
n: long integer, the number of candies to produce
contstraints:
m,w,p,n <= 10^12

IDEA: use binary search to find the # of rounds required to product n candies. 
For producing maximum candies, both m and w should be as close as possible, becuase m x w will
be maximum when both are either equal or close to each other. Let's say a+b = S, then axb will
be maximum when a = S/2 and b = S/2 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll machines, ll workers, ll price, ll target, ll rounds) {
    // (machines * targets) can overflow, so
    if (machines >= (target + workers - 1) / workers) return true;
    ll curr = (machines * workers);
    rounds--;
    if (rounds == 0) return false;

    while (1) {
        // find the # of rounds required to produce the remaining candies
        ll req = target - curr;
        ll rnds = (req + (machines * workers) - 1) / (machines * workers);
    
        if (rnds <= rounds) return true;
        // if current # of candies is less than the price to purchase machines and workers,
        // then we need more rounds to produce the remianing candies
        if (curr < price) {
            req = price - curr;
            rnds = (req + (machines * workers) - 1) / (machines * workers);
            rounds -= rnds;
            if (rounds <= 0) return false;
            curr += rnds * machines * workers;
        }
        curr -= price;
        if (machines < workers) machines++;
        else workers++;
    }
    
    return false;
}

int main() {
    ll m, w, p, n;
    cin >>m>>w>>p>>n;
    
    ll l = 1, r = 1e14, mid;
    
    while (l < r) {
        mid = l + ((r-l)>>1);
        if (check(m, w, p, n, mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << endl;
}