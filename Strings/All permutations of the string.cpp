// C program to print all permutations with duplicates allowed

// output: 123 132 213 321
// NOTE: all the permutations will not be distinct if the input contains duplicate characters
// for getting only distinct permutations, use the next_permutation func
// or implement the function if asked by the interviewer
void permute(string s, int pos, int N) {
  if (pos == N) {
    cout << s << " ";
    return;
  }
  for (int i = pos; i < N; ++i) {
    swap(s[pos], s[i]);
    permute(s, i + 1, N);
    swap(s[pos], s[i]);
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
