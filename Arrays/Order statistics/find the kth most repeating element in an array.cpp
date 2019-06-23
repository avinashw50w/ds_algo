/* Method 1: (naive) store the frequency of array elements in f[], then sort the f array in descending order. print f[K-1]. */

/* Mehod 2: (using Max heap) 

We can further reduce the time complexity to O(klog(n)) by making use of max-heap('n' is the length of the input array). 
This approach would be very similar to heap sort algorithm. For understanding the concept of max-heap and heap sort you can refer this post.

This approach uses following steps - 
1. Using hash table, we first create a frequency table which stores the frequency of occurrence for each number. 
In this hash table, we define (key, value) tuple as tuple (number 'i', frequency of 'i').
2. Now we traverse this hash table and create an array which stores these (number, frequency) tuples.
3. We build the max-heap using this tuple array created in step #2. 
4. By property of max-heap, the root element(or element at 0th index) would be the most frequent element and hence 
would be the output for input n = 1. For finding out 2nd most frequent element, we swap the root element with the 
last element and re-arrange the remaining 'n - 1' elements to form a max-heap(let the length of the array be 'n'). 
Now in this newly created heap(without using the previous root), new root element would again be the largest element 
in the 'n - 1' elements and hence it would be the 2nd largest element in all 'n' elements.
5. It follows that if we repeat step #4 'k' times, we should be able to find out 'k'th most frequent number.

If 'n' is the length of the input array then step #1, #2 and #3 take O(n) time. Step #4 takes O(log(n)) 
time which is executed 'k' number of times hence overall time complexity of this algorithm is O(nlog(n)). 
Space complexity of this algorithm is O(n).*/

struct Node {
	int freq, num;
};

auto cmp = [](const Node &a, const Node &b) { return a.freq > b.freq; };

int find(int A[], int N, int K) {

	int f[100000+5] = {0};
	REP(i, 0, N) f[A[i]]++;

	priority_queue<Node, vector<Node>, decltype(cmp)> Q(cmp);

	for (int i = 0; i < K; ++i) Q.push(Node(f[A[i]], i));

	for (int i = K; i < N; ++i) {
		Node top = Q.top();

		if (f[A[i]] > top.freq) {
			Q.pop();
			Q.push(Node(f[A[i]]), i);
		}
	}

	return A[Q.top().num];
}
/*------------------------------------------------*/
void buildHeap(Node A[], int N) {
	for(int i = (N-1)/2; i >= 0; --i)
		maxHeapify(i);
}

void maxheapify(Node A[], int N, int i) {
	int m = i, l = 2*i+1, r = 2*i+2;

	if(l < N and A[l].freq > A[m].freq) m = l;
	if(r < N and A[r].freq > A[m].freq) m = r;

	if(m != i) {
		swap(A[m].freq, A[i].freq)
		maxHeapify(H, N, m);
	}
}
/*----------------------------------------------------*/