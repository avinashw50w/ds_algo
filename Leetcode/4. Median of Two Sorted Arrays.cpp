/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();

        if (n < m) {
            swap(A, B);
            swap(n, m);
        }

        int l = 0, r = m, halflen = (n + m + 1) / 2;

        while (l <= r) {
            int i = l;
            int j = halflen - i;

            if (i < r and B[j - 1] > A[i]) l = i + 1;
            else if (i > l and A[i - 1] > B[j]) r = i - 1;
            else {
                int maxleft = 0;
                if (i == 0) maxleft = B[j - 1];
                else if (j == 0) maxleft = A[i - 1];
                else maxleft = max(A[i - 1], B[j - 1]);

                if ((m + n) & 1) return maxleft;

                int minright = 0;
                if (i == m) minright = B[j];
                else if (j == n) minright = A[i];
                else minright = min(A[i], B[j]);

                return (maxleft + minright) / 2.0;
            }
        }

        return 0.0;
    }
};


/*Approach 1: Recursive Approach
To solve this problem, we need to understand "What is the use of median". In statistics, the median is used for:

Dividing a set into two equal length subsets, that one subset is always greater than the other.

If we understand the use of median for dividing, we are very close to the answer.

First let's cut A into two parts at a random position i:

          left_A             |        right_A
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
Since A has m elements, so there are m+1 kinds of cutting (i=0∼m).

And we know:

len(left_A) = i, len(right_A) = m - i

Note: when i = 0, left_A is empty, and when i = mi=m, right_Ais empty.

With the same way, cut B into two parts at a random position j:


          left_B             |        right_B
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
Since A has m elements, so there are m+1 kinds of cutting (i = 0 \sim mi=0∼m).

And we know:

          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
If we can ensure:

len(left_part) = len(right_part)
max(left_part)≤min(right_part)
then we divide all elements in A,B into two parts with equal length, and one part is always greater than the other. Then
median = max(left_part) + min(right_part) / 2
​
To ensure these two conditions, we just need to ensure:

i + j = m - i + n - j (or: m - i + n - j + 1)
if n≥m, we just need to set: i = 0 ∼ m, j = (m+n+1 / 2) - i

B[j−1]≤A[i] and A[i−1]≤B[j]

ps.1 For simplicity, I presume A[i−1],B[j−1],A[i],B[j] are always valid even if i=0, i=m, j=0, or j=n. I will talk about how to deal with these edge values at last.

ps.2 Why n≥m? Because I have to make sure j is non-negative since 0≤i≤m and j= (m+n+1/2)-i.
If n < m, then j may be negative, that will lead to wrong result.

So, all we need to do is:

Searching i in [0, m], to find an object i such that:

B[j−1]≤A[i] and, A[i−1]≤B[j], where j = (m+n+1 / 2) - i

And we can do a binary search following steps described below:

Set imin = 0, imax = m, then start searching in [imin, imax]

Set i = imin + imax / 2, j = (m+n+1 / 2) - i
Now we have len(left_part)=len(right_part). And there are only 3 situations that we may encounter:

B[j−1]≤A[i] and A[i−1]≤B[j]
Means we have found the object i, so stop searching.

B[j-1] > [i]
Means A[i] is too small. We must adjust i to get B[j−1]≤A[i].
Can we increase i?
      Yes. Because when i is increased, j will be decreased.
      So B[j-1] is decreased and A[i] is increased, and B[j−1]≤A[i] may
      be satisfied.
Can we decrease i?
      No! Because when i is decreased, j will be increased.
      So B[j-1] is increased and A[i] is decreased, and B[j−1]≤A[i] will
      be never satisfied.
So we must increase i. That is, we must adjust the searching range to [i+1, imax].
So, set imin = i+1, and goto 2.

A[i−1]>B[j]:
Means A[i−1] is too big. And we must decrease i to get A[i−1]≤B[j].
That is, we must adjust the searching range to [imin,i−1].
So, set imax = i-1, and goto 2.

When the object i is found, the median is:

max(A[i−1],B[j−1]), when m + n is odd

max([i-1], B[j-1]) + min([i], B[j]) / 2, when m + n is even

Now let's consider the edges values i=0,i=m,j=0,j=n where A[i−1],B[j−1],A[i],B[j] may not exist. Actually this situation is easier than you think.

What we need to do is ensuring that max(left_part)≤min(right_part). So, if i and j are not edges values (means A[i−1],B[j−1],A[i],B[j] all exist), then we must check both B[j−1]≤A[i] and
A[i−1]≤B[j]. But if some of A[i−1],B[j−1],A[i],B[j] don't exist, then we don't need to check one (or both) of these two conditions. For example, if i=0, then A[i−1] doesn't exist, then we don't need to check A[i−1]≤B[j]. So, what we need to do is:

Searching i in [0, m], to find an object i such that:

(j=0 or i = m or B[j−1]≤A[i]) and
(i=0 or j = n or A[i−1]≤B[j]), where j = (m+n+1 / 2) - i
And in a searching loop, we will encounter only three situations:

(j = 0(j=0 or i = mi=m or {B}[j-1] \leq [i])B[j−1]≤A[i]) and
(i = 0(i=0 or j = nj=n or [i-1] \leq {B}[j])A[i−1]≤B[j])
Means i is perfect, we can stop searching.
j > 0j>0 and i < mi<m and {B}[j - 1] > [i]B[j−1]>A[i]
Means i is too small, we must increase it.
i > 0i>0 and j < nj<n and [i - 1] > {B}[j]A[i−1]>B[j]
Means i is too big, we must decrease it.
Thanks to @Quentin.chen for pointing out that: i < m \implies j > 0i<m⟹j>0 and i > 0 \implies j < ni>0⟹j<n. Because:

.*/