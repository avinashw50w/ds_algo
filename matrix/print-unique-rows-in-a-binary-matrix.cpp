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

// A Trie node
typedef struct Node
{
    bool isEndOfCol;
    struct Node *child[2]; // Only two children needed for 0 and 1
} Node;
 
 
// A utility function to allocate memory for a new Trie node
Node* newNode()
{
    Node* temp = new Node();
    temp->isEndOfCol = 0;
    temp->child[0] = temp->child[1] = NULL;
    return temp;
}
 
// Inserts a new matrix row to Trie.  If row is already
// present, then returns 0, otherwise insets the row and
// return 1
bool insert( Node** root, int (*M)[COL], int row, int col )
{
    // base case
    if ( *root == NULL )
        *root = newNode();
 
    // Recur if there are more entries in this row
    if ( col < COL )
        return insert ( &( (*root)->child[ M[row][col] ] ), M, row, col+1 );
 
    else // If all entries of this row are processed
    {
        // unique row found, return 1
        if ( !( (*root)->isEndOfCol ) )
            return (*root)->isEndOfCol = 1;
 
        // duplicate row found, return 0
        else return 0;
    }
}
 
// A utility function to print a row
void printRow( int (*M)[COL], int row )
{
    int i;
    for( i = 0; i < COL; ++i )
        printf( "%d ", M[row][i] );
    printf("\n");
}
 
// The main function that prints all unique rows in a
// given matrix.
void findUniqueRows( int (*M)[COL] )
{
    Node* root = NULL; // create an empty Trie
    int i;
 
    // Iterate through all rows
    for ( i = 0; i < ROW; ++i )
        // insert row to TRIE
        if ( insert(&root, M, i, 0) )
            // unique row found, print it
            printRow( M, i );
}
 
// Driver program to test above functions
int main()
{
    int M[ROW][COL] = { {0, 1, 0, 0, 1},
        				{1, 0, 1, 1, 0},
        				{0, 1, 0, 0, 1},
        				{1, 0, 1, 0, 0} };
 
    findUniqueRows( M );
 
    return 0;
}

/*Time complexity: O( ROW x COL )
Auxiliary Space: O( ROW x COL )

This method has better time complexity. Also, relative order of rows is maintained while printing.*/
