/*Inplace rotate square matrix by 90 degrees
Given an square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.

Examples:

Input
 1  2  3
 4  5  6
 7  8  9

Output:
 3  6  9
 2  5  8
 1  4  7

 How to do without extra space?
Below are some important observations.

First row of source –> First column of destination, elements filled in opposite order

Second row of source –> Second column of destination, elements filled in opposite order

so … on

Last row of source –> Last column of destination, elements filled in opposite order.

An N x N matrix will have floor(N/2) square cycles. For example, a 4 X 4 matrix will have 2 cycles.
The first cycle is formed by its 1st row, last column, last row and 1st column. The second cycle is
formed by 2nd row, second-last column, second-last row and 2nd column.

The idea is for each square cycle, we swap the elements involved with the corresponding cell in the matrix
in anti-clockwise direction i.e. from top to left, left to bottom, bottom to right and from right to top one at a time.
We use nothing but a temporary variable to achieve this.

Below steps demonstrate the idea

First Cycle (Involves Red Elements)
 1  2  3 4
 5  6  7  8
 9 10 11 12
 13 14 15 16


Moving first group of four elements (First
elements of 1st row, last row, 1st column
and last column) of first cycle in counter
clockwise.
 4  2  3 16
 5  6  7 8
 9 10 11 12
 1 14  15 13

Moving next group of four elements of
first cycle in counter clockwise
 4  8  3 16
 5  6  7  15
 2  10 11 12
 1  14  9 13

Moving final group of four elements of
first cycle in counter clockwise
 4  8 12 16
 3  6  7 15
 2 10 11 14
 1  5  9 13


Second Cycle (Involves Blue Elements)
 4  8 12 16
 3  6 7  15
 2  10 11 14
 1  5  9 13

Fixing second cycle
 4  8 12 16
 3  7 11 15
 2  6 10 14
 1  5  9 13  */

/*So overall the transformations are:
    (x, y)         -> (y, N-1-x)
    (y, N-1-x)     -> (N-1-x, N-1-y)
    (N-1-x, N-1-y) -> (N-1-y, x)
    (N-1-y, x)     -> (x, y)
*/

// An Inplace function to rotate a N x N matrix
// by 90 degrees in anti-clockwise direction
void rotateMatrixAntiClockWise(int mat[][N])
{
    for (int i = 0; i < N / 2; ++i) {
        for (int j = i; j < N - 1 - i; ++j) {
            int t = mat[i][j];
            mat[i][j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = t;
        }
    }
}

// rotate by 90 degree clockwise
void rotateMatrixClockWise(int mat[][N])
{
    for (int i = 0; i < N / 2; ++i) {
        for (int j = i; j < N - 1 - i; ++j) {
            int t = mat[i][j];
            mat[i][j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = t;
        }
    }
}


///////////////////////////////////////////////////
// a more readable version

void rotate(int mat[][N]) {

    for (int layer = 0; layer < N / 2; ++layer) {
        int first = layer;
        int last = N - 1 - layer;

        for (int i = first; i < last; ++i) {
            int offset = N - 1 - i;

            int top = mat[first][i];

            mat[first][i] = mat[i][last];

            mat[i][last] = mat[last][offset];

            mat[last][offset] = mat[offset][first];

            mat[offset][first] = top;
        }
    }
}


// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}


/* Driver program to test above functions */
int main()
{
    // Test Case 1
    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);

    // Print rotated matrix
    displayMatrix(mat);

    return 0;
}