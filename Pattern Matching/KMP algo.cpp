// C program for implementation of KMP pattern searching 
// algorithm
// lps[i] : the length of the longest proper suffix which is also a proper prefix of the string from index 0-i
void computeLPSArray(char *pat, int M, int *lps)
{
    int j = 0, i = 1; 
 
    lps[0] = 0; // lps[0] is always 0

    while (i < M)
    {
       if (pat[i] == pat[j])
       {
            lps[i] = j+1;
            j++;
            i++;
       }
       else // (pat[i] != pat[j])
       {
            if (j != 0)
                j = lps[j-1];
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
       }
    }
}
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
 
// Driver program to test above function
int main()
{
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);
   return 0;
}
