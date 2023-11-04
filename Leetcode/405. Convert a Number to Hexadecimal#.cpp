/*Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"*/

class Solution {
public:
    string toHex(int num) {
        string l = "0123456789abcdef";
        string res = "";

        // convert the no to its 2's complement
        // so for -ve nos, its 2's complement will be taken
        unsigned n = num;

        if (n == 0) return "0";

        while (n) {
            res = l[n % 16] + res;
            n /= 16;
        }
        return res;
    }
};


////////////////////////////////////////////////////////////////

char *toHex(int num)
{
    const char hex_digit[17] = "0123456789abcdef";
    char num_16[9] = "00000000";

    // Store number as 4-bit chunks (2^4 => 16)
    for (int i = 7; i >= 0; --i)
    {
        num_16[i] = hex_digit[15 & num]; // 15 => 1111
        num >>= 4;
    }

    // Calculate offset (to ignore leading zeroes)
    int offset;
    for (offset = 0;
            num_16[offset] != '\0' && num_16[offset] == '0';
            ++offset);

    offset = (offset > 7) ? 7 : offset; // cap at final digit for case | num == 0

    // Transfer result to an allocated array
    const int len = 9 - offset;
    char *hex = malloc(len);
    if (hex == NULL) exit(-1);
    for (int i = 0; i < len; ++i)
    {
        hex[i] = num_16[i + offset];
    }

    return hex;
}