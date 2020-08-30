/*Find a quadruple in an array whose sum is K*/

// Using hashing

void solve(vector<int> a, int sum) {
    int n = a.size();
    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val = sum - (a[i] + a[j]);

            if (mp.count(val)) {
                for (auto p : mp[val]) {
                    int x = p.first;
                    int y = p.second;

                    if ((x != i and x != j) and (y != i and y != j)) {
                        printf("%d %d %d %d\n", a[x], a[y], a[i], a[j]);
                        return;
                    }
                }
            }

            mp[a[i] + a[j]].push_back({i, j});
        }
    }
}

/////////////////////////////////////
void find4Numbers(int A[], int n, int X)
{
    int l, r;

    sort (A, A + n);

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            l = j + 1;
            r = n - 1;

            while (l < r)
            {
                if ( A[i] + A[j] + A[l] + A[r] == X)
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