/*You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5

We can try to remove the common factors of A and B from A by finding the
greatest common divisor (gcd) of A and B and dividing A with that gcd.

Mathematically, A = A / gcd(A, B) —— STEP1
Now, we repeat STEP1 till we get gcd(A, B) = 1.
Atlast, we return X = A

How does this work ?

On doing prime factorisation of A and B, we get :

A = p1^x1 . p2^x2 . … . pk^xk
B = q1^y1 . q2^y2 . … . ql^yl
Where pi ; i = 1, 2, …, k are prime factors of A and xi ; i = 1, 2, …, k are their respective powers
Similarly, qj ; i = 1, 2, …, l are prime factors of B and yi ; j = 1, 2, …, l are their respective powers

Let ri ; i = 1, 2, …, m be the common factors of A and B. By repeating STEP1, we are reducing the respective powers of ri by at least one, each time (Proof of this is left to the reader). Therefore, we reach a point
where powers of ri become zero and product of the rest prime-powers in A form the largest divisor of A that is co-prime with B.
*/

int solve(int A, int B) {

    while (__gcd(A, B) != 1) A /= __gcd(A, B);

    return A;
}