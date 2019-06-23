/*For every element a[i] in array 'a', we need to find the largest element less than a[i](say leftLargest[i]) in 
left sub-array a[0 .. i-1] and largest element greater than a[i](say rightLargest[i]) in right sub-array a[i+1 .. lengthOfArray-1]. 
Once we have leftLargest[i] and rightLargest[i], we know that no increasing sequence of length 3 with a[i] as the 
second element in it would yield greater value for product than sequence leftLargest[i],a[i],rightLargest[i]. 
We compute this product leftLargest[i]*a[i]*rightLargest[i] for all elements in array 'a' and pick the maximum of these 
products to return the sequence which produces this maximum product.

Now let's see how can we compute leftLargest[i] and rightLargest[i] for all elements in array 'a'.
1. To compute leftLargest[i] for an element a[i], we make use of AVL tree to compute floor for each element. 
Floor of an element 'n' for a given array is the largest value in the given array which is less than element 'n'. 
After computing floor of an element a[i], a[i] is inserted into the AVL tree. If floor of a[i] is not found then 
leftLargest[i] is made 0. This step takes O(nlogn) time.

We have discussed how to calculate floor of an element in this post. Please note that floor definition here is slightly 
different than in the post because here we are looking for sequence which is strictly increasing. Checkout function 
getFloor() in the code snippet below which implements this functionality. 

2. To compute rightLargest[i] for an element a[i], we start traversing the array from rightmost end(from index arrayLength-1). 
While traversing the array, we keep track of the largest element seen so far(say 'rightLargestSofar') in sub-array a[i+1 .. (arrayLength-1)]. 
If the value 'rightLargestSofar' is greater than a[i] then rightLargest[i] is assigned a value 'rightLargestSofar' 
otherwise it's assigned the value as 0; also 'rightLargestSofar' is updated to a[i]. In this way, complete array rightLargest is computed. 
This step takes O(n) time. Checkout function fillRightGreatest(int[] array, int[] rightGreatest) for implementation details.
  
3. After computing leftLargest[i], rightLargest[i] for all a[i]'s , we pick the 
maximum of products leftLargest[i]*a[i]*rightLargest[i] to output the required sequence. 
This step takes O(n) time. Please checkout function - findSequence(int[] array, int[] sequenceIndices) for implementation details.*/


// leftLargset[i] - the largest no to the left of i which is smaller than a[i]
// rightLargest[i] - the largest no to the right of i which is greater than a[i]
int findSubSequence(int A[], int N) {

	int leftLargest[N], rightLargest[N];

	findLeftLargest(A, N, leftLargest);

	findRightLargest(A, N, rightLargest);

	REP(i, 0, N) {

		int p = leftLargest[i] * A[i] * rightLargest[i];

		if(p > maxProd) {
			maxProd = p;
			sequence[0] = leftLargest[i];
			sequence[1] = A[i];
			sequence[2] = rightLargest[i];
		}
	}
	return maxSum;
}


void findLeftLargest(int A[], int N, int leftLargest[]) {

	AVLTree tree = new AVLTree();

	REP(i, 0, N) {

		int floor = tree.getFloor(A[i]);

		leftLargest[i] = (floor == -1) ? 0 : floor;

		tree.insert(A[i]);
	}
}

void findRightLargest(int A[], int N, int rightLargest[]) {

	rightLargest[N-1] = 0;
	int maxRight = A[N-1];

	PER(i, N-2, 0) {

		if(A[i] > maxRight) {
			maxRight = A[i];
			rightLargest[i] = 0;
		}
		else
			rightLargest[i] = maxRight;
	}
}