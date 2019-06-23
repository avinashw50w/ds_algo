/*A scuba diver uses a special equipment for diving. He has a cylinder with two containers: one with oxygen and the other with 
nitrogen. Depending on the time he wants to stay under water and the depth of diving the scuba diver needs various amount of 
oxygen and nitrogen. The scuba diver has at his disposal a certain number of cylinders. Each cylinder can be described by 
its weight and the volume of gas it contains. In order to complete his task the scuba diver needs specific amount of oxygen 
and nitrogen. What is the minimal total weight of cylinders he has to take to complete the task?

Example
The scuba diver has at his disposal 5 cylinders described below. Each description consists of: volume of oxygen, 
volume of nitrogen (both values are given in litres) and weight of the cylinder (given in decagrams):

3 36 120
10 25 129
5 50 250
1 45 130
4 20 119
If the scuba diver needs 5 litres of oxygen and 60 litres of nitrogen then he has to take two cylinders of total weight 249 
(for example the first and the second ones or the fourth and the fifth ones).

Task
Write a program that for each test case:

reads scuba diver's demand for oxygen and nitrogen, the number of accessible cylinders and their descriptions;
computes the minimal total weight of cylinders the scuba diver needs to complete his task;
outputs the result.
Note: the given set of cylinders always allows to complete the given task.

Input
The number of test cases c is in the first line of input, then c test cases follow separated by an empty line.

In the first line of a test case there are two integers t, a separated by a single space, 1 <= t <= 21 and 1 <= a <= 79. 
They denote volumes of oxygen and nitrogen respectively, needed to complete the task. The second line contains 
one integer n, 1 <= n <= 1000, which is the number of accessible cylinders. 
The following n lines contain descriptions of cylinders; i-th line contains three integers ti, ai, wi separated by 
single spaces, (1 <= ti <= 21, 1 <= ai <= 79, 1 <= wi <= 800). These are respectively: volume of oxygen and nitrogen 
in the i-th cylinder and the weight of this cylinder.

Output
For each test case your program should output one line with the 
minimal total weight of cylinders the scuba diver should take to complete the task.*/

/*This is similar to the classic “knapsack” dynamic programming problem.

Recurrence relation:

dp[n][O][N] = minimum total weight of cylinders required to have O and N capacity of oxygen and nitrogen 
(capacity of oxygen and nitrogen can exceed) provided n cylinders

dp[i][co][cn]=min(solve(i-1,co,cn),solve(i-1,max(co-oxi[i-1],0),max(cn-nitro[i-1],0))+w[i-1]);

where oxi[i-1] and nitro[i-1] denotes the oxygen and nitrogen capacity of ith cylinder,

w[i-1] denotes the weight of ith cylinder

Terminating conditions:

dp[0][0][0] = 0

dp[0][oxi][nitro]=INFINITY where oxi>0 and nitro>0  */


const int MAX = 1024;
const int INF = 999999999;

int N, O, n, t, cs;
int nitro[MAX], oxi[MAX], w[MAX];
int dp[MAX][22][80], visited[MAX][22][80];

int solve(int i, int co, int cn) 
{
	if(dp[i][co][cn]!=-1){
		return dp[i][co][cn];
	}
	if(co==0&&cn==0){
		dp[i][co][cn]= 0;
	}
	else if(i==0){//if we considered all cylinders and if co and cn are still not equal to zero
		//then its not possible to satisfy the required condition. Hence return INF in order to eliminate all
		//recursive paths leading to this status
		dp[i][co][cn]= INF;
	 }
	 else{
		//either select the ith cylinder or move on to i-1th cylinder
		//Be careful about the index:
		//ith cylinder oxi[i-1] capacity of oxygen and nitro[i-1] capacity of nitrogen
		dp[i][co][cn]=min(solve(i-1,co,cn), solve(i-1, max(co-oxi[i-1],0), max(cn-nitro[i-1],0))+w[i-1]);
	}
	return dp[i][co][cn];
}

int main() 
{
	scanf("%d", &t);
	while(t--){
		
		scanf("%d %d %d", &O, &N, &n);
		for(int i=0;i<n+1;i++)
			for(int j=0;j<O+1;j++)
				for(int k=0;k<N+1;k++)
					dp[i][j][k]=-1;
	
		for(int i = 0; i < n; i++) 
            scanf("%d %d %d", &oxi[i], &nitro[i], &w[i]);
		//dp[n][O][N] gives the minimum total weight of cylinders required to have O and N capacity of oxygen
		//and nitrogen (capacity of oxygen and nitrogen can exceed)
		printf("%d\n", solve(n, O, N));
	}
	return 0;
}