/*Find a quadruple in an array whose sum is K*/

// Using hashing

void solve(vector<int> a, int sum) {
    int n = a.size();
    unordered_map<int, vector<array<int,2>> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val = sum - (a[i] + a[j]);

            if (mp.count(val)) {
                auto p = mp[val];
                int x = p[0], y = p[1];
                cout << a[i] << " "<< a[j] << " " << a[x] << " " << a[y] << endl;
            }
        }
        for (int j = 0; j < i; ++j) {
            mp[a[i] + a[j]] = {i, j};
        }
    }
}

/////////////////////////////////////

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



//////////////////////////////////////////////////////////