/*Maximize length of increasing subsequence possible by replacing array element by nearest primes
Difficulty Level : Expert
Last Updated : 22 Oct, 2020
Given an array arr[], the task is to maximize the length of increasing subsequence by replacing 
elements to greater or smaller prime number to the element.

Examples:

Input: arr[] = {4, 20, 6, 12}
Output: 3
Explanation:
Modify the array arr[] as {3, 19, 5, 11} to maximize answer, 
where {3, 5, 11} is longest increasing subsequence with length as 3.*/

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n & 1 ^ 1) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    while(!isPrime(n)) n++;
    return n;
}

int prevPrime(int n) {
    if (n < 2) return 2;
    while (!isPrime(n)) n--;
    return n;
}

int solve(vector<int> a) {
    vector<int> lis;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        for (int p : { prevPrime(a[i]), nextPrime(a[i]) }) {
            int pos = lower_bound(lis.begin(), lis.end(), p) - lis.begin();
            if (pos < lis.size()) lis[pos] = p;
            else lis.push_back(p);
        }
    }

    return lis.size();
}