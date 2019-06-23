#include<iostream>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {

    list<int> L;
    unordered_map<int> hash;
    int cache_sz;

public:
    LRUCache(int N) {
        cache_sz = N;
    }

    void set(int x, int y) {
        if (L.size() < cache_sz) {
            L.push_front(y);
            hash[x] = y;
            return;
        }

        // check if the page exists in the list
        if (hash.count(x)) {
            auto it = find(L.begin(), L.end(), y);
            L.erase(it);
            L.push_front(y);
        }
        else {
            L.erase(L.end());
            hash.erase(L.back());

            L.push_front(y);
            hash[x] = y;
        }
    }

    int get(int x) {
        if (hash.count(x) == 0) return -1;

        return *find(L.begin(), L.end(), hash[x]);
    }
};

const int cache_sz = 4
 
void ReferencePage(list<int>& L, unordered_map<int, int>& hash, int page)
{
    if (L.size() < cache_sz)
    {
        L.push_front(page);
        hash[page] = page;
    }
    else // list full
    {
        list<int>::iterator itr = std::find(L.begin(), L.end(), page);
 
        if (itr != L.end()) // page already present in list
        {
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