/*Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in 
order from oldest to newest, including this letter just queried) spell one of the words in the 
given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.

IDEA: store words in reverse order into a trie
the query the stream of chars in reverse order
*/
class StreamChecker {
    static const int maxn = 4e4;
    static const int maxc = 26;
    int trie[maxn][maxc];
    int leaf[maxn];
    string chars;
    int sz = 0;

public:
    void insert(string word) {
        int node = 0;
        for (char c: word) {
            if (trie[node][c-'a'] == -1)
                trie[node][c-'a'] = ++sz;
            node = trie[node][c-'a'];
        }
        leaf[node]++;
    }
    
    StreamChecker(vector<string>& words) {
        memset(trie, -1, sizeof(trie));
        for (string w: words) {
            string s = w;
            reverse(s.begin(), s.end());
            insert(s);
        }
    }
    
    bool query(char c) {
        chars += c;
        int node = 0;
        for (int i = chars.length() - 1; i >= 0; --i) {
            // cout << trie[node][chars[i]-'a'] << " " <<chars[i] <<endl;
            if (trie[node][chars[i]-'a'] == -1) return false;
            node = trie[node][chars[i]-'a'];
            if (leaf[node]) return true;
        }
        return leaf[node] > 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */