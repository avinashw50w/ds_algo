/*Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n
as input and prints first n lines of the Pascal’s triangle. Following are the first 6 rows of Pascal’s Triangle.

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1 */

class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> res;
        vector<int> v;
        v.push_back(1);
        res.push_back(v);
        for (int i = 1; i < rows; ++i) {
            v.resize(i+1);
            for (int j = i; j > 0; --j) 
                v[j] += v[j-1];
            res.push_back(v);
        }
        return res;
    }
};

int A[100][100];

void genPascalTriangle() {

    for (line = 0; line < 100; ++line) {

        for (int i = 0; i <= line / 2; ++line) {

            if (i == 0)
                A[line][i] = A[line][line - i] = 1;

            else
                A[line][i] = A[line][line - i] = A[line - 1][i - 1] + A[line - 1][i];
        }
    }
}

//////////////////////////////////////
/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.*/

class Solution {
public:
    // nCr => nCr+1
    // n*(n-1)*...*(n-r+1)/r! => n*(n-1)*...*(n-r+1)*(n-r)/(r+1)!
    // nCr+1 = nCr * (n-r)/(r+1)
    // => nCr * (n-(r+1-1))/(r+1) => nCr * (n-r`+1)/r`
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;

        for (int row = 0; row < numRows; ++row) {
            vector<int> v(row + 1);
            int curr = 1;
            for (int i = 0; i <= row / 2; ++i) {
                if (i == 0) v[i] = v[row - i] = 1;
                else {
                    curr = (curr * (row - i + 1)) / i;
                    v[i] = v[row - i] = curr;
                }
            }
            res.push_back(v);
        }

        return res;
    }
};

////////////////////////////////////////////////////////////////////
/*C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time */
// A O(n^2) time and O(1) extra space function for Pascal's Triangle
void printPascal(int n)
{
    for (int line = 1; line <= n; line++)
    {
        int C = 1;  // used to represent C(line, i)
        for (int i = 1; i <= line; i++)
        {
            printf("%d ", C);  // The first value in a line is always 1
            C = C * (line - i) / i;
        }
        printf("\n");
    }
}