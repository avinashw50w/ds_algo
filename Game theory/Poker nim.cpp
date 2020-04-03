/*Poker Nim is another -player game that's a simple variation on a Nim game. The rules of the games are as follows:

The game starts with  piles of chips indexed from  to . Each pile  (where ) has  chips.
The players move in alternating turns. During each move, the current player must perform either of the following actions:

Remove one or more chips from a single pile.
Add one or more chips to a single pile.
At least  chip must be added or removed during each turn.

To ensure that the game ends in finite time, a player cannot add chips to any pile  more than  times.
The player who removes the last chip wins the game.
Given the values of , , and the numbers of chips in each of the  piles, determine whether the person who wins the game is the first or second person to move. Assume both players move optimally. 


poker nim is just a variation of nim. If a player adds x chips to a pile, just restore the piles as it was before by removing the x chips from that pile */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t; cin>>t;
    while(t--){
        int n, k, x=0, s;
        cin>>n>>k;
        for(int i=0;i<n;++i){
            cin>>s;
            x ^= s;
        }
        
        (x == 0)? puts("Second"): puts("First");
    }
    return 0;
}
