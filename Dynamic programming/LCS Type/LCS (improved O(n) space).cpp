#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int lcs(string &s1, string &s2) {
  int m = s1.size();
  int n = s2.size();
  int L[2][n+1];
 
  for(int i=0; i<=m; i++) {
    int ii = i&1;
    for(int j=0; j<=n; j++) {
      if(i==0 || j==0)
        L[ii][j] = 0;
      else if(s1[i-1] == s2[j-1])
        L[ii][j] = 1 + L[1-ii][j-1];
      else
        L[ii][j] = max(L[1-ii][j], L[ii][j-1]);
    }
  }
 
  return L[m&1][n];
}
 
int main()
{
  string s1, s2;
  while(cin >> s1 >> s2)
    cout << "The Longest Common Sub-sequence Length is " << lcs(s1, s2) << "\n";
  return 0;
}
