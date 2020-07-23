// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

void permute(string s, int l, int r) {
  if (l == r) {
    cout << s << endl;
    return;
  }

  for (int i = l; i <= r; i++) {
    swap(a[l], a[i]);
    permute(a, l + 1, r);
    swap(a[l], a[i]); //backtrack
  }
}

/* Driver program to test above functions */
int main()
{
  string s = "123";
  int n = s.size();
  permute(s, 0, n - 1);
  return 0;
}
