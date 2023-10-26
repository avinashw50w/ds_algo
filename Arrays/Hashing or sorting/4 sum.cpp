/*Find a quadruple in an array whose sum is K*/

vector<vector<int>> find4Numbers(int A[], int n, int X)
{
    set<vector<int>> st;
    sort (A, A + n);

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int l = j + 1;
            int r = n - 1;

            while (l < r)
            {
                int sum = A[i] + A[j] + A[l] + A[r];
                if ( sum == X)
                {
                    st.insert({A[i], A[j], A[l], A[r]});
                    l++; r--;
                }
                else if (sum < X)
                    l++;
                else // A[i] + A[j] + A[l] + A[r] > X
                    r--;
            } // end of while
        } // end of inner for loop
    } // end of outer for loop

    vector<vector<int>> res;
    
    for (auto e: st) res.push_back(e);
    return res;
}
/////////////////////////////////////

// Using hashing

void solve(vector<int> a, int sum) {
    int n = a.size();
    unordered_map<int, vector<pair<int, int>>> mp;

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

//////////////////////////////////////////////////////////