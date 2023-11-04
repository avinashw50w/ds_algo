/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res = (numerator > 0) ^ (denominator > 0) ? "-" : "";
        long long num = abs(numerator);
        long long deno = abs(denominator);
        
        // integer part
        res += to_string(num/deno);
        long long rem = num % deno;
        
        if (rem == 0) return res;
        
        // fractional part
        res += ".";
        
        unordered_map<long long,int> mp;
        mp[rem] = res.size();
        
        while (rem) {
            rem *= 10;
            res += to_string(rem/deno);
            rem %= deno;
            if (mp.count(rem)) {
                res.insert(mp[rem], "(");
                res += ")";
                return res;
            }
            else mp[rem] = res.size();
        }
        
        return res;
    }
};