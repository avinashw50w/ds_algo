/*Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.*/

string addStrings(string num1, string num2) {
    if (num1.length() < num2.length()) swap(num1, num2);

    int i = num1.length() - 1, j = num2.length() - 1;
    int carry = 0;
    while (i >= 0 or j >= 0) {
        int sum = (i >= 0 ? num1[i] - '0' : 0)
                  + (j >= 0 ? num2[j] - '0' : 0) + carry;

        carry = sum / 10;
        sum %= 10;
        num1[i] = sum + '0';

        i--; j--;
    }

    if (carry) num1 = (char)(carry + '0') + num1;

    return num1;
}