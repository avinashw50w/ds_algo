/*Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
idea: the two numbers which are i and n-i should be prime
NOTE A solution will always exist. read Goldbach’s conjecture*/

bool isprime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
vector<int> Solution::primesum(int n) {

    vector<int> ans;

    for (int i = 2; i < n; ++i) {
        int x = isprime(i);
        int y = isprime(n - i);
        if (x and y) {
            ans.push_back(i);
            ans.push_back(n - i);
            break;
        }
    }
    return ans;
}
