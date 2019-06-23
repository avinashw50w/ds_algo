/*Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the 
next N days.

Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own, or not make any transaction at all. What is the maximum profit 
you can obtain with an optimum trading strategy?

Input

The first line contains the number of test cases T. T test cases follow:

The first line of each test case contains a number N. The next line contains N integers, denoting the predicted price of WOT shares for the next N days.

Output

Output T lines, containing the maximum profit which can be obtained for the corresponding test case.

Constraints

1 <= T <= 10 
1 <= N <= 50000

All share prices are between 1 and 100000*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k,a[50005],i,idx,b[50005],sum=0;
		scanf("%lld %lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		idx=n;
		b[n]=n;
		for(i=n-1;i>0;i--)
		{
			if(a[idx]<a[i])
			idx=i;
			b[i]=idx;
		}
		for(i=1;i<=n;i++)
		{
			if((a[b[i]]-a[i] - 2*k)>=0)
			sum+=(a[b[i]]-a[i] - 2*k);
		}
		cout<<sum<<endl;
	}
}