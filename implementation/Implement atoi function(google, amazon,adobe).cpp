/*Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. */

int Solution::atoi(const string &str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
      sign = (str[i++] == '-') ? -1 : 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
      if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
        if (sign == 1) return INT_MAX;
        else return INT_MIN;
      }
      base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}
