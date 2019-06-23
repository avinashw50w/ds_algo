/*Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence 
are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is 
{3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10*/

/* maxSumIS() returns the maximum sum of increasing subsequence
    in arr[] of size n */
int maxSumIS( int arr[], int n )
{
    int i, j, max = 0;
    int msis[n];
 
    /* Initialize msis values for all indexes */
    for ( i = 0; i < n; i++ )
        msis[i] = arr[i];
 
    /* Compute maximum sum values in bottom up manner */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
 
    /* Pick maximum of all msis values */
    for ( i = 0; i < n; i++ )
        if ( max < msis[i] )
            max = msis[i];
 
    return max;
}

// time : O(n^2)

////////////////////////////////////////////////////////////////////

// using segment tree : time - O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int s[400005];
void update(int node,int l,int r,int pos,int val)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        s[node] = val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,pos,val);
    update(2*node+1,mid+1,r,pos,val);
    s[node] = max(s[node*2],s[node*2+1]);
}
int query(int node,int l,int r,int ql,int qr)
{
    if(ql > r || qr < l) {
        return 0;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l+r)/2;
    int left = query(node*2,l,mid,ql,qr);
    int right = query(node*2+1,mid+1,r,ql,qr);
    return max(left,right);
}
int main()
{
    int n;
    int a[10000];
    int b[10000];
    int mx = 0;
    unordered_map<int,int> m;
    int i;
 
    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    for(i = 0; i < n; i++) {
        if(m[b[i]] == 0)
            m[b[i]] = i+1;
    }
    for(i = 0; i < n; i++) {
        int q = query(1,1,n,1,m[a[i]]-1);
        mx = max(mx,q+a[i]);
        update(1,1,n,m[a[i]],q+a[i]);
    }
    cout<<mx<<endl;
}