/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR" */


string convert(string s, int numRows) {

    if (numRows == 1) return s;

    vector<string> rows(min(numRows, (int)s.size()));

    int currRow = 0;
    bool goingDown = false;

    for (char c: s) {
        rows[currRow] += c;

        if (currRow == 0 or currRow == numRows-1) 
            goingDown = !goingDown;

        currRow += goingDown ? 1 : -1;
    }

    string res = "";

    for (string row: rows)
        res += row;

    return res;
}