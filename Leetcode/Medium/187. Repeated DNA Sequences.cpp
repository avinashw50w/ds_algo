/*The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) 
that occur more than once in a DNA molecule. You may return the answer in any order.

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.*/
class Solution {
public:
    struct Node {
        bool leaf;
        Node* ch[26];

        Node() {
            this->leaf = false;
            for (int i = 0; i < 26; i++) {
                this->ch[i] = NULL;
            }
        }
    };


    void insert(Node* root, string s) {
        int l = s.size();
        int index;
        Node *tmp = root;
        
        for (int i = 0; i < l; i++){
            index = s[i] - 'A';
            if (tmp->ch[index] == NULL)
                tmp->ch[index] = new Node();
            tmp = tmp->ch[index];
        }
        tmp->leaf = true;
    }


    bool search(Node* root, string s) {
        int l = s.size();
        Node* tmp = root;
        int index, found = 1;

        for (int i = 0; i < l; i++) {
            index = s[i] - 'A';
            if (tmp->ch[index] == NULL){
                found = 0; 
                break;
            }
            tmp = tmp->ch[index];
        }
        return tmp->leaf;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        Node *root = new Node();
        vector<string> res;
        unordered_set<string> st;

        for (int i = 0; i + 10 <= n; ++i) {
            string s2 = s.substr(i, 10);
            if (search(root, s2)) {
                st.insert(s2);
            } else {
                insert(root, s2);
            }
        }

        for (auto e: st) res.push_back(e);
            return res;
    }
};