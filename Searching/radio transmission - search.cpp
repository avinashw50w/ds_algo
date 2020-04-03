/*Hackerland is a one-dimensional city with n houses, where each house i is located at some xi on the -axis. 
The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a range, k, 
meaning it can transmit a signal to all houses k units of distance away.

Given a map of Hackerland and the value of k, can you find and print the minimum number of transmitters needed to cover 
every house in the city? (Every house must be covered by at least one transmitter) Each transmitter must be installed on 
top of an existing house.

Input Format

The first line contains two space-separated integers describing the respective values of  (the number of houses in Hackerland) 
and  (the range of each transmitter). 
The second line contains  space-separated integers describing the respective locations of each house (i.e., ).*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
int n, k;
int a[maxn];

void solve()
{
    int ans = 0;
    int j, i = 0;
    
    while(i < n)
    {
        int proximity = a[i] + k;
        int j = i;
        
        while(j < n and a[j] <= proximity) i = j, j++; 
        
        proximity = a[i] + k;
        j = i;
        
        while(j < n and a[j] <= proximity) i = j, j++;
        
        i++;
        ans++;
    }
    
    cout << ans << endl;
}

int main() {
    
    cin>>n>>k;
    
    for(int i = 0; i < n; ++i) cin>>a[i];
    sort(a, a+n);
    
    solve();
}