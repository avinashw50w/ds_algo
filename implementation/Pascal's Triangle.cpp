/*Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n 
as input and prints first n lines of the Pascal’s triangle. Following are the first 6 rows of Pascal’s Triangle.

1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 */

int A[100][100];

void genPascalTriangle() {

	for(line = 0; line < 100; ++line) {
		
		for(int i = 0; i <= line; ++line) {
			
			if(i == 0 or i == line) 
				A[line][i] = 1;

			else 
				A[line][i] = A[line-1][i-1] + A[line-1][i];
		}
	}
}

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
