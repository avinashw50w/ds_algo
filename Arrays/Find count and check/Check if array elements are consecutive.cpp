/*Check if array elements are consecutive
Given an unsorted array of numbers, write a function that returns true if array consists of consecutive numbers.

Examples:
a) If array is {5, 2, 3, 1, 4}, then the function should return true because the array has consecutive numbers from 1 to 5.

b) If array is {83, 78, 80, 81, 79, 82}, then the function should
return true because the array has consecutive numbers from 78 to 83.

Method 1 (Use Sorting)
1) Sort all the elements.
2) Do a linear scan of the sorted array. If the difference between current element and next element is anything other than 1,
then return false. If all differences are 1, then return true.

Time Complexity: O(nLogn)

Method 2 (Use visited array)
The idea is to check for following two conditions. If following two conditions are true, then return true.
1) max – min + 1 = n where max is the maximum element in array,
	min is minimum element in array and n is the number of elements in array.
2) All elements are distinct.

To check if all elements are distinct, we can create a visited[] array of size n. We can map the ith element of
input array arr[] to visited array by using arr[i] – min as index in visited[].

Method 3 (Mark visited array elements as negative)
This method is O(n) time complexity and O(1) extra space, but it changes the
original array and it works only if all numbers are positive.
We can get the original array by adding an extra step though.
It is an extension of method 2 and it has the same two steps.
1) max – min + 1 = n where max is the maximum element in array,
	min is minimum element in array and n is the number of elements in array.
2) All elements are distinct.

In this method, the implementation of step 2 differs from method 2. Instead of creating a new array,
we modify the input array arr[] to keep track of visited elements. The idea is to traverse the array
and for each index i (where 0 <= i < n), make arr[arr[i] – min]] as a negative value.
If we see a negative value again then there is repetition.

NOTE: if array also contains -ve nos, then find the min in the array and add that min to
every element of the array so that all elements become +ve. And then proceed as follows

*/

bool solve(int a[], int N)
{
	if (N < 1) return false;

	int maxx = *max_element(a, a + N);
	int mini = *min_element(a, a + N);

	if (maxx - mini + 1 == N) {
		int j;
		bool zero = false;
		for (int i = 0; i < N; ++i) {

			int x = abs(a[i]) - mini;

			if (x == 0) {
				if (zero) return false;
				zero = true;
			}

			if (a[x] > 0) a[x] = -a[x];
			else return false;
		}
		return true;
	}

	return false;
}