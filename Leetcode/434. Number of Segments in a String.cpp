/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5*/

int countSegments(string s) {
    stringstream ss;
    ss << s;
    string x;
    int cnt = 0;
    while (ss >> x) cnt++;
    return cnt;
}