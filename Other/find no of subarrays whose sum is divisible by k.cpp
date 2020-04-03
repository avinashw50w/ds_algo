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
            ans += B[i] * (B[i] - 1) / 2;
        }
        return ans;
    }
