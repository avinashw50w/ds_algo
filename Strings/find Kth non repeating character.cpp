/*Method 3 (O(n) and requires one traversal)
The idea is to use two auxiliary arrays of size 256 (Assuming that characters are stored using 8 bits). The two arrays are:

count[x] : Stores count of character 'x' in str.
           If x is not present, then it stores 0.

index[x] : Stores indexes of non-repeating characters
           in str. If a character 'x' is not  present
           or x is repeating, then it stores  a value
           that cannot be a valid index in str[]. For
           example, length of string.
Initialize all values in count[] as 0 and all values in index[] as n where n is length of string.
Traverse the input string str and do following for every character c = str[i].
Increment count[x].
If count[x] is 1, then store index of x in index[x], i.e., index[x] = i
If count[x] is 2, then remove x from index[], i.e., index[x] = n
Now index[] has indexes of all non-repeating characters. Sort index[] in increasing order so that we get k’th smallest element at index[k].
Note that this step takes O(1) time because there are only 256 elements in index[].*/

char KthNonRepeating(stirng s, int K) {
    int n = s.length();

    int cnt[256] = {}, idx[256];
    fill(idx, idx + 256, n);

    REP(i, 0, n) {

        char x = s[i];

        cnt[x]++;

        if (cnt[x] == 1) idx[x] = i;

        if (cnt[x] == 2) idx[x] = n;
    }

    sort(idx, idx + 256);

    return (idx[K - 1] != n) ? idx[K - 1] : '\0';
}

///////////////////////////////////////////////////////////////
// the above code can be further optimized by taking the cnt[] array as the idx[] array

fill(cnt, cnt + 256, n);

for (int i = 0; i < n; ++i) {

    char x = s[i];

    if (cnt[x] == n) cnt[x] = i; // if the char appears for the first time

    else cnt[x] = n + 1; // if the char appears again
}

sort(cnt, cnt + 256);

return (cnt[K - 1] < n) ? cnt[K - 1] : '\0';

////////////////////////////////////////////////////////////////////