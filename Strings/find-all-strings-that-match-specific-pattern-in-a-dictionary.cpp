/*Given a dictionary of words, find all strings that matches the given pattern where every 
character in the pattern is uniquely mapped to a character in the dictionary.

Examples:

Input:  
dict = ["abb", "abc", "xyz", "xyy"];
pattern = "foo"
Output: [xyy abb]
Explanation: 
xyy and abb have same character at index 1 and 2 like the pattern

Input:  
dict = ["abb", "abc", "xyz", "xyy"];
pat = "mno"
Output: [abc xyz]
Explanation: 
abc and xyz have all distinct characters, similar to the pattern

The idea is to encode the pattern in such a way that any word from the dictionary that matches the pattern will have same hash as that of the pattern 
after encoding. We iterate through all words in dictionary one by one and print the words that have same hash as that of the pattern.*/

// C++ program to print all the strings that match the
// given pattern where every character in the pattern is
// uniquely mapped to a character in the dictionary
#include <bits/stdc++.h>
using namespace std;
 
// Function to encode given string
string encodeString(string str)
{
    unordered_map<char, int> map;
    string res = "";
    int i = 0;
 
    // for each character in given string
    // eg, hash key for xyz : 012 , for xyy : 011 , for abbcad : 011203
    for (char ch : str)
    {
        if (map.find(ch) == map.end())
            map[ch] = i++;
 
        res += to_string(map[ch]);
    }
 
    return res;
}
 
void findMatchedWords(unordered_set<string> dict, string pattern)
{
    int len = pattern.length();
 
    string hash = encodeString(pattern);
 
    for (string word : dict)
    {

        if (word.length() == len && encodeString(word) == hash)
            cout << word << " " ;
    }
}
 
// Driver code
int main()
{
    unordered_set<string> dict = { "abb", "abc", "xyz", "xyy" };
    string pattern = "foo";
 
    findMatchedWords(dict, pattern);
 
    return 0;
}
