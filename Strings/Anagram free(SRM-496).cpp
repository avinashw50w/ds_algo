/*A string X is an anagram of string Y if X can be obtained by arranging all characters of Y in some order, without removing any 
characters and without adding new characters. For example, each of the strings "baba", "abab", "aabb" and "abba" is an anagram of "aabb", 
and strings "aaab", "aab" and "aabc" are not anagrams of "aabb". 

A set of strings is anagram-free if it contains no pair of strings which are anagrams of each other. Given a set of strings S, 
return the size of its largest anagram-free subset. Note that the entire set is considered a subset of itself.*/

/*We are given a set of strings S, and need to find the size of the largest subset A of S such that no two strings in A are anagrams of each other.

First, let's figure out when two strings a and b are anagrams of each other. This happens precisely when the letters used to build a and b are the same. 
So, for each string in S, we just need to store the set of letters needed to build it, and count how many distinct such sets there are.

A simple way to do this is to sort the contents of each string a in S, since two strings which are anagrams would then be sorted to the same string. 
For example, the strings "abgska" and "kaagsb" would both be transformed to "aabgks", and so would any other anagram of "abgska".

All that is left is to find how many distinct sorted strings there are. This can be done by, for example, putting all the 
sorted strings into a set data structure (which is available in most programming languages), and returning the size of the set.

Here is an example of a short C++ implementation: */

   set<string> A;                      // Declare a set A, which will contain the sorted strings
   for(int i = 0; i < S.size(); i++)
   {
      sort(S[i].begin(), S[i].end());  // Convert each string into its sorted form...
      A.insert(S[i]);                  // ... and put it into A
   }
   return A.size();         

   /*Let's end with a little extension. Given a set of strings S, can you design an algorithm that calculates the 
   minimum size of a subset of S that is not anagram-free (or returns -1 if such a set does not exist)?*/
   /*Simply find the smallest set of strings which are anagrams of each other. */

   map<string,int> M;
   for(int i = 0; i < S.size(); ++i)
   {
   		sort(S[i].begin(), S[i].end());
   		if(M.count(S)) M[S]++;
   }

   int ans = INF;
   for(auto i: M) 
   	ans = min(ans, i.second);

   return ans;

   