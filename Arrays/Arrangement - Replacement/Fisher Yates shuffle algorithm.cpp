/*The Fisher–Yates shuffle is an algorithm for generating a random permutation of a finite sequence,
such that each permutation is equally likely.*/

/*Algo:
for i from n - 1 downto 1 do
   j = random integer with 0 <= j <= i
   exchange a[j] and a[i]
*/

void shuffle(vector<int> &a) {
    int n = a.size();
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(a[i], a[j]);
    }
}

/*How does this work?
The probability that ith element (including the last one) goes to last position is 1/n,
because we randomly pick an element in first iteration.

The probability that ith element goes to second last position can be proved to be 1/n by dividing it in two cases.
Case 1: i = n-1 (index of last element):
The probability of last element going to second last position is = (probability that last element doesn't stay
at its original position) x (probability that the index picked in previous step is picked again so that the
last element is swapped)
So the probability = ((n-1)/n) x (1/(n-1)) = 1/n
Case 2: 0 < i < n-1 (index of non-last):
The probability of ith element going to second position = (probability that ith element is not picked in previous iteration) x
(probability that ith element is picked in this iteration)
So the probability = ((n-1)/n) x (1/(n-1)) = 1/n*/