/*Length of shortest chain to reach a target word
Given a dictionary, and two words ‘start’ and ‘target’ (both of same length). Find length of the smallest chain from ‘start’ 
to ‘target’ if it exists, such that adjacent words in the chain only differ by one character and each word in the chain is a 
valid word i.e., it exists in the dictionary. It may be assumed that the ‘target’ word exists in dictionary and length of all dictionary words is same.

Example:

Input:  Dictionary = {POON, PLEE, SAME, POIE, PLEA, PLIE, POIN}
             start = TOON
             target = PLEA
Output: 7
Explanation: TOON - POON - POIN - POIE - PLIE - PLEE - PLEA
We strongly recommend you to minimize your browser and try this yourself first.

The idea is to use BFS. We start from the given start word, traverse all words that adjacent (differ by one character) 
to it and keep doing so until we find the target word or we have traversed all words.*/

// C++ program to find length of the shortest chain
// transformation from source to target
#include <bits/stdc++.h>
using namespace std;

class Graph {

    unordered_map<string, unordered_set<string>> G;
    vector<int> dist;
    int N;
    
public:
    Graph(int N) {
        this->N = N;
        dist.assign(N, -1);
    }
    // check if two strings differ by only 1 character
    bool isAdjacent(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < min(s1, s2); ++i) cnt += (s1[i] != s2[i]);

        return (cnt == 1);
    }

    void addEdge(string s1, string s2) {
        G[s1].insert(s2);
        G[s2].insert(s1);
    }

    void bfs(string src, string dest) {
        queue<string> Q;
        Q.push(src);
        dist[src] = 0;

        while (!Q.empty()) {
            string top = Q.front();

            for (string v: G[top]) {
                if (dist[v] == -1) {
                    dist[v] = dist[top] + 1;
                    Q.push(v);
                }

                if (v == dest) return dist[v];
            }
        }

        return -1;
    }

    int solve(vector<string> dict, string src, string dest) {
        for (int i = 0; i < dict.size()-1; ++i)
            for (int j = i+1; j < dict.size(); ++j)
                if (isAdjacent(dict[i], dict[j]))
                    addEdge(dict[i], dict[j]);

        int dist = bfs(src, dest);

        return dist;
    }
};
/*
Output:

Length of shortest chain is: 7
Time Complexity of the above code is O(n²m) where n is the number of entries originally in the dictionary and m is the size of the string*/