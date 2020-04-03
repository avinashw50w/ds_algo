/*Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.*/

bool comp(string a, string b) { return a + b > b + a; }

string Solution::largestNumber(const vector<int> &A) {
    vector<string> S;
    
    for(int i = 0; i < A.size(); ++i)
        S.push_back(to_string(A[i]));
        
    sort(S.begin(), S.end(), comp);
    
    string res = "";
    
    for(int i = 0; i < S.size(); ++i)
        res += S[i];
        
    int pos = 0;
    while(res[pos] == '0' and pos+1 < res.size()) pos++;
    
    return res.substr(pos);
}
