/*Suffix Array | Set 2 (nLogn Algorithm)
3.7
A suffix array is a sorted array of all suffixes of a given string. The definition is similar to Suffix Tree which is compressed 
trie of all suffixes of the given text.

Let the given string be "banana".

0 banana                          5 a
1 anana     Sort the Suffixes     3 ana
2 nana      ---------------->     1 anana  
3 ana        alphabetically       0 banana  
4 na                              4 na   
5 a                               2 nana

The suffix array for "banana" is {5, 3, 1, 0, 4, 2} 
We have discussed Naive algorithm for construction of suffix array. The Naive algorithm is to consider all suffixes, 
sort them using a O(nLogn) sorting algorithm and while sorting, maintain original indexes. Time complexity of the Naive 
algorithm is O(n2Logn) where n is the number of characters in the input string.

In this post, a O(nLogn) algorithm for suffix array construction is discussed. Let us first discuss a O(n * Logn * Logn) 
algorithm for simplicity. The idea is to use the fact that strings that are to be sorted are suffixes of a single string.
We first sort all suffixes according to first character, then according to first 2 characters, then first 4 characters and 
so on while the number of characters to be considered is smaller than 2n. The important point is, if we have sorted suffixes 
according to first 2i characters, then we can sort suffixes according to first 2i+1 characters in O(nLogn) time using a nLogn 
sorting algorithm like Merge Sort. This is possible as two suffixes can be compared in O(1) time (we need to compare only 
two values, see the below example and code).
The sort function is called O(Logn) times (Note that we increase number of characters to be considered in powers of 2). 
Therefore overall time complexity becomes O(nLognLogn). See http://www.stanford.edu/class/cs97si/suffix-array.pdf for more details.

Let us build suffix array the example string “banana” using above algorithm.

Sort according to first two characters Assign a rank to all suffixes using ASCII value of first character. 
A simple way to assign rank is to do “str[i] – ‘a'” for ith suffix of strp[]

Index     Suffix            Rank
 0        banana             1   
 1        anana              0 
 2        nana               13 
 3        ana                0
 4        na                 13
 5        a                  0 
For every character, we also store rank of next adjacent character, i.e., the rank of character at str[i + 1] 
(This is needed to sort the suffixes according to first 2 characters). If a character is last character, we store next rank as -1

Index    Suffix            Rank          Next Rank 
 0       banana             1              0
 1       anana              0              13    
 2       nana               13             0
 3       ana                0              13
 4       na                 13             0 
 5       a                  0             -1 
Sort all Suffixes according to rank and adjacent rank. Rank is considered as first digit or MSD, and adjacent rank is 
considered as second digit.

Index    Suffix            Rank          Next Rank 
 5        a                  0              -1
 1        anana              0               13    
 3        ana                0               13
 0        banana             1               0
 2        nana               13              0
 4        na                 13              0  
Sort according to first four character
Assign new ranks to all suffixes. To assign new ranks, we consider the sorted suffixes one by one. Assign 0 as new rank 
to first suffix. For assigning ranks to remaining suffixes, we consider rank pair of suffix just before the current suffix. 
If previous rank pair of a suffix is same as previous rank of suffix just before it, then assign it same rank. 
Otherwise assign rank of previous suffix plus one.

Index       Suffix          Rank       
  5          a               0     [Assign 0 to first]        
  1          anana           1     (0, 13) is different from previous
  3          ana             1     (0, 13) is same as previous     
  0          banana          2     (1, 0) is different from previous      
  2          nana            3     (13, 0) is different from previous      
  4          na              3     (13, 0) is same as previous      
For every suffix str[i], also store rank of next suffix at str[i + 2]. If there is no next suffix at i + 2, 
we store next rank as -1

Index       Suffix          Rank        Next Rank
  5          a               0             -1
  1          anana           1              1      
  3          ana             1              0 
  0          banana          2              3
  2          nana            3              3 
  4          na              3              -1       
Sort all Suffixes according to rank and next rank.

Index       Suffix          Rank        Next Rank
  5          a               0             -1
  3          ana             1              0 
  1          anana           1              1      
  0          banana          2              3
  4          na              3             -1
  2          nana            3              3     */

struct suffix {
	int index;
	int rank[2];
};

int cmp(struct suffix a, struct suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1: 0) : (a.rank[0] < b.rank[0] ? 1: 0);
}

int* buildSuffixArray(char* txt, int N) {
	suffix suffixes[N];

	for(int i = 0; i < N; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'a';
		suffixes[i].rank[1] = (i+1 < n) ? txt[i+1] - 'a' : -1;
	}

  // sort according to the first 2 characters
	sort(suffixes, suffixes+N; cmp);

	int ind[N]; // to store the index of each suffix

	// At his point, all suffixes are sorted according to first
    // 2 characters.  Let us sort suffixes according to first 4
    // characters, then first 8 and so on
    for(int k = 4; k < 2*N; k *= 2) {
    	int rank = 0;
    	int prevRank = suffixes[0].rank[0];
    	suffixes[0].rank[0] = 0;
    	ind[suffixes[0].index] = 0;

    	for(int i = 1; i < N; ++i) {
    		// If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
            if(suffixes[i].rank[0] == prevRank and suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
            	prevRank = suffixes[i].rank[0];
            	suffixes[i].rank[0] = rank;
            }
            else {
            	prevRank = suffixes[i].rank[0];
            	suffixes[i].rank[0] = ++rank;
            }

            ind[suffixes[i].index] = i;
    	}

    	// Assign next rank to every suffix
    	for(int i = 0; i < N; ++i) {
    		int nextIndex = suffixes[i].index + k/2;
    		suffixes[i].rank[1] = (nextIndex < N) ? suffixes[ind[nextIndex]].rank[0] : -1;
    	}

    	sort(suffixes, suffixes+N, cmp);

    	int suffixArray[N];

    	for(int i = 0; i < N; ++i)
    		suffixArray[i] = suffixes[i].index;

    	return suffixArray;
    }
}

int main() {
	char txt[] = "banana";
	int n = strlen(txt);

	int* suffixArray = buildSuffixArray(txt, n);

	for(int i = 0; i < n; ++i)
		cout << suffixArray[i] << " ";
	cout << endl;
}

////////////////////////////////////////////////////////////////////

// another implementation
const int MAXN = 60606;
const int LOGN = 18;
// suffixRank is table hold the rank of each string on each iteration  
// suffixRank[i][j] denotes rank of jth suffix at ith iteration  
int suffixRank[LOGN][MAXN];

struct suffix {
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b) {
    if(a.rank[0] == b.rank[0]) return a.rank[1] < b.rank[1];
    else return a.rank[0] < b.rank[0];
}

void solve(string S) {

    int N = S.size();
    // store the initial rank of every character in the string
    for(int i = 0; i < N; ++i) suffixRank[0][i] = S[i] - 'a';

    suffix L[N];

    for(int ctn = 1, stp = 1; cnt < N; ++stp, cnt *= 2) {
        // assign rank of ith and (i+cnt)th character
        for(int i = 0; i < N; ++i) {
            L[i].rank[0] = suffixRank[stp - 1][i];
            L[i].rank[1] = i + cnt < N ? suffixRank[stp - 1][i + cnt] : -1;
            L[i].index = i;
        }

        sort(L, L + N, cmp);

        // find the equivalent rank of (suffix[i].rank[0], suffix[i].rank[1]) for all i
        suffixRank[stp][L[0].index] = 0;

        for(int i = 1, rank = 0; i < N; ++i) {
            if(L[i-1].rank[0] != L[i].rank[0] || L[i-1].rank[1] != L[i].rank[1]) rank++;

            suffixRank[stp][L[i].index] = rank;
        }
    }

    int result[N];

    for(int i = 0; i < N; ++i) result[i] = L[i].index;

    return result;
}

//////////////////////////////////////////////////////////////////////////////////////

// a much simpler implementation

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    char * S;
    int N, gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
    
    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = strlen(S);
        REP(i, N) sa[i] = i, pos[i] = S[i];
        for (gap = 1;; gap *= 2)
        {
            sort(sa, sa + N, sufCmp);
            REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            REP(i, N) pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }

    void buildLCP()
    {
        for (int i = 0, k = 0; i < N; ++i)
        { 
            if (pos[i] != N - 1)
            {
                for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];) ++k;
                lcp[pos[i]] = k;
                if (k) --k;
            }
        }
    }
} // end namespace SuffixArray