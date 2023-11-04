/*Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".*/

int compress(vector<char>& a) {
    int n = a.size();
    int i = 0, k = 0;
    while (i < n) {
        a[k++] = a[i];
        int len = 1;

        while (i + len < n and a[i] == a[i + len]) len++;

        if (len > 1) {
            string s = to_string(len);
            for (char c : s) a[k++] = c;
        }

        i += len;
    }

    return k;
}