/*algo:
store a value "value" with key "key"
we use hashmap to store the key value pairs, and a deque to maintain the order of occurrence of the keys
set(key, value)
- if key is already present in the map, then remove the key from the list and push it to the front.
- if key is not present:
    - if cache_size is full: remove the last element from the list. Also remove it from the map
    else: push the element to the front of the list
*/
class LRU {
    int cache_size;
    deque<int> list;
    unordered_map<int, int> mp;

    LRU(int N) {
        this->cache_size = N;
    }

    void set(int key, int value) {
        if (mp.count(key)) {
            list.erase(find(list.begin(), list.end(), key));
            list.push_front(key);
        }
        else {
            if (list.size() == cache_size) {
                mp.erase(list.back());
                list.pop_back();
            }
            list.push_front(key);
            mp[key] = value;
        }
    }

    int get(int key) {
        return mp.count(key) ? mp[key] : -1;
    }
};
