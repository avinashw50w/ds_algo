/*Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
] 
*/

vector<vector<int> > Solution::generate(int A) {
    
    vector<vector<int> > res;
    int p[A][A];
    
    for(int line = 0; line < A; ++line) {
        for(int i = 0; i <= line; ++i) {
            if(i == 0 or i == line) p[line][i] = 1;
            else p[line][i] = p[line-1][i-1] + p[line-1][i];
        }
    }
    for(int line = 0; line < A; ++line) {
        vector<int> v;
        for(int i = 0; i <= line; ++i)
            v.push_back(p[line][i]);
        res.push_back(v);
    }
    return res;
}
