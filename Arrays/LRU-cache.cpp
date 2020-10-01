
struct Node {
    string key, value;
};

class LRU {
    int cache_size;
    deque<int> list;
    unordered_map<int> mp;

    LRU(int N) {
        this->cache_size = N;
    }

    void set(int key, value) {
        // if key is already present
        if (mp.count(key)) {
            list.erase(find(list.begin(), list.end(), key));
            list.push_front(key);
        }
        else {
            // if cache is full
            if (list.size() == cache_size) {
                mp.erase(list.back());
                list.pop_back();
            }
            list.push_front(key);
            mp[key] = value;
        }
    }

    int get(int key) {
        if (mp.count(key)) return mp[key];
        else return -1;
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
