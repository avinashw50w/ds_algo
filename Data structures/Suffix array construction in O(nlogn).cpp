/*Background
Suffix Array : A suffix array is a sorted array of all suffixes of a given string.
Let the given string be “banana”.
0 banana                          5 a
1 anana     Sort the Suffixes     3 ana
2 nana      ---------------->     1 anana  
3 ana        alphabetically       0 banana  
4 na                              4 na   
5 a                               2 nana
The suffix array for “banana” :

suffix[] = {5, 3, 1, 0, 4, 2}

We have discussed Suffix Array and it O(nLogn) construction .

Once Suffix array is built, we can use it to efficiently search a pattern in a text. 
For example, we can use Binary Search to find a pattern (Complete code for the same is discussed here)

LCP Array

The Binary Search based solution discussed here takes O(m*Logn) time where m is length of the pattern to be searched 
and n is length of the text. With the help of LCP array, we can search a pattern in O(m + Log n) time. 
For example, if our task is to search “ana” in “banana”, m = 3, n = 5.
LCP Array is an array of size n (like Suffix Array). A value lcp[i] indicates length of the longest common prefix 
of the suffixes inexed by suffix[i] and suffix[i+1]. suffix[n-1] is not defined as there is no suffix after it.

txt[0..n-1] = "banana"
suffix[]  = {5, 3, 1, 0, 4, 2| 
lcp[]     = {1, 3, 0, 0, 2, 0}

Suffixes represented by suffix array in order are:
{"a", "ana", "anana", "banana", "na", "nana"}


lcp[0] = Longest Common Prefix of "a" and "ana"     = 1
lcp[1] = Longest Common Prefix of "ana" and "anana" = 3
lcp[2] = Longest Common Prefix of "anana" and "banana" = 0
lcp[3] = Longest Common Prefix of "banana" and "na" = 0
lcp[4] = Longest Common Prefix of "na" and "nana" = 2
lcp[5] = Longest Common Prefix of "nana" and None = 0
How to construct LCP array?
LCP array construction is done two ways:
1) Compute the LCP array as a byproduct to the suffix array (Manber & Myers Algorithm)
2) Use an already constructed suffix array in order to compute the LCP values. (Kasai Algorithm).

There exist algorithms that can construct Suffix Array in O(n) time and therefore we can always construct 
LCP array in O(n) time. But in the below implementation, a O(n Log n) algorithm is discussed.

kasai’s Algorithm

In this article kasai’s Algorithm is discussed. The algorithm constructs LCP array from suffix array and input text in O(n) time. 
The idea is based on below fact:
Let lcp of suffix beginning at txt[i[ be k. If k is greater than 0, then lcp for suffix beginning at txt[i+1] will be 
at-least k-1. The reason is, relative order of characters remain same. If we delete the first character from both suffixes, 
we know that at least k characters will match. For example for substring “ana”, lcp is 3, so for string “na” lcp will be at-least 2.*/
/*I'd recommend reading the paper "Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications" 
by Toru Kasai, Gunho Lee, Hiroki Arimura, Setsuo Arikawa, and Kunsoo Park.

It shows how to find the length of the longest common prefixes between consecutive suffixes in lineal time, 
in around 10 lines of code (really, see code in edit).

I also wanted to share my implementation of Manber & Myers algorithm which is also on edit. I got Accepted on SUBST1 with it.

// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
// Refer to "Suffix arrays: A new method for on-line string searches",
// by Udi Manber and Gene Myers
 
//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!
 
//Output:
// SA = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// rank = The inverse of the suffix array. rank[i] = the index of the suffix str[i..n)
//        in the SA array. (In other words, SA[i] = k <==> rank[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if rank[i] < rank[j]  */
 
int str[N]; //input
int rank[N], SA[N]; //output
int cnt[N], next[N]; //internal
bool bh[N], b2h[N];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i)
    SA[i] = i;
  
  sort(SA, SA + n, smaller_first_char);
  //{SA contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[SA[i]] != str[SA[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of SA[i-1] == the first h characters of SA[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}
 
    for (int i = 0; i < n; i = next[i]){
      cnt[i] = 0;
      for (int j = i; j < next[i]; ++j){
        rank[SA[j]] = i;
      }
    }
 
    cnt[rank[n - h]]++;
    b2h[rank[n - h]] = true;
    for (int i = 0; i < n; i = next[i]){
      for (int j = i; j < next[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0){
          int head = rank[s];
          rank[s] = head + cnt[head]++;
          b2h[rank[s]] = true;
        }
      }
      for (int j = i; j < next[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0 && b2h[rank[s]]){
          for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      SA[rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    rank[SA[i]] = i;
  }
}
// End of suffix array algorithm
 
 
// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int LCP[N];
// LCP[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// LCP[0] = 0
void getLCA(int n){
  for (int i=0; i<n; ++i) rank[SA[i]] = i;
  LCP[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (rank[i] > 0){
      int j = SA[rank[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      LCP[rank[i]] = h;
      if (h > 0) h--;
    }
  }
}
// End of longest common prefixes algorithm
 