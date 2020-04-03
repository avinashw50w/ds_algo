/*Given an array of N elements, find the sum of product of all the possible subsets on the array.

eg. arr[] = {1,2,3}, then subsets are: 1,2,3,{1,2},{2,3},{1,3},{1,2,3}
the req ans will be K = 1 + 2 + 3 + (1*2) + (2*3) + (1*3) + (1*2*3) */

/*explanation: 
no. of elements: 	req ans
	1 say a 		a
	2 say a,b 		a+b+ab = a*(b+1) + b
	3 say a,b,c 	a+b+c+ab+bc+ca+abc = (a+b+ab)*(c+1) + c = (a*(b+1) + b)*(c+1) + c

	so it follows a pattern: sum = previous_sum * (curr_number + 1) + curr_number
*/


#include <iostream>
using namespace std;

int main() {
	int A[] = {1,2,3};
	int N = sizeof(A)/sizeof(A[0]);
	int sum = 0;

	for(int i = 0; i < N; ++i) sum = sum*(A[i]+1) + A[i];

	cout << sum << endl;
}