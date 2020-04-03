/*Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 0 (or true) 
then make all the cells of ith row and jth column as 0.*/

void solve(vector<vector<int>> &a) {
    int r = a.size(), c = a[0].size();
    vector<int> row(r, 0), col(c, 0);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (row[i] == 0 || col[j] == 0)
                a[i][j] = 0;
}

//////////////////////////////////////////////
// In place
void solve(vector<vector<int>> &a) {
    int r = a.size(), c = a[0].size();

    // iterate through all the rows and if jth column contains zero then make the jth column of the first row zero
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (a[i][j] == 0)
                a[0][j] = 0;

    for (int i = 1; i < r; ++i) {
        // check if the ith row contains any zero
        bool contains_zero = false;
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 0) {
                contains_zero = true;
                break;
            }
        }
        for (int j = 0; j < c; ++j) {
            if (contains_zero || a[0][j] == 0)
                a[i][j] = 0;
        }
    } 
}