/*Two people are playing game of Misère Nim. The basic rules for this game are as follows:

The game starts with  piles of stones indexed from  to . Each pile  (where ) has  stones.
The players move in alternating turns. During each move, the current player must remove one or more stones from a single pile.
The player who removes the last stone loses the game.
Given the value of  and the number of stones in each pile, determine whether the person who wins the game is the first or second person to move. Assume both players move optimally.

In Misere nim, Second player wins if :
1) n1^n2^n3^.... = 0  if any n exists such that n>1
2) n1^n2^n3^.... = 1 for all n<=1*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int x = 0, s, f = 0;
        for(int i=0;i<n;++i){
            cin>>s;
            x ^= s;
            if(s > 1) f = 1;
        }
        if(f == 0){
            (x == 1)? puts("Second"): puts("First"); 
        }
        else{
            (x == 0)? puts("Second"): puts("First");
        }
    }
    return 0;
}