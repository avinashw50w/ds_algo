/*You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False*/

bool checkRecord(string s) {
    int n = s.size();
    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a++;
        if (a > 1) return false;
        if (s[i] == 'L' and i + 1 < n
                and s[i + 1] == 'L'
                and i + 2 < n and s[i + 2] == 'L') return false;
    }

    return true;
}

/////////////////////////////////////
// another method
bool checkRecord(string s) {
    int n = s.size();
    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a++;
        if (a > 1) return false;
        if (s[i] == 'L') {
            int l = 1;
            while (i + l < n and s[i] == s[i + l]) l++;
            if (l > 2) return false;
        }
    }

    return true;
}