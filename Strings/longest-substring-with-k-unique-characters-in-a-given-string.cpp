// C++ program to find the longest substring with k unique
// characters in a given string
#include <iostream>
#include <cstring>
using namespace std;
 
bool notValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i < 26; i++)
        if (count[i] > 0)
            val++;
 
    // Return true if k is greater than or equal to val
    return (val > k);
}
 
// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
    int u = 0; // number of unique characters
    int n = s.length();
 
    // Associative array to store the count of characters
    int f[26];
    memset(f, 0, sizeof(f));
 
    for (int i = 0; i < n; ++i) {
        if (f[s[i]-'a'] == 0) u++;
        f[s[i]-'a']++;
    }
 
    // If there are not enough unique characters, show
    // an error message.
    if (u < k)
    {
        cout << "Not enough unique characters";
        return;
    }
 
    int start = 0, mx = 1;
 
    // Initialize associative array f[] with zero
    memset(f, 0, sizeof(f));
 
    f[s[0]-'a']++; 
 
    for (int i=1; i<n; i++)
    {
        f[s[i]-'a']++;
 
        // If there are more than k unique characters in
        // current window, remove from left side
        while (notValid(f, k))
        {
            f[s[start]-'a']--;
            start++;
        }
 
        // Update the max window size if required
        if (i-start+1 > mx)
        {
            mx = i-start+1;
        }
    }
 
    cout << "Max sustring is : "
         << s.substr(start, mx)
         << " with length " << mx << endl;
}
 
// Driver function
int main()
{
    string s = "aabacbebebe";
    int k = 3;
    kUniques(s, k);
    return 0;
}
