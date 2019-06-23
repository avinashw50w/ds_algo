/*Find a quadruple in an array whose sum is K*/

void find4Numbers(int A[], int n, int X) 
{ 
    int l, r; 
  
    sort (A, A+n);
  
    for (int i = 0; i < n - 3; i++) 
    { 
        for (int j = i+1; j < n - 2; j++) 
        { 
            l = j + 1; 
            r = n-1; 
  
            while (l < r) 
            { 
                if( A[i] + A[j] + A[l] + A[r] == X) 
                { 
                   printf("%d, %d, %d, %d", A[i], A[j], 
                                           A[l], A[r]); 
                   l++; r--; 
                } 
                else if (A[i] + A[j] + A[l] + A[r] < X) 
                    l++; 
                else // A[i] + A[j] + A[l] + A[r] > X 
                    r--; 
            } // end of while 
        } // end of inner for loop 
    } // end of outer for loop 
} 

//////////////////////////////////////////////////////////
// Using hashing
struct Node {

    int sum;
    int i;
    int j;
    Node(int e, int x, int y) {
        sum = e;
        i = x; 
        j = y;
    }
};

bool cmp(const Node &a, const Node &b) { return a.ele < b.ele; }

void sovle(int A[], int N, int K) {
    vector<Node> hash;

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j)
            hash.push_back(Node(A[i] + A[j], i, j));
    }

    sort(A.begin(), A.end(), cmp);

    int M = hash.size();

    int l = 0, r = M-1;

    while(l < r) {
        if (hash[l].sum == hash[r].sum and noCommon(hash[i], hash[j])) {
            cout << A[hash[l].i] << " " << A[hash[l].j] << " " << A[hash[r].i] << " " << A[hash[r].j];
            return;
        }

        else if (hash[l].sum + hash[r].sum < K) l++;
        else r--;
    }
}