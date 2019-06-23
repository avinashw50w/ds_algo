/*Given a sequence a consisting of n integers. The player can make several steps. In a single step he can choose 
an element of the sequence (let's denote it ak) and delete it, at that all elements equal to ak + 1 and ak - 1 
also must be deleted from the sequence. That step brings ak points to the player.

Alex is a perfectionist, so he decided to get as many points as possible. Help him.

Input
The first line contains integer n (1 ≤ n ≤ 105) that shows how many numbers are in Alex's sequence.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 105).

Output
Print a single integer — the maximum number of points that Alex can earn.

Examples
input
2
1 2
output
2 */

#define MAX 100005
typedef long long int ll;
ll dp[MAX];
ll count[MAX];
int main(){
	int n,x;
	cin>>n;
	REP(i,n){
		cin>>x;
		count[x]++;
	}
	dp[0]=0;
	dp[1]=count[1];
	for(int i=2;i<MAX;i++){
		dp[i]=max(dp[i-1],dp[i-2]+i*count[i]);
	}
	cout<<dp[MAX-1];
}