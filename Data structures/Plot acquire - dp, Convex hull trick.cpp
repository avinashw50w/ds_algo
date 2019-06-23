/*Up to 50000 rectangles of possibly differing dimensions are given and it is desired to acquire all of them. 
To acquire a subset of these rectangles incurs a cost that is proportional to neither the size of the subset nor 
to its total area but rather the product of the width of the widest rectangle in the subset times the height of 
the tallest rectangle in the subset. We wish to cleverly partition the rectangles into groups so that the total 
cost is minimized; what is the total cost if we do so? Rectangles may not be rotated; that is, we may not interchange 
the length and width of a rectangle.

Observation 1: Irrelevant rectangles
Suppose that both of rectangle A's dimensions equal or exceed the corresponding dimensions of rectangle B. 
Then, we may remove rectangle B from the input because its presence cannot affect the answer, because we can 
merely compute an optimal solution without it and then insert it into whichever subset contains rectangle A 
without changing the cost. Rectangle B, then, is irrelevant. We first sort the rectangles in ascending order 
of height and then sweep through them in linear time to remove irrelevant rectangles. What remains is a list 
of rectangles in which height is monotonically increasing and width is monotonically decreasing. 
(Otherwise, a contradiction would exist to our assumption that all irrelevant rectangles have been removed.)

Observation 2: Contiguity
In the sorted list of remaining rectangles, each subset to be acquired is contiguous. Thus, for example, 
if there are four rectangles, numbered 1, 2, 3, 4 according to their order in the sorted list, 
it is possible for the optimal partition to be {{1,2},{3,4}} but not {{1,4},{2,3}}; in the latter, {2,3} 
is contiguous but {1,4} is not. This is true because, in any subset, if rectangle A is the tallest and rectangle B 
is the widest, then all rectangles between them in the sorted list may be added to this subset without 
any additional cost, and therefore we will always assume that this occurs, making each subset contiguous.

DP solution
The remaining problem then is how to divide up the list of rectangles into contiguous subsets while 
minimizing the total cost. This problem admits a \Theta(N^2) solution by dynamic programming, 
the pseudocode for which is shown below: Note that it is assumed that the list of rectangles comes "cooked"; 
that is, irrelevant rectangles have been removed and the remaining rectangles sorted.

input N
for i ∈ [1..N]
     input rect[i].h
     input rect[i].w
let cost[0] = 0
for i ∈ [1..N]
     let cost[i] = ∞
     for j ∈ [0..i-1]
         cost[i] = min(cost[i],cost[j]+rect[i].h*rect[j+1].w)
print cost[N]

In the above solution, cost[k] stores the minimum possible total cost for acquiring the first k rectangles. 
Obviously, cost[0]=0. To compute cost[i] when i is not zero, we notice that it is equal to the total 
cost of acquiring all previous subsets plus the total cost of acquiring the subset containing rectangle number i; 
the latter may be readily calculated if the size of the latter subset is known, because it is merely the 
width of the first times the height of the last (rectangle number i). We wish to minimize this, 
hence cost[i] = min(cost[i],cost[j]+rect[i].h*rect[j+1].w). (Notice that j is the last rectangle of the 
previous subset, looping over all possible choices.) Unfortunately, O(N^2) is too slow when N=50000, 
so a better solution is needed.

Observation 3: Convexity
Let mj=rect[j+1].w, bj=cost[j], and x=rect[i].h. Then, it is clear that the inner loop in the above DP 
solution is actually trying to minimize the function y=mj*x + bj by choosing j appropriately. 
That is, it is trying to solve exactly the problem discussed in this article. Thus, assuming we have 
implemented the lower envelope data structure discussed in this article, the improved code looks as follows:

input N
for i ∈ [1..N]
     input rect[i].h
     input rect[i].w
let E = empty lower envelope structure
let cost[0] = 0
add the line y=mx+b to E, where m=rect[1].w and b=cost[0] //b is zero
for i ∈ [1..N]
     cost[i] = E.query(rect[i].h)
     if i<N
          E.add(m=rect[i+1].w,b=cost[i])
print cost[N]

Notice that the lines are already being given in descending order of slope, so that each line is added "at the right"; 
this is because we already sorted them by width. The query step can be performed in logarithmic time, as discussed, 
and the addition step in amortized constant time, giving a O(Nlg N) solution. We can modify our data structure slightly 
to take advantage of the fact that query values are non-decreasing (that is, no query occurs further left than its 
predecessor, so that no line chosen has a greater slope than the previous one chosen), and replace the binary search 
with a pointer walk, reducing query time to amortized constant as well and giving a \Theta(N) solution for the DP step. 
The overall complexity, however, is still O(N\lg N), due to the sorting step.*/