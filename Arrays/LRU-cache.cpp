#include<iostream>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

struct Node {
    string key, value;
};

class LRUCache {

    list<Node> L;
    unordered_map<string, list<string>::iterator> hash;
    int cache_sz;

public:
    LRUCache(int N) {
        cache_sz = N;
    }

    void set(string key, string value) {
        // if key already exists, put that node to the front of the list
        if (hash.count(key)) {
            auto it = hash[key];
            deleteFromList(it);
            pushToFront(Node(key, value));
            hash[key] = L.begin();
        }
        else {
            if (L.size() >= cache_sz) {
                auto it = L.end();
                hash.erase((*it).key);
                deleteFromList(it);
            }
            pushToFront(Node(key, value));
            hash[key] = L.begin();
        }
    }

    string get(string key) {
        if (hash.count(key) == 0) return "";

        auto it = hash[key];
        deleteFromList(it);
        pushToFront(Node(key, (*it).value));

        hash[key] = L.begin();

        return (*it).value;
    }

    void deleteFromList(list<string>::iterator it) {
        L.erase(it);
    }

    void pushToFront(Node node) {
        L.push_front(node);
    }
};


//////////////////////////////////
const int cache_sz = 4;

void ReferencePage(list<int>& L, unordered_map<int, int>& hash, int page)
{
    if (L.size() < cache_sz)
    {
        L.push_front(page);
        hash[page] = page;
    }
    else // list full
    {
        // if page already exists in the list
        if (hash.count(page))
        {
            list<int>::iterator itr = std::find(L.begin(), L.end(), page);
            L.erase(itr);
            L.push_front(page);
        }
        else // page NOT present in list
        {
            hash.erase(L.back());
            L.erase(L.end());

            L.push_front(page);
            hash[page] = page;
        }
    }
}

// Driver program to test above functions
int main()
{
    list<int> L;
    unordered_map<int, int> hash;

    // Let us refer pages 1, 2, 3, 1, 4, 5
    ReferencePage(L, hash, 1);
    ReferencePage(L, hash, 2);
    ReferencePage(L, hash, 3);
    ReferencePage(L, hash, 1);
    ReferencePage(L, hash, 4);
    ReferencePage(L, hash, 5);

    // Let us print cache frames after the above referenced pages
    for (auto& val : L)
    {
        cout << val << endl;
    }

    return 0;
}
