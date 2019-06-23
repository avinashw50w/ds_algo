/**
Stable Marriage Problem
The Stable Marriage Problem states that given N men and N women, where each person has ranked all members of the opposite sex in order of preference, marry the men and women together such that there are no two people of opposite sex who would both rather have each other than their current partners. If there are no such people, all the marriages are “stable” (Source Wiki).

Consider the following example.

Let there be two men m1 and m2 and two women w1 and w2.
Let m1‘s list of preferences be {w1, w2}
Let m2‘s list of preferences be {w1, w2}
Let w1‘s list of preferences be {m1, m2}
Let w2‘s list of preferences be {m1, m2}



The matching { {m1, w2}, {w1, m2} } is not stable because m1 and w1 would prefer each other over their assigned partners. The matching {m1, w1} and {m2, w2} is stable because there are no two people of opposite sex that would prefer each other over their assigned partners.

It is always possible to form stable marriages from lists of preferences (See references for proof). Following is Gale–Shapley algorithm to find a stable matching:
The idea is to iterate through all free men while there is any free man available. Every free man goes to all women in his preference list according to the order. For every woman he goes to, he checks if the woman is free, if yes, they both become engaged. If the woman is not free, then the woman chooses either says no to him or dumps her current engagement according to her preference list. So an engagement done once can be broken if a woman gets better option. Time Complexity of Gale-Shapley Algorithm is O(n2).
Following is complete algorithm from Wiki

Initialize all men and women to free
while there exist a free man m who still has a woman w to propose to 
{
    w = m's highest ranked such woman to whom he has not yet proposed
    if w is free
       (m, w) become engaged
    else some pair (m', w) already exists
       if w prefers m to m'
          (m, w) become engaged
           m' becomes free
       else
          (m', w) remain engaged    
}
 */

const int N = 4;

bool wPrefersM1OverM(int women_prefer[N][N], int w, int m1, int m) {
    for (int i = 0; i < N; ++i) {
        if (women_prefer[w][i] == m1) return true;
        if (women_prefer[w][i] == m) return false;
    }
}

void stableMarriage(int men_prefer[N][N], women_prefer[N][N]) {

    bool free_men[N];
    int women_partner[N];
    fill(free_men, free_men+N, true);
    fill(women_partner, women_partner+N, -1);

    int free_men_cnt = N;

    while (free_men_cnt) {
        int m;
        // find a man which is free(not engaged with a women)
        for (m = 0; m < N; ++m) if (free_men[m]) { break; }

        // One by one go to all women according to m's preferences. 
        // Here m is the picked free man 
        for (int i = 0; i < N and free_men[m]; ++i) {
            int w = men_prefer[m][i];
            // The woman of preference is free, w and m become 
            // partners (Note that the partnership maybe changed 
            // later). So we can say they are engaged not married 
            if (women_partner[w] == -1) {
                women_partner[w] = m;
                free_men[m] = false;
                free_men_cnt--;
            }
            else {
                // Find current engagement of w 
                int m1 = women_partner[w];

                // If w prefers m over her current engagement m1, 
                // then break the engagement between w and m1 and 
                // engage m with w. 
                if (! wPrefersM1OverM(women_prefer, w, m1, m)) {
                    women_partner[w] = m;
                    free_men[m] = false;
                    free_men[m1] = true;
                }
            }
        }
    }
}

int main() {

    int men_prefer[N][N] = {{}, {}, {}, {}};
    int women_prefer[N][N] = {{}, {}, {}, {}};

    stableMarriage(men_prefer, women_prefer);
}