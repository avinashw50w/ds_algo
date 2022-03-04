/*Given a string S consisting of characters 0, 1, and ‘?’, the task is to count all possible 
combinations of the binary string formed by replacing ‘?’ by 0 or 1.*/

int solve(string s) {
    int cnt = 0;
    for (char c: s) if (c == '?') cnt++;
    return (1 << cnt);
}