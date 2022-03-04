/*Minimum Swaps for Bracket Balancing
You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets.
A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2
are balanced strings. We can make an unbalanced string balanced by swapping ADJACENT
characters. Calculate the minimum number of swaps necessary to make a string balanced.

Examples:

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Naive approach:
Initialize sum = 0 where sum stores result. Go through the string maintaining a count of the
 number of ‘[‘ brackets encountered. Reduce this count when we encounter a ‘]’ character.
 If the count hits negative, then we must start balancing the string.
Let index ‘i’ represents the position we are at. We now move forward to the next ‘[‘ at index
j. Increase sum by j – i because j-i swaps are needed. Move the ‘[‘ at position j,
to position i, and shift all other characters to the right. Set the count back to 0 and
continue traversing the string. In the end, ‘sum’ will have the required value.

Time Complexity = O(N^2)
Extra Space = O(1)

Better one: store the position of the next '['.
Time: O(N), space: O(N)

Efficient one: no need to store positions. Just maintain the imbalance, which is
(no of ']' so far - no of '[' so far).
Time: O(N), space: O(1)

For balanced brackets upto index i: 
the #of open brackets should be(open) >= #of closing brackets(close)
if it's not, then there is an imbalance of (close - open) which should be corrected by open brackets. 

[[]]][
o = 1, c = 0, im = -1
o = 2, c = 0, im = -2
o = 2, c = 1, im = -1
o = 2, c = 2, im = 0
o = 2, c = 3, im = 1
o = 3, c = 3, im = 0 => in this step the previous imbalance was > 0, so we used this [ to 
balance the imbalanced ]
*/


int solve(string s) {
    int n = s.length();

    int imbalance = 0, swaps = 0, open = 0, close = 0;
    for (char c : s) {
        if (c == ']') {
            close++;
            imbalance = close - open;
        }
        else {
            open++;
            if (imbalance > 0) {
                swaps += imbalance;
                imbalance--;
            }
        }
    }

    return imbalance == 0 ? swaps : -1;
}

// another variation
// we can swap any two chars (not necessarily adjacent)
// Sol: keep track of maximum consecutive closed brackets ']'
// on swap of 1 '[' with 1 ']' gets rid of two ']'
// eg. ]]][[[ : swapping 3rd index with the 0th index 
// []]][[
int solve(string s) {
    int n = s.length();
    int close = 0, maxClose = 0;
    for (char c: s) {
        if (c == ']') close++;
        else close--;
        maxClose = max(maxClose, close);
    }
    return (maxClose + 1) / 2;
}