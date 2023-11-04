/*Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.
Idea : a perfect square has odd no of divisors
*/
bool isPerfectSquare(int num) {
    int cnt = 0;
    long long i;
    for (i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            cnt++;
            if (i != num / i) cnt++;
        }
    }

    return cnt & 1;
}