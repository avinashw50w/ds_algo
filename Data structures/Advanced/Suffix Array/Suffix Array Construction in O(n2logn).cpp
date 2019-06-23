/*A suffix array is a sorted array of all suffixes of a given string. The definition is similar to Suffix Tree which is 
compressed trie of all suffixes of the given text. Any suffix tree based algorithm can be replaced with an algorithm that uses 
a suffix array enhanced with additional information and solves the same problem in the same time complexity (Source Wiki).
A suffix array can be constructed from Suffix tree by doing a DFS traversal of the suffix tree. In fact Suffix array and
suffix tree both can be constructed from each other in linear time.
Advantages of suffix arrays over suffix trees include improved space requirements, simpler linear time construction algorithms 
(e.g., compared to Ukkonen’s algorithm) and improved cache locality (Source: Wiki)

Example:

Let the given string be "banana".

0 banana                          5 a
1 anana     Sort the Suffixes     3 ana
2 nana      ---------------->     1 anana  
3 ana        alphabetically       0 banana  
4 na                              4 na   
5 a                               2 nana

So the suffix array for "banana" is {5, 3, 1, 0, 4, 2}
Naive method to build Suffix Array
A simple method to construct suffix array is to make an array of all suffixes and then sort the array. 
Following is implementation of simple method.*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct suffix {
	int index;
	char* suff;
};

int cmp(struct suffix a, struct suffix b) {
	return strcmp(a.suff, b.suff) < 0 ? 1: 0;
}

int* buildSuffixArray(char* txt, int N) {
	suffix suffixes[N];

	for(int i = 0; i < N; ++i) {
		suffixes[i].index = i;
		suffixes[i].suff = (txt + i);
	}

	sort(suffixes, suffixes+n, cmp);

	int suffixArray[N];

	for(int i = 0; i < N; ++i)
		suffixArray[i] = suffixes[i].index;

	return suffixArray;
}

/*Search a pattern using the built Suffix Array
To search a pattern in a text, we preprocess the text and build a suffix array of the text. Since we have a sorted array of 
all suffixes, Binary Search can be used to search. Following is the search function. Note that the function doesn’t report all 
occurrences of pattern, it only report one of them.*/

int serach(char* pat, char* txt, int* suffixArray, int N) {
	int M = strlen(pat);

	int l = 0, r = N-1;

	while(l <= r) {
		int mid = (l+r) >> 1;
		int res = strncmp(pat, txt+suffixArray[mid], M);

		if(res == 0) return suffixArray[mid];

		if(res < 0) r = mid - 1;

		else l = mid + 1;
	}
	// pattern not found
	return -1;
}

int main() {
	char txt[] = "banana";
	int n = strlen(txt);

	int* suffixArray = buildSuffixArray(txt, n);

	for(int i = 0; i < n; ++i)
		cout << suffixArray[i] << " ";
	cout << endl;
}

////////////////////////////////////////////////////////////
// another implementation of generating suffix array in O(n2logn)

void constructSuffixArray() {
	string s;
    cin >> s;
    vector<pair<string,int> > v;
    
    for(int i = 0; i < s.size();i++)
    {
        v.push_back({s.substr(i, string::npos), i});
    }
    
    sort(v.begin(),v.end());
    
    for(int i = 0; i < v.size();i++)
    {
        cout << v[i].second << endl;
    }
}