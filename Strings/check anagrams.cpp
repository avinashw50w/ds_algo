#include <bits/stdc++.h>
using namespace std;

bool anagram(string s1, string s2) {
	if(s1.length() != s2.length()) return false;
    
    transform(s1.begin(), s1.end(), s1.begin(),::tolower); 
   	transform(s2.begin(), s2.end(), s2.begin(),::tolower);

   	int f[26] = {};

   	for(int i = 0; i < s1.length(); ++i) f[s1[i] - 'a']++, f[s2[i] - 'a']--;

   	for(int i = 0; i < 26; ++i) if(f[i] != 0) return false;

   	return true;
}

int main() 
{
	anagram("AGGS", "HK");
}