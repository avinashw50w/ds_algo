/*Let A[0…n – 1] be an array of n distinct positive integers. 
If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. 
Given n and an array A your task is to 
find the number of inversions of A.

Full Problem Description is here.

A Very Nice Analysis is Here

Merge Sort Solution  */

/*
Algorithm: Solution with Merge Sort. This problem can also be solved
            with BST and BIT.
*/
  
// inversion pairs (i,j) if i < j , and Ai > Aj

#include <bits/stdc++.h>
using namespace std;
#define LL long long
int a[200009];
int ans=0;
void Merge(int l, int mid, int r)
{
    int pos = 0;
    int i = l;
    int j = mid+1;

    int temp[r - l + 1];
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])
            temp[pos++] = a[i++];
        else
        {
            ans += (mid - i + 1);    ///  this is the only change that is made here
            temp[pos++] = a[j++];
        }
    }
    while(i <= mid) temp[pos++] = a[i++];
    while(j <= r) temp[pos++] = a[j++];
    for(int i = 0; i < pos; i++)
        a[l+i] = temp[i];
    return;
}
  
void MergeSort(int l,int r)
{
    int mid=(l+r)>>1;
    if(l<r)
    {
        MergeSort(l,mid);
        MergeSort(mid+1,r);
        Merge(l,mid,r);
    }
}
  
int main()
{
    int i,j,k,n,m,d,test,t=0;
    scanf("%d",&test);
    while(test--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        MergeSort(0,n-1);
        printf("%d\n",ans);
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/*BIT solution*/
/*
Algorithm: Binary Indexed Tree
*/
  
#include<bits/stdc++.h>
using namespace std;
#define LL long long
  
LL a[200009];
LL b[200009];
LL tree[200009];
LL n;
  
void update(LL idx,LL val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += idx & -idx;
    }
}
  
LL query(LL idx)
{
    LL ret=0;
    while(idx > 0)
    {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int main() {
	int n; cin>>n;
	
	for(int i=0; i<n; ++i) cin>>a[i];
	
	int maxx = *max_element(a, a+n);
	
	int BIT[maxx+1];
	
	memset(BIT, 0, sizeof(BIT));
	
	for(int i=n-1; i>=0; --i) {
		inv += query(a[i]-1);
		
		update(a[i], 1);
	}
}
/* if the elements of a[i] are greater than 10^6 then use this method of taking another array and store 
relative postions of the elements of a[i] because in BIT the elements of a[i] acts as the index of BIT */
int main()
{
    LL i, j, k, m, d, test, t = 0;
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld", &n);
        memset(tree, 0, sizeof(tree));
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            b[i] = a[i];
        }
        sort(b, b+n);
        for(i = 0; i < n; i++)
        {
            d = lower_bound(b, b+n, a[i]) - b;
            a[i] = d + 1;
        }
        LL ans = 0;
        for(i = n-1; i >= 0; i--)
        {
            ans = ans + query(a[i] - 1);
            update(a[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////
// using set but takes O(n) time in worst case;

int inversion(){
	set<int> st;
	set<int>::iterator it;
	st.insert(a[0]);
	int inv = 0;
	for(int i=1;i<n;++i){
		st.insert(a[i]);
		it = st.upper_bound(a[i]);
		inv += distance(it, st.end());
	}
	return inv;
	
}
