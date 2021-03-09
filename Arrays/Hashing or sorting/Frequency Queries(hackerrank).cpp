/*You are given  queries. Each query is of the form two integers described below:
- 1,x : Insert x in your data structure.
- 2,y : Delete one occurence of y from your data structure, if present.
- 3,z : Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.
Operation   Array   Output
(1,1)       [1]
(2,2)       [1]
(3,2)                   0
(1,1)       [1,1]
(1,1)       [1,1,1]
(2,1)       [1,1]
(3,2)                   1
Return an array with the output: [0,1].*/

vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> f, fi;
    vector<int> res;
    for (auto q : queries) {
        if (q[0] == 1) {
            int freq = f[q[1]];
            if (fi[freq]) fi[freq]--;
            f[q[1]]++;
            fi[f[q[1]]]++;
        }
        else if (q[0] == 2) {
            int freq = f[q[1]];
            if (fi[freq]) fi[freq]--;
            if (f[q[1]]) f[q[1]]--;
            fi[f[q[1]]]++;
        }
        else if (q[0] == 3) {
            res.push_back(fi[q[1]] ? 1 : 0);
        }
    }
    return res;
}