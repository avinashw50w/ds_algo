/*1) Create an empty stack and push -1 to it. The first element
   of stack is used to provide base for next valid string.

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index
   'i' to the stack.

2) Else (if the character is ')')
   a) Pop an item from stack (Most of the time an opening bracket)
   b) If stack is not empty, then find length of current valid
      substring by taking difference between current index and
      top of the stack. If current length is more than result,
      then update the result.
   c) If stack is empty, push current index as base for next
      valid substring.

3) Return result.
Below is C++ implementation of above algorithm.*/

// C++ program to find length of the longest valid
// substring
// using stack
int findMaxLen(string str)
{
  int n = str.length();
  stack<int> stk;
  stk.push(-1);
  int result = 0;

  // Traverse all characters of given string
  for (int i = 0; i < n; i++)
  {
    // If opening bracket, push index of it
    if (str[i] == '(')
      stk.push(i);

    else
    {
      stk.pop();
      if (!stk.empty())
        result = max(result, i - stk.top());

      else stk.push(i);
    }
  }

  return result;
}

// using dp
// dp[i] : longest valid parenthesis upto index i
// if ) is at i and ( at i - dp[i-1] - 1 then dp[i] = dp[i-1] + 2

int solve(string s) {
  int n = s.length();
  int dp[n] = {};

  for (int i = 0; i < n; ++i) {
    if (s[i] == ')' and i - dp[i - 1] - 1 >= 0 and s[i - dp[i - 1] - 1] == '(') {
      dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
    }

    return dp[n];
  }
}

// Driver program
int main()
{
  string str = "((()()";
  cout << findMaxLen(str) << endl;

  str = "()(()))))";
  cout << findMaxLen(str) << endl ;

  return 0;
}
