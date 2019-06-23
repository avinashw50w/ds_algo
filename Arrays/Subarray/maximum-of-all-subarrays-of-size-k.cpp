
void func(int a[], int n, int k) 
{
	deque<int> q(k);

	int i;

	for (i = 0; i < k; ++i) 
	{
		while(!q.empty() and a[q.back()] <= a[i]) q.pop_back();
		q.push_back(i);
	}

	for ( ; i < n; ++i) 
	{
		cout << a[q.front()];

		while(!q.empty() and i - q.front() >= k) q.pop_front();

		while(!q.empty() and a[q.back()] <= a[i]) q.pop_back();

		q.push_back(i);
	}

	cout << a[q.front()];
}

// time 		   : O(n)
// auxiliary space : O(k)
/////////////////////////////////////////////////////////////////////
/*Optimized approach: In this approach, we make use of AVL trees (self-balanced Binary Search Tree) as explained in the  following algorithm. 
We will be referring to AVL tree as a BST in below steps because it would make understanding the intuition of the algorithm easier.
1. Create a BST from first 'k' elements of the input array.
2. Find node with maximum value from the BST created in step #1. Print this node's value. 
This would represent an element with maximum value from first sub-array of size 'k'.
3. Now starting from i = 0 upto i = n-k-1
    a. Search and delete element with value array[i] from the BST.
    b. Insert node with value as array[i+k] into the BST. Now this BST represents next sub-array of size 'k'.
    c. Find node with maximum value from the BST. Print this node's value.

Handling duplicates: Note that this optimized approach which uses BST won't be able to handle the case when input array 
has more than one elements with same value. We can handle this case easily by pre-processing the input array such that 
whenever there are duplicates, their values are modified by adding different decimal offsets. For example, 
if the given input array is {2,3,6,5,6,5} then it could be modified to {2,3,6.01,5.01,6.02,5.02}. 
Now this modified input does not have any duplicates and above algorithm should work. Care has to taken to 
remove the decimal part while printing the value of maximum element in a sub-array.

In the above algorithm, creating BST takes O(logk) time. Search and delete operation, insert operation and finding 
maximum valued node operation, each of these operations takes O(logk) time and we need to perform each of these 
operations 'n-k' times. Therefore, overall time complexity of this algorithm is O(nlogk). Extra space taken in the form of BST is O(k).
You can check out function 'printMaxfromEachSubarray(int[] array, int k)' in the following code snippet for implementation details.*/

void fun(int A[], int N, int K) {
	multiset<int> s;
	
	REP(i, 0, K) s.insert(A[i]);
	
	REP(i, K, N) {
		
		cout << *s.rbegin() <<" ";
		
		s.erase(s.find(A[i-K]));
		
		s.insert(A[i]);
	}
	
	cout << *s.rbegin() << endl;
}

////////////////////////////////////////////////////////////////
// another method //
/*Algorithm:

N is number of elements in an array and W is window size. So, Window number = N-W+1
Now divide array into blocks of W starting from index 1.
We have divided into blocks because we will calculate maximum in 2 ways 
A.) by traversing from left to right B.) by traversing from right to left. but how ??
Firstly, Traversing from Left to Right. For each element ai in block we will find maximum 
till that element ai starting from START of Block to END of that block.
Secondly, Traversing from Right to Left. For each element 'ai' in block we will find 
maximum till that element 'ai' starting from END of Block to START of that block.
Now we have to find maximum for each subarray or window of size 'W'. So, starting from index = 1 to index = N-W+1 .

max_val[index] = max(RL[index], LR[index+w-1]);*/
#define LIM 100001 

using namespace std;

int arr[LIM]; // Input Array
int LR[LIM]; // maximum from Left to Right
int RL[LIM]; // maximum from Right to left
int max_val[LIM]; // number of subarrays(windows) will be n-k+1

int main(){
    int n, w, i, k; // 'n' is number of elements in array
                    // 'w' is Window's Size 
    cin >> n >> w;

    k = n - w + 1; // 'K' is number of Windows

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    for(i = 1; i <= n; i++){ // for maximum Left to Right
        if(i % w == 1) // that means START of a block
            LR[i] = arr[i];
        else
            LR[i] = max(LR[i - 1], arr[i]);        
    }

    for(i = n; i >= 1; i--){ // for maximum Right to Left
        if(i == n) // Maybe the last block is not of size 'W'. 
            RL[i] = arr[i]; 
        else if(i % w == 0) // that means END of a block
            RL[i] = arr[i];
        else
            RL[i] = max(RL[i+1], arr[i]);
    }

    for(i = 1; i <= k; i++)    // maximum
        max_val[i] = max(RL[i], LR[i + w - 1]);

    for(i = 1; i <= k ; i++)
        cout << max_val[i] << " ";

    cout << endl;

    return 0;
}
