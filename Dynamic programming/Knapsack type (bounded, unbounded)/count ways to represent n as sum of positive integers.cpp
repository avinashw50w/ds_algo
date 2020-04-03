/*Number of different ways in which n can be written as sum of two or more positive integers
For a given number n > 0, find the number of different ways in which n can be written as a sum of at two or more positive integers.

Examples:

Input : n = 5
Output : 6
Explanation : All possible six ways are :
4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

Input : 3
Output : 4
Explanation : All possible four ways are :
3 + 1
2 + 2
2 + 1 + 1
1 + 1 + 1 + 1
We strongly recommend you to minimize your browser and try this yourself first.

This problem can be solved in the similar fashion as coin change problem, the difference is only that in this case we should 
iterate for 1 to n-1 instead of particular values of coin as in coin-change problem.*/

int countWays(int n)
{
    // table[i] will be storing the number of
    // solutions for value i. We need n+1 rows
    // as the table is consturcted in bottom up
    // manner using the base case (n = 0)
    int table[n+1];

    memset(table, 0, sizeof(table));
 
    table[0] = 1;
 
    for (int i=1; i<n; i++)
        for (int j=i; j<=n; j++)
            table[j] += table[j-i];
 
    return table[n];
}
 
// Driver program
int main()
{
    int n = 7;
    cout << countWays(n);
    return 0;
}