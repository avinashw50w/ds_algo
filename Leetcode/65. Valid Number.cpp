/*A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
At least one digit, followed by a dot '.'.
At least one digit, followed by a dot '.', followed by at least one digit.
A dot '.', followed by at least one digit.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
At least one digit.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.*/
class Solution {
public:
    bool isDecimalOrInteger(string s) {
        if (s.empty()) return false;
        if (s[0] == '+' or s[0] == '-') s = s.substr(1);
        if (s.empty()) return false;
        bool dot = false;
        bool digit = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') {
                if (dot) return false;
                dot = true;
                continue;
            }
            if (s[i] < '0' or s[i] > '9') return false;
            if ('0' <= s[i] and s[i] <= '9') digit = true;
        }
        return digit;
    }
    
    bool isInteger(string s) {
        if (s.empty()) return false;
        if (s[0] == '+' or s[0] == '-') s = s.substr(1);
        if (s.empty()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < '0' or s[i] > '9') return false;
        }
        return true;
    }
    
    bool isNumber(string s) {
        if (s.empty()) return true;
        string first, second;
        if (s.find('e') != string::npos) {
            first = s.substr(0, s.find('e'));
            second = s.substr(s.find('e') + 1);
        }
        if (s.find('E') != string::npos) {
            first = s.substr(0, s.find('E'));
            second = s.substr(s.find('E') + 1);
        }
        if (first.empty() and second.empty()) return isDecimalOrInteger(s);
        return isDecimalOrInteger(first) and isInteger(second);
    }
};