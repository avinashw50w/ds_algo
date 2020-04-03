/*Two players (numbered 1 and 2) are playing a game with n stones. Player 1 always plays first, and the two players move in alternating turns. The game's rules are as follows:

In a single move, a player can remove either 2, 3, or 5 stones from the game board.
If a player is unable to make a move, that player loses the game.
Given the number of stones, find and print the name of the winner (i.e.,First  or Second) on a new line. Each player plays optimally, 
meaning they will not make a move that causes them to lose the game if some better, winning move exists.

Input Format

The first line contains an integer, T, denoting the number of test cases. 
Each of the T subsequent lines contains a single integer, n, denoting the number of stones in a test case.

Constraints
1 <= T <= 100
1 <= N <= 100
Output Format

On a new line for each test case, print  if the first player is the winner; otherwise, print .

Sample Input

8
1
2
3
4
5
6
7
10
Sample Output

Second
First
First
First
First
First
Second
First  */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    int n, a[101] = {};
    // base cases: if there are 2 or 3 or 4 or 5 or 6 stones, then player 1 can win
    a[2] = a[3] = a[4] = a[5] = a[6] = 1;
    for(int i=8;i<=100;++i){
        if(a[i-2] == 0 or a[i-3] == 0 or a[i-5] == 0) a[i] = 1;
    }
    while(t--){
        cin>>n;
        (a[n] == 1) ? puts("First"): puts("Second");
    }
    return 0;
}
