/*The magician shuffles a small pack of cards, holds it face down and performs the following procedure:

The top card is moved to the bottom of the pack. The new top card is dealt face up onto the table. It is the Ace of Spades.
Two cards are moved one at a time from the top to the bottom. The next card is dealt face up onto the table. It is the Two of Spades.
Three cards are moved one at a time…
This goes on until the nth and last card turns out to be the n of Spades.
This impressive trick works if the magician knows how to arrange the cards beforehand (and knows how to give a false shuffle). 
Your program has to determine the initial order of the cards for a given number of cards, 1 ≤ n ≤ 20000.

Input

On the first line of the input is a single positive integer, telling the number of test cases to follow. 
Each case consists of one line containing the integer n.

Output

For each test case, output a line with the correct permutation of the values 1 to n, space separated. The first number showing the top card of the pack, etc…

Example

Input:
2
4
5
 
Output:
2 1 4 3
3 1 4 5 2 */

/*
Algo: Binary Indexed Tree
Complexity: N*LogN
*/

#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 20500
#define init(Arr) memset((Arr), 0, sizeof (Arr))
 
static int BIT[MAX+1], ANS[MAX], N, T;
inline void update(int i, int v){
    for (; i<=MAX; i+=(i & -i)) BIT[i]+=v;
}
inline int query(int i){
    int ans=0;
    for (; i>0; i-=(i & -i)) ans+=BIT[i];
    return ans;
}
 
int main()
{
    scanf("%d", &T);
    while(T--){
        init(BIT); init(ANS);
        scanf("%d", &N);
        for (int i=1; i<=N; ++i) update(i, 1);
        int M=N, L=1, s, e;
        
        for(int i=1; i<=N; ++i){
            L= (L+i)%M;
            L= (!L)? M: L; M--;
            
            s=1; e=N;
            while(s<=e){
                int mid = (s+e)>>1;
                if (query(mid)>=L) e=mid-1;
                else if (query(mid)<L) s=mid+1;
            }
            ANS[s]=i; update(s, -1);
        }
        for(int i=1; i<=N; ++i) printf("%d ", ANS[i]);
        printf("\n");
    }
    return 0;
}