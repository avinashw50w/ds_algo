/*Check if an array can be Arranged in Left or Right Positioned Array
Given an array arr[] of size n>4, the task is to check whether the given array can be arranged in the form of Left or Right positioned array?
Left or Right Positioned Array means each element in the array is equal to the number of elements to its left or number of elements to its right.

Examples:

Input  : arr[] = {1, 3, 3, 2}
Output : "YES"
This array has one such arrangement {3, 1, 2, 3}.
In this arrangement, first element '3' indicates
that three numbers are after it, the 2nd element
'1' indicates that one number is before it, the
3rd element '2' indicates that two elements are
before it.
An efficient solution for this problem needs little bit observation and pen-paper work.
To satisfy the Left or Right Positioned Array condition all the numbers in the array should either be equal to index, i or (n-1-i)
and arr[i] < n. So we create an visited[] array of size n and initialize its element with 0. Then we traverse array and follow given steps :

If visited[arr[i]] = 0 then make it 1, which checks for the condition that number of elements on the left side of array arr[0]…arr[i-1] is equal to arr[i].
Else make visited[n-arr[i]-1] = 1, which checks for the condition that number of elements on the right side of array arr[i+1]…arr[n-1] is equal to arr[i].
Now traverse visited[] array and if all the elements of visited[] array become 1 that means arrangement is possible “YES” else “NO”.
*/

bool leftOrRight(int a[], int n) {

	bool vis[n] = {};

	for (int i = 0; i < n; ++i) {
		if (a[i] < n) {
			if (!vis[a[i]]) vis[a[i]] = 1;
			else vis[n - a[i] - 1] = 1;
		}
	}

	for (int i = 0; i < n; ++i)
		if (!vis[i]) return false;

	return true;
}