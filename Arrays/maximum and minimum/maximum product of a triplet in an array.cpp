/*Approach 4: O(n) Time, O(1) Space

Scan the array and compute Maximum, second maximum and third maximum element present in the array.
Scan the array and compute Minimum and second minimum element present in the array.
Return the maximum of product of Maximum, second maximum and third maximum and product of Minimum,
second minimum and Maximum element.*/

int maxProduct(int A[], int N) {

	if (N < 3) return -1;

	int maxA, maxB, maxC;
	int minA, minB;

	maxA = maxB = maxC = INT_MIN;
	minA = minB = INT_MAX;

	for (int i = 0; i < N; ++i)
	{
		if (A[i] > maxA) {
			maxC = maxB;
			maxB = maxA;
			maxA = a[i];
		}
		else if (maxB < A[i] and A[i] < maxA) {
			maxC = maxB;
			maxB = A[i];
		}
		else if (maxC < A[i] and A[i] < maxB) {
			maxC = A[i];
		}

		if (A[i] < minA) {
			minB = minA;
			minA = A[i];
		}
		else if (minA < A[i] and A[i] < minB) {
			minB = A[i];
		}
	}

	return max(maxA * maxB * maxC, maxA * minA * minB);
}

