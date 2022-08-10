/* A non-empty zero-indexed array A consisting of N numbers is given.
 * The absolute distinct count of this array is the number of distinct absolute
 * values among the elements of the array.
 *
 * For example, consider the following array:
 *
 * [ -5, -3, -1, 0, 3, 6 ]
 *
 * The absolute distinct count of this array is 5, because there are 5 distinct absolute values
 * among the elements of this array, namely: 0, 1, 3, 5 and 6.
 *
 * Write a function, abs_distinct(), that, given an array, returns its absolute distinct count.
 *
 * Assume that the input array is sorted
 *
 * Source: Careercup
 */
#include <stdio.h>
#include <assert.h>

static unsigned abs_distinct_merge(int A[], size_t N, int idx_positive, int idx_negative, int last) {
	unsigned res = 0;
	while (idx_negative >= 0 && idx_positive < N) {
		int next;
		if (-A[idx_negative] < A[idx_positive]) {
			next = -A[idx_negative];
			idx_negative--;
		} else {
			next = A[idx_positive];
			idx_positive++;
		}
		if (next != last) {
			res++;
		}
		last = next;
	}

	while (idx_negative >= 0) {
		if (last != -A[idx_negative]) {
			res++;
		}
		last = -A[idx_negative];
		idx_negative--;
	}

	while (idx_positive < N) {
		if (last != A[idx_positive]) {
			res++;
		}
		last = A[idx_positive];
		idx_positive++;
	}

	return res;
}

unsigned abs_distinct(int A[], int N) {
	int right_neg;
	for (right_neg = N-1; right_neg >= 0 && A[right_neg] > 0; right_neg--)
		; /* Intentionally left blank */

	int idx_positive = right_neg+1;
	int idx_negative = right_neg;
	int last;

	if (idx_negative >= 0 && idx_positive < N) {
		if (-A[idx_negative] < A[idx_positive]) {
			last = -A[idx_negative];
			idx_negative--;
		} else {
			last = A[idx_positive];
			idx_positive++;
		}
	} else if (idx_negative >= 0) {
		last = -A[idx_negative];
		idx_negative--;
	} else if (idx_positive < N) { 
		last = A[idx_positive];
		idx_positive++;
	} else {
		assert(0);
	}

	return abs_distinct_merge(A, N, idx_positive, idx_negative, last)+1;
}

static int A[1024];
int main(void) {
	printf("Enter array size, followed by the elements. Array must be sorted.\n");
	printf("> ");

	size_t N;
	while (scanf("%zu", &N) == 1) {
		assert(N <= sizeof(A)/sizeof(A[0]));
		size_t i;
		for (i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		unsigned distcount = abs_distinct(A, N);
		printf("Absolute distinct count = %u\n", distcount);
		printf("> ");
	}

	return 0;
}
