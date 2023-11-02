#include <bits/stdc++.h>
using namespace std;
// method 1 
/*Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]*/

int* rotate(int *a, int k, int n) {
	k %= n;
	int *tmp = new int[k];

	for(int i = 0; i < k; ++i) tmp[i] = a[i];

	int i;
	for(i = 0; i < n-k; ++i)
		a[i] = a[i+k];

	int k = 0;
	while(i<n) a[i++] = tmp[k++];

	return a;
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8};

	int *a = rotate(a, 3, 8);

	for(int i = 0; i < 8; ++i) cout << a[i] <<" ";
}

//////////////////////////////////////////////////////
// Method 2: rotate one by one //
// Time : O(n*k)  ,  space : O(1) //

void rotateByOne(int *a, int n) {
	int tmp = a[0];
	for(int i = 0; i < n-1; ++i)
		a[i] = a[i+1];
	a[n-1] = tmp;
}

void rotate(int *a, int k, int n) {
	for(int i = 0; i < k; ++i)
		rotatebyOne(a, n);
}

///////////////////////////////////////////////////

/*METHOD 3 (A Juggling Algorithm)
This is an extension of method 2. Instead of moving one by one, divide the array in different sets
where number of sets is equal to GCD of n and d and move the elements within sets.
If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, 
we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place.

Here is an example for n =12 and d = 3. GCD is 3 and

Let arr[] be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

a) arr[] after this step --> {4 2 3 7 5 6 10 8 9 1 11 12}

b)	Then in second set.
          arr[] after this step --> {4 5 3 7 8 6 10 11 9 1 2 12}

c)	Finally in third set.
          arr[] after this step --> {4 5 6 7 8 9 10 11 12 1 2 3}
*/

void leftRotate(int *a, int k, int n) {

	int i, j, k, tmp;

	for(int i = 0; i < __gcd(n ,k); ++i) {
		
		tmp = a[i];
		j = i;

		while(1) {

			k = (j+d) % n;

			if(k == i) break;

			a[j] = a[k];

			j = k;
		}
		a[j] = tmp;
	}
}

/*Time complexity: O(n)
Auxiliary Space: O(1)  

time : the outer loop runs not more than k times, because gcd(n, k) is always smaller than the smallest of n and k.
the inner while loop will run atmost n/k times.
So the overall runtime is k * n/k = n */
//////////////////////////////////////////////////////////////////////
/*Method 4(The Reversal Algorithm)
Please read this for first three methods of array rotation.

Algorithm:

rotate(arr[], d, n)
  reverse(arr[], 1, d) ;
  reverse(arr[], d + 1, n);
  reverse(arr[], l, n);
Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1]. The idea of the algorithm is:
Reverse A to get ArB. // Ar is reverse of A 
Reverse B to get ArBr. // Br is reverse of B 
Reverse all to get (ArBr) r = BA.

For arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7
A = [1, 2] and B = [3, 4, 5, 6, 7]
Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]  
A` is the reverse of A
LR -> L`R` -> RL
Time Complexity: O(n)*/

void rotate(int *a, int l, int r) {
	while(l < r) {
		swap(a[l], a[r]);
		++l;
		--r;
	}
}

void leftRotate(int *a, int d, int n) {
	rotate(a, 0, d-1);
	rotate(a, d, n-1);
	rotate(a, 0, n-1);
}



