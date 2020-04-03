/*Method 3 (Using Divide and Conquer))

In this post, Divide and Conquer approach is discussed. This approach doesn’t require extra space for heap and works in O(nk Log k)
We already know that merging of two linked lists can be done in O(n) time and O(1) space (For arrays O(n) space is required). 
The idea is to pair up K lists and merge each pair in linear time using O(1) space. After first cycle, K/2 lists are left each of size 2*N. 
After second cycle, K/4 lists are left each of size 4*N and so on. We repeat the procedure until we have only one list left.*/

struct Node {
	int data;
	Node* next;
};

Node* sortedMerge(Node *a, Node *b) {
	Node *result = NULL;

	if(a == NULL) return b;
	if(b == NULL) return a;

	if(a->data <= b->data) {
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	return result;
}

Node *mergeKLists(Node *a[], int last) {

	while(last != 0) {
		
		int i = 0, j = last;

		while(i < j) {

			a[i] = sortedMerge(a[i], a[j]);

			++i; --j;

			if(i >= j) last = j;
		}
	}

	return a[0];
}

// Driver program to test above functions
int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list
 
    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);
}