/*Given n biased coins, with each coin giving heads with probability Pi, find the probability that on tossing the n coins I will obtain exactly k heads. write the formula for this (i.e. the expression that would give us P (n, k)).*/

/*
prob of getting head  = p and tail is (1-p) say q, then a possible sequence in which k heads appear out of n tosses
is pqppqqpp... where p is k times and q is n-k times, ie, p^k * q^(n-k)
Now all possible combination of this n length sequence where p appears k times and q appears n-k times
will be n!/k!(n-k)! => nCk
So the prob = nCk * p^k * q^(n-k) = n!/((n-k)! * k!)  * p^k * (1 - p)^(n-k)

We can use Dynamic Programming as 𝑁th turn's outcome is mutually independent to 𝑁−1th and there are two possible cases here :

𝐾 heads already came in 𝑁−1 turns
𝐾−1 heads already came in 𝑁−1 turns
𝑑𝑝[𝑖][𝑗] : probability of getting 𝑗 heads in 𝑖 trials.

So, 𝑑𝑝[𝑛][𝑘]=𝑑𝑝[𝑛−1][𝑘]⋅(1−𝑃[𝑛]) + 𝑑𝑝[𝑛−1][𝑘−1]⋅𝑃[𝑛]
*/