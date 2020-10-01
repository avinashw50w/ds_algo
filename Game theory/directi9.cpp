/*Alice and Bob are playing a game. The game is played as follows : 
- There are N piles of coins on the table. Pile i has A[i] coins. 
- In each turn, each player can pick up 1 or more coins from the leftmost non-empty pile. 
- If a player picks up a coin from pile i , all coins from piles 0 to i-1 should have been taken. 
- The person who picks up the last coin loses the game. 
Alice and Bob play the game alternately. Alice plays first. Given the number of piles N and the 
number of coins Ai in pile i, you have to determine which player will win the game, assuming 
both play optimally.
*/

/*Alice wins iff the number of piles with 1 coin is odd. Bob otherwise. 
Alice always take A[i]-1 (if A[i] > 1) coins from every pile. If pile i has only one coin then she has to take at least one 
coin per pile and then Bob will lead the game (he is capable now to take A[j] -1 coin first and leave Alice with just one coin to be picked up. 
Same Reasoning holds now for Bob.
*/