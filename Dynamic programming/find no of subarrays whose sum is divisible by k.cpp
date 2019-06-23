/*As you are only interested in numbers divisible by K, you can do all computations modulo K. 
Consider the cumulative sum array S such that S[i] = S[0] + S[1] + ... + S[i]. Then (P, Q) is a slice divisible by K iff S[P] = S[Q] 
(remember we do all computations modulo K). So you just have to count for each possible value of [0,...,K-1] how many times it appears in S.
Once you know that they are x cells in S that have value i, you want to count the number of slices the start in a cell with 
value i and ends in a cell with value i, this number is x(x-1)/2. To solve edge problems, we add one cell with value 0.*/

int GetSubArraysCount(int A[], int K)
    {
        int N = sizeof(A)/sizeof(A[0]);
        int* B = new int[K];
        memset(B,0,sizeof(B));
        B[0]++;
        int s = 0;
        for (int i = 0; i < N; i++)
        {
            s = (s + A[i]) % K;
            while (s < 0)
            {
                s += K;
            }
            B[s]++;
        }
        int ans = 0;
        for (int i = 0; i <= K - 1; i++)
        {
            ans += (B[i] * (B[i] - 1)) / 2;
        }
        return ans;
    }
