/*The time has arrived when the world is going to end. But don't worry, because the new world yuga will start soon. Manu (carrier of mankind) has been 
assigned the job to carry all the necessary elements of current yuga to the upcoming yuga.

There are N stones arranged in a straight line. In order to fulfill the task, Manu has to travel from the first stone to the last one in a very specific way. 
First of all, he has to do it using exactly K jumps. In a single jump, he can jump from a stone with coordinate xi to a stone with coordinate xj if and only 
if xi < xj. We denote the value xj - xi as the length of such a jump.

Your task is to help Manu minimize the maximum length of a jump he makes in his journey, in order to reach the last stone in exactly K jumps and save the mankind. 
This is the answer you have to provide.

Input:

In the first line, there is a single integer T denoting the number of test cases to handle. Then, description of T tests follow. In the first line of each such 
description, two integers N and K are given. This is followed by N space separated integers in the second line, each one denoting a single stone location.

Output:

Output exactly T lines, and in the ith of them, print a single integer denoting the answer to the ith test case.

Constraints:

1 <= T <= 10
2 <= N <= 105
1 <= K <= (N-1)
1 <= Coordinates of stones <= 109 */

/* Binary search the value of minimum dist required*/
const int mod = 1000000007;
const int MAXN = 100000+9;

int n, k;
int stones[MAXN];

// this function checks whether it is possible to cover all the stones in atmost k jumps, with each jump of dist x  //
int Check(int x) {
	int jumps = 0, curr = 0, prev = 0;

	rep(i,0,n) {
		while(curr != n && (stones[curr] - stones[prev] <= x)) curr++;

		jumps++;
		if(curr == n) break;
		prev = curr -1;
	}

	if(curr != n) return 0;
	if(jumps <= k) return 1;
	return 0;
}

int main() {
	caset{
		cin>>n>>k;

		rep(i,0,n) cin>> stones[i]; 

		int lo = 1, hi = mod, ans = -1;
		
		while(lo <= hi) {
			int mid = (lo + hi)>>1;
			if(Check(mid)) {
				ans = mid;
				hi = mid-1;
			}
			else lo = mid+1;
		}

		cout<< ans <<endl;
	}
	return 0;
}
