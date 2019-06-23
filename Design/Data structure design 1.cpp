/*Design a data structure that supports insert, delete, search and getRandom in constant time
Design a data structure that supports following operations in Θ(1) time.

insert(x): Inserts an item x to the data structure if not already present.

remove(x): Removes an item x from the data structure if present. 

search(x): Searches an item x in the data structure.

getRandom(): Returns a random element from current set of elements

We strongly recommend to minimize your browser and try this yourself first.

We can use hashing to support first 3 operations in Θ(1) time. How to do the 4th operation? 
The idea is to use a resizable array (ArrayList in Java, vector in C) together with hashing. 
Resizable arrays support insert in Θ(1) amortized time complexity. To implement getRandom(), 
we can simply pick a random number from 0 to size-1 (size is number of current elements) and 
return the element at that index. The hash map stores array values as keys and array indexes as values.

Following are detailed operations.

insert(x)
1) Check if x is already present by doing a hash map lookup.
2) If not present, then insert it at the end of the array.
3) Add in hash table also, x is added as key and last array index as index.

remove(x)
1) Check if x is present by doing a hash map lookup.
2) If present, then find its index and remove it from hash map.
3) Swap the last element with this element in array and remove the last element.
Swapping is done because the last element can be removed in O(1) time.
4) Update index of last element in hash map.

getRandom()
1) Generate a random number from 0 to last index.
2) Return the array element at the randomly generated index.

search(x)
Do a lookup for x in hash map.*/

class MyDS {
	vector<int> v;
	map<int, int> hash;

public:
	void insert(int );
	void Delete(int );
	bool search(int );
	int getRandom();
}

void MyDS::insert(int x) {
	if(m.count(x) == 0) {
		v.push_back(x);
		m[x] = v.size() - 1;
	}
}

void MyDS::Delete(int x) {
	if(m.count(x) != 0) {
		int idx = m[x];
		int last = v[v.size()-1];
		v[idx] = last;
		v.pop_back();
		m.erase(x);
		m[last] = idx;
	}
}

bool MyDS::search(int x) { return m.count(x) > 0; }

int MyDS::getRandom() {

	return v[rand() % v.size()];
}