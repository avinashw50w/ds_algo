/*Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Example 1
The matrix
1 0
0 0
should be changed to following
1 1
1 0

Example 2
The matrix
0 0 0
0 0 1
should be changed to following
0 0 1
1 1 1

Method 1 (Use two temporary arrays)
1) Create two temporary arrays row[M] and col[N]. Initialize all values of row[] and col[] as 0.
2) Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as true, then mark row[i] and col[j] as true.
3) Traverse the input matrix mat[M][N] again. For each entry mat[i][j], check the values of row[i] and col[j]. If any of the two values (row[i] or col[j])
is true, then mark mat[i][j] as true.*/

void modifyMatrix(bool mat[R][C])
{
    vector<int> row(R), col(C);

    /* Store the rows and columns to be marked as 1 in row[] and col[]
       arrays respectively */
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (mat[i][j] == 1) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    /* Modify the input matrix mat[] using the above constructed row[] and
       col[] arrays */
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if ( row[i] == 1 || col[j] == 1 ) {
                mat[i][j] = 1;
            }
        }
    }
}

//////////////////////////////////////
// futher optimisation: we can remove the row array and loop once to check wether
// row i contains a 1 or not
vector<int> col(C);
for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
        if (mat[i][j] == 1) col[j] = 1;
    }
}

for (i = 0; i < R; i++) {
    bool row_contains_one = false;
    for (int j = 0; j < C; ++j) {
        if (mat[i][j] == 1) {
            row_contains_one = true;
            break;
        }
    }
    for (j = 0; j < C; j++) {
        if ( row_contains_one || col[j] == 1 ) {
            mat[i][j] = 1;
        }
    }
}
////////////////////////////////////////////////
// futher optimization: use the first row to store col array data
bool first_row_contains_one = false;
for (int i = 0; i < C; ++i) {
    if (mat[0][i] == 1) {
        first_row_contains_one = true;
        break;
    }
}

for (int i = 1; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
        if (mat[i][j] == 1) {
            mat[0][j] = 1;
        }
    }
}

for (i = 0; i < R; i++) {
    bool row_contains_one = false;
    for (int j = 0; j < C; ++j) {
        if (mat[i][j] == 1) {
            row_contains_one = true;
            break;
        }
    }
    for (j = 0; j < C; j++) {
        if ( row_contains_one || mat[0][j] == 1 ) {
            mat[i][j] = 1;
        }
    }
}

if (first_row_contains_one) {
    for (int i = 0; i < C; ++i) mat[0][i] = 1;
}
