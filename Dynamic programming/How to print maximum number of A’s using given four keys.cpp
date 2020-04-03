/*How to print maximum number of A’s using given four keys
This is a famous interview question asked in Google, Paytm and many other company interviews.

Below is the problem statement.
Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed. 

If you can only press the keyboard for N times (with the above four
keys), write a program to produce maximum numbers of A's. That is to
say, the input parameter is N (No. of keys that you can press), the 
output is M (No. of As that you can produce).
Examples:

Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing 
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

Input:  N = 11
Output: 27
We can at most get 27 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V, Ctrl A, 
Ctrl C, Ctrl V, Ctrl V

Below are few important points to note.

a) For N < 7, the output is N itself.

b) Ctrl V can be used multiple times to print current buffer (See last two examples above). 
The idea is to compute the optimal string length for N keystrokes by using a simple insight. 
The sequence of N keystrokes which produces an optimal string length will end with a suffix of 
Ctrl-A, a Ctrl-C, followed by only Ctrl-V’s . (For N > 6)

The task is to find out the break=point after which we get the above suffix of keystrokes. 
Definition of a breakpoint is that instance after which we need to only press Ctrl-A, Ctrl-C 
once and the only Ctrl-V’s afterwards to generate the optimal length. If we loop from N-3 to 1 
and choose each of these values for the break-point, and compute that optimal string they would produce. 
Once the loop ends, we will have the maximum of the optimal lengths for various breakpoints, 
thereby giving us the optimal length for N keystrokes.

Below is implementation based on above idea.*/

int findoptimal(int N) 
{ 
    // The optimal string length is N when N is smaller than 7 
    if (N <= 6) 
        return N; 
  
    // Initialize result 
    int max = 0; 
  
    // b = N-3, means if the last 3 key presses are ctrl-a, ctrl-c, ctrl-v,
    // then it will double the size of the substring [0..n-4]
    // and if b = N-4, then the last 4 key presses are ctrl-a, ctrl-c, ctrl-v, ctrl-v
    // then it will triple the size of the subtring [0..n-5]
    int b; 
    for (b=N-3; b>=1; b--) 
    { 
            // If the breakpoint is s at b'th keystroke then 
            // the optimal string would have length 
            // (n-b-1)*screen[b-1]; 
            int curr = (N-b-1)*findoptimal(b); 
            if (curr > max) 
                max = curr; 
     } 
     return max; 
} 
  
// Driver program 
int main() 
{ 
    int N; 
  
    // for the rest of the array we will rely on the previous 
    // entries to compute new ones 
    for (N=1; N<=20; N++) 
        printf("Maximum Number of A's with %d keystrokes is %d\n", 
               N, findoptimal(N)); 
} 


/////////////////////////////////////////////////////
// DP solution

int solve(int N) {
	if (N <= 6) return N;

	int dp[N+1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= 6; ++i) dp[i] = i;

	for (int n = 7; n <= N; ++n) {
		for (int i = n-3; i >= 0; --i)
			dp[n] = max(dp[n], (n-i-1)*dp[i]);
	}

	return dp[N];
}