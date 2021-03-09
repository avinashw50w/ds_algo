/*Method 2 (Linear Time)
Find the length of the longest substring without repeating characters.*/

int solve(string s) {
  int n = s.length();
  map<char, int> mp;
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n and mp.count(s[j]) == 0) {
      mp[s[i]]++;
      j++;
    }

    ans = max(ans, j - i);
    mp[s[i]]--;
  }

  return ans;
}

////////////////////////////////////////
/// another lengthy method
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256
int min(int a, int b);

int longestUniqueSubsttr(string str)
{
  int n = str.length();
  int cur_len = 1;  // lenght of current substring
  int max_len = 1;  // result
  int prev_index;  //  previous index
  int i;
  vector<int> visited(256, -1);

  /* Mark first character as visited by storing the index
     of first   character in visited array. */
  visited[str[0]] = 0;

  /* Start from the second character. First character is
     already processed (cur_len and max_len are initialized
     as 1, and visited[str[0]] is set */
  for (i = 1; i < n; i++)
  {
    prev_index =  visited[str[i]];
    // update the index of current character
    visited[str[i]] = i;

    /* If the currentt character is not present in the
       already processed substring or it is not part of
       the current NRCS, then do cur_len++ */
    if (prev_index == -1 || i - cur_len > prev_index)
      cur_len++;

    /* If the current character is present in currently
       considered NRCS, then update NRCS to start from
       the next character of previous instance. */
    else
    {
      /* Also, when we are changing the NRCS, we
         should also check whether length of the
         previous NRCS was greater than max_len or
         not.*/
      max_len = max(max_len, curr_len);

      cur_len = i - prev_index;
    }
  }

  // Compare the length of last NRCS with max_len and
  // update max_len if needed
  max_len = max(max_len, curr_len);

  return max_len;
}

/* A utility function to get the minimum of two integers */
int min(int a, int b)
{
  return (a > b) ? b : a;
}

/* Driver program to test above function */
int main()
{
  char str[] = "ABDEFGABEF";
  printf("The input string is %s \n", str);
  int len =  longestUniqueSubsttr(str);
  printf("The length of the longest non-repeating "
         "character substring is %d", len);
  return 0;
}
