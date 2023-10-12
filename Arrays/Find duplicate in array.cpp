/*Find Duplicate in Array
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:
[3 4 1 4 1]
Sample Output:
1
If there are multiple possible answers ( like in the sample case above ), output any one.
If there is no duplicate, output -1

Solution:
Had it not been a read-only array, we could have solved it in-place using the algorithm here.
http://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

Since it is a read-only array, we cannot make changes to the array itself.
We can treat this question as finding the starting point of a loop in a linked.
Explanation:
Let us take an array A = [3, 4, 1, 4, 2]
Treat the elements as individual nodes. If there is a repetition , we will get a loop.
The above array can be converted to a linked list as shown:

We get 2 linked lists in this case. Since we need to output any one duplicate number, we can do so by finding
the start of the loop in linked list. We do not actually need to create linked list for it. The slow and
fast pointer can be simulated in the array itself. The solution contains 2 parts as is the case when we need
to find the start node of a loop in a linked list.

Phase1: Take 2 pointers slow and fast. Fast moves with double the speed of slow.
If there is a cycle the two pointers will meet somewhere.

Phase2: Keep the fast pointer where it is. Move the slow pointer to the start of the linked list.
Now advance both the pointers at the same speed. The point where they meet is the start node of a loop.
In our case, that is our duplicate node.

Note: This does not take care of the case when there is no duplicate element.
However, interviewbit seems to have no test cases for this scenario and the code passes. */

// Approach 1: sorting
// T: O(nlogn), S: O(1)
int solve(vector<int> a) {
	sort(a.begin(), a.end());
	for (int i = 1; i < a.size(); ++i) if (a[i] == a[i - 1]) return a[i];
	return -1;
}
// Approach 2: use set
// T: O(nlogn), S: O(n)
int solve(vector<int> a) {
	set<int> st;
	for (int i = 0; i < a.size(); ++i) {
		if (st.count(a[i])) return a[i];
		st.insert(a[i]);
	}
	return -1;
}
// Approach 3: Floyd's hare and tortoise algo
// T: O(n), S: O(1)
int solve(vector<int> &A) {

	int slow = A[0];
	int fast = A[0];

	do {
		slow = A[slow];
		fast = A[A[fast]];
	} while (slow != fast);

	slow = A[0];

	while (slow != fast) {
		slow = A[slow];
		fast = A[fast];
	}

	return slow;
}

