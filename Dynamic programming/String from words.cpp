/*Given a string s and a list of words. check if s can formed by concatenation of a subset of words
eg. s = avinash, words = [av, tyu, nas, sh, ina]
*/

// each word can be taken multiple times
// without using dp the time complexity will be
// T: O(m^n), where m = words list size and n = string length
// 
// with using dp, the time complexity will be
// T: O(m * n^2)
unordered_map<string, int> dp;

int solve(string s, vector<string> words) {
    if (s == '') return true;

    if (dp[s]) return dp[s];

    for (string word: words) {
        // if word is a prefix
        if (s.find(word) == 0) {
            string suffix = s.substr(word.length);
            dp[s] |= solve(suffix, words);
        }
    }

    return dp[s];
}

// each word can be taken only once
unordered_map<string, int> dp;
// T: O(m * n^2)
bool solve(int pos, string s, vector<string> words) {
    if (s == '') return true;

    if (dp[s]) return dp[s];

    for (int i = pos; i < words.size(); ++i) {
        string word = words[i];
        // if word is a prefix
        if (s.find(word) == 0) {
            string suffix = s.substr(word.length);
            dp[s] |= solve(i+1, suffix, words);
        }
    }

    return dp[s];
}

solve(0, s, words);

////////////////////////////////////////////////////////////////
// Find the # of ways to construct the string

unordered_map<string, int> dp;
// T: O(m * n^2)
bool solve(int pos, string s, vector<string> words) {
    if (s == '') return 1;

    if (dp[s]) return dp[s];

    for (int i = pos; i < words.size(); ++i) {
        string word = words[i];
        // if word is a prefix
        if (s.find(word) == 0) {
            string suffix = s.substr(word.length);
            dp[s] += solve(i+1, suffix, words);
        }
    }

    return dp[s];
}

////////////////////////////////////////////////////////////////
// also find the words that concataneted to s
vector<string> words;
unordered_map<string, vector<string>> dp; // {word, path}

// T: O(m * n^2), where m = words list size and n = string length
bool solve(int pos, string s, vector<string> &path) {
    if (s == '') return true;

    if (dp.count(s)) return dp[s];

    for (int i = pos; i < words.size(); ++i) {
        string word = words[i];
        // if word is a prefix
        if (s.find(word) == 0) {
            string suffix = s.substr(word.length);
            if (solve(i+1, suffix, words)) {
                path.push_back(suffix);
                dp[s] = path;
                return true;
            }
        }
    }

    return false;
}

////////////////////////////////////////////////////////////////////////
// get all the ways to construct s from words
vector<vector<string>> res;
vector<string> words;

// T: O(m^n) where m = words list size and n = string length
void solve(int pos, string s, vector<string> path) {
    if (s == '') {
        res.push_back(path);
        return;
    }

    for (int i = pos; i < words.size(); ++i) {
        string word = words[i];
        if (s.find(word) != 0) continue;
        string suffix = s.substr(word.length);
        path.push_back(word);
        solve(i+1, suffix, path);
        path.pop_back()
    }    
}