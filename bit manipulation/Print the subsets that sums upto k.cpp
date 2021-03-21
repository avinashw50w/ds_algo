void printSubsets(vector<int> a, int K) {
    int n = a.size();
    for (int i = 0; i < 1 << n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j)
            if (i >> j & 1) sum += a[j];
        if (sum == K) print(a, i);
    }
}

void print(vector<int> a, int mask) {
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (mask >> i & 1) cout << a[i] << " ";
    cout << endl;
}

//////////////////////////////////
void printSubset(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%*d", 5, A[i]);
    }

    printf("\n");
}
// inputs
// a            - the element array
// t            - tuplet vector
// s_size       - array size
// t_size       - tuplet size so far
// sum          - sum so far
// k            - nodes count
// target_sum   - sum to be found

void subsetSum(int a[], int t[], int a_size, int t_size, int sum, int k, int target_sum) {

    if (sum == target_sum) {
        printSubset(t, t_size);
        subsetSum(a, t, a_size, t_size - 1, sum - a[k], k + 1, target_sum);
        return;
    }

    for (int i = k, i < a_size; ++i) {
        t[t_size] = a[i];
        subsetSum(a, t, a_size, t_size + 1, sum + a[i], i + 1, target_sum);
    }
}

void generateSubsets(int a[], int size, int target_sum) {
    int *t = new int[size];

    subsetSum(a, t, size, 0, 0, 0, target_sum);

    delete[] t;
}
int main() {
    int a[] = {10, 7, 5, 18, 12, 20, 15};
    int size = ARRAYSIZE(a);

    generateSubsets(a, size, 35);
    printf("Nodes generated %d\n", total_nodes);
}

///////////////////////////////////////////////////////////////////////////////////////////
/*The power of backtracking appears when we combine explicit and implicit constraints, and we stop generating nodes when these checks fail.
We can improve the above algorithm by strengthening the constraint checks and presorting the data. By sorting the initial array, we need not
to consider rest of the array, once the sum so far is greater than target number. We can backtrack and check other possibilities.

Similarly, assume the array is presorted and we found one subset. We can generate next node excluding the present node only when inclusion
of next node satisfies the constraints. Given below is optimized implementation (it prunes the subtree if it is not satisfying contraints).*/
static int total_nodes;

// prints subset found
void printSubset(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%*d", 5, A[i]);

    printf("\n");
}
// inputs
// a            - set vector
// t            - tuplet vector
// s_size       - set size
// t_size       - tuplet size so far
// sum          - sum so far
// k          - nodes count
// target_sum   - sum to be found
void subset_sum(int a[], int t[],
                int s_size, int t_size,
                int sum, int k,
                int const target_sum)
{
    total_nodes++;

    if ( target_sum == sum )
    {
        // We found sum
        printSubset(t, t_size);

        // constraint check
        if ( k + 1 < s_size && sum - a[k] + a[k + 1] <= target_sum )
        {
            // Exclude previous added item and consider next candidate
            subset_sum(a, t, s_size, t_size - 1, sum - a[k], k + 1, target_sum);
        }
        return;
    }
    else
    {
        // constraint check
        if ( k < s_size && sum + a[k] <= target_sum )
        {
            // generate nodes along the breadth
            for ( int i = k; i < s_size; i++ )
            {
                t[t_size] = a[i];

                if ( sum + a[i] <= target_sum )
                {
                    // consider next level node (along depth)
                    subset_sum(a, t, s_size, t_size + 1, sum + a[i], i + 1, target_sum);
                }
            }
        }
    }
}

// Wrapper that prints subsets that sum to target_sum
void generateSubsets(int a[], int size, int target_sum)
{
    int *tuplet_vector = new int [size];

    int total = 0;

    // sort the set
    sort(a, a + size);

    for ( int i = 0; i < size; i++ )
        total += a[i];

    if ( a[0] <= target_sum && target_sum <= total )
    {

        subset_sum(a, tuplet_vector, size, 0, 0, 0, target_sum);

    }

    delete [] tuplet_vector;
}

