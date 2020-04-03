/*Problem Statement : You are given a 2-D matrix A of n rows and m columns where A[i][j] denotes the calories burnt. 
Two persons, a boy and a girl, start from two corners of this matrix. The boy starts from cell (1,1) and needs to reach cell (n,m). 
On the other hand, the girl starts from cell (n,1) and needs to reach (1,m). The boy can move right and down. 
The girl can move right and up. As they visit a cell, the amount in the cell A[i][j] is added to their total of calories burnt. 
You have to maximize the sum of total calories burnt by both of them under the condition that they shall meet only in one cell 
and the cost of this cell shall not be included in either of their total.
Solution : Let us analyse this problem in steps:

The boy can meet the girl in only one cell.
So, let us assume they meet at cell (i,j).

Boy can come in from left or the top, i.e. (i,j-1) or (i-1,j). Now he can move right or down.That is, the sequence for the boy can be:

(i,j-1)-->(i,j)-->(i,j+1)
(i,j-1)-->(i,j)-->(i+1,j)
(i-1,j)-->(i,j)-->(i,j+1)
(i-1,j)-->(i,j)-->(i+1,j)
Similarly, the girl can come in from the left or bottom, i.e. (i,j-1) or (i+1,j) and she can go up or right. The sequence for girl's movement can be:

(i,j-1)-->(i,j)-->(i,j+1)
(i,j-1)-->(i,j)-->(i-1,j)
(i+1,j)-->(i,j)-->(i,j+1)
(i+1,j)-->(i,j)-->(i-1,j)
Comparing the 4 sequences of the boy and the girl, the boy and girl meet only at one position (i,j), iff

Boy: (i,j-1)-->(i,j)-->(i,j+1) and Girl: (i+1,j)-->(i,j)-->(i-1,j)
or

Boy: (i-1,j)-->(i,j)-->(i+1,j) and Girl:  (i,j-1)-->(i,j)-->(i,j+1)
Convince yourself that in no other case will they meet at only one position.

Now, we can solve the problem by creating 4 tables:

Boy's journey from start (1,1) to meeting cell (i,j)
Boy's journey from meeting cell (i,j) to end (n,m)
Girl's journey from start (n,1) to meeting cell (i,j)
Girl's journey from meeting cell (i,j) to end (1,n)
The meeting cell can range from 2<= i <= n-1 and 2 <= j <= m-1

See the code below for more details: */

#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MAX 1005
int Boy1[MAX][MAX];
int Boy2[MAX][MAX];
int Girl1[MAX][MAX];
int Girl2[MAX][MAX];

int main()
{
    int N,M,ans,op1,op2;
    scanf("%d%d",&N,&M);
    int Workout[MAX][MAX];
    ans = 0;

    //Take input the calories burnt matrix
    F(i,1,N)
        F(j,1,M)
            scanf("%d",&Workout[i][j]);

    //Table for Boy's journey from start to meeting cell
    F(i,1,N)
        F(j,1,M)
            Boy1[i][j] = max(Boy1[i-1][j],Boy1[i][j-1]) + Workout[i][j];

    //Table for boy's journey from end to meet cell
    RF(i,N,1)
        RF(j,M,1)
            Boy2[i][j] = max(Boy2[i+1][j],Boy2[i][j+1]) + Workout[i][j];

    //Table for girl's journey from start to meeting cell
    RF(i,N,1)
        F(j,1,M)
            Girl1[i][j] = max(Girl1[i+1][j],Girl1[i][j-1]) + Workout[i][j];

    //Table for girl's journey from end to meeting cell
    F(i,1,N)
        RF(j,M,1)
            Girl2[i][j] = max(Girl2[i-1][j],Girl2[i][j+1]) + Workout[i][j];

    //Now iterate over all meeting positions (i,j)
    F(i,2,N-1)
    {
        F(j,2,M-1)
        {
            //For the option 1
            op1 = Boy1[i][j-1] + Boy2[i][j+1] + Girl1[i+1][j] + Girl2[i-1][j];

            //For the option 2
            op2 = Boy1[i-1][j] + Boy2[i+1][j] + Girl1[i][j-1] + Girl2[i][j+1];

            //Take the maximum of two options at each position
            ans = max(ans,max(op1,op2));
        }
    }

    printf("%d",ans);
    return 0;
}
