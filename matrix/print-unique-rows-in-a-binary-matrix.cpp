/*Print unique rows in a given boolean matrix
Given a binary matrix, print all unique rows of the given matrix.

Input:
        {0, 1, 0, 0, 1}
        {1, 0, 1, 1, 0}
        {0, 1, 0, 0, 1}
        {1, 1, 1, 0, 0}
Output:
    0 1 0 0 1
    1 0 1 1 0
    1 1 1 0 0
Method 1 (Simple)
A simple approach is to check each row with all processed rows. Print the first row. Now, starting from the second row, for each row,
compare the row with already processed rows. If the row matches with any of the processed rows, don’t print it. If the current row doesn’t
match with any row, print it.

Time complexity: O( ROW^2 x COL )
Auxiliary Space: O( 1 )

Method 2 (Use Binary Search Tree)
Find the decimal equivalent of each row and insert it into BST. Each node of the BST will contain two fields, one field for the decimal value,
other for row number. Do not insert a node if it is duplicated. Finally, traverse the BST and print the corresponding rows.

Time complexity: O( ROW x COL + ROW x log( ROW ) )
Auxiliary Space: O( ROW )

This method will lead to Integer Overflow if number of columns is large.

Method 3 (Use Trie data structure)
Since the matrix is boolean, a variant of Trie data structure can be used where each node will be having two children one for 0 and other for 1.
Insert each row in the Trie. If the row is already there, don’t print the row. If row is not there in Trie, insert it in Trie and print it.*/

int trie[maxn][2];
int leaf[maxn];
int sz = 1;
// Inserts a new matrix row to Trie.  If row is already
// present, then returns 0, otherwise insets the row and
// return 1
bool insert( vector<vector<int>> M, int row )
{
    int col = M[0].size();
    int node = 0;
    for (int i = 0; i < col; ++i) {
        int curr = M[row][i];
        if (trie[node][curr] == 0) trie[node][curr] = sz++;
        node = trie[node][curr];
    }

    if (left[node] == 0) {
        left[node] = 1;
        return true;
    }
    return false;
}

// A utility function to print a row
void printRow( vector<vector<int>> M, int row )
{
    for ( i = 0; i < M[0].size(); ++i )
        printf( "%d ", M[row][i] );
    printf("\n");
}

// The main function that prints all unique rows in a
// given matrix.
void findUniqueRows( vector<vector<int>> M ) {
    for ( int i = 0; i < M.size(); ++i )
        if ( insert(M, i, 0) )
            printRow( M, i );
}

// Driver program to test above functions
int main()
{
    vector<vector<int>> M = { {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };

    findUniqueRows( M );

    return 0;
}

/*Time complexity: O( ROW x COL )
Auxiliary Space: O( ROW x COL )

This method has better time complexity. Also, relative order of rows is maintained while printing.*/
