/*Therasa is a Nurse. She wants to give some tablets to the patients in her practice. 
All the patients sit in a line and each of them has a rating score according to his or her health score. 
Therasa wants to give at least 1 tablet for each patient. Patients get jealous of their immediate neighbors, 
so if two patients sit next to each other then the one with the higher rating must get more tablets. 
Therasa wants to save money, so she wants to minimize the total number of tablets.

Input
The first line of the input is an integer N, the number of patients in Therasa’s practice. 
Each of the following N lines contains an integer indicates the health score of each patient.

Output
Output a single line containing the minimum number of tablets Therasa must give.

Constraints
1 <= N <= 100000
1 <= health score <= 100000

SAMPLE INPUT 
3
1
2
2
SAMPLE OUTPUT 
4
Explanation
Here 1, 2, 2 is the health score. Note that when two patients have equal health 
score they are allowed to have different number of tablets. Hence optimal distribution will be 1, 2, 1.*/

int main() {
	int N; cin >> N;
	int A[N], dp[N];

	for (int i = 0; i < N; ++i) cin >> A[i];
	
	dp[0] = 1; 
	for (int i = 1; i < N; ++i) {
		if (A[i] > A[i-1]) dp[i] = dp[i-1] + 1;
		else dp[i] = 1;
	}

	for (int i = N-2; i >= 0; --i) {
		if (A[i] > A[i+1] and dp[i] <= dp[i+1]) 
			dp[i] = dp[i+1] + 1;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) ans += dp[i];

	cout << ans << endl;
}