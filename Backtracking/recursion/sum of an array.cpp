#include <iostream>
using namespace std;
int sz;

int sum(int *A,int n){
	if(n==0) return 0;
	else return A[n-1] + sum(A,n-1); // s = last element + sum of the remaining elements
}

int sum2(int *A,int n) {
	int s = 0;
	if(n==sz) return s;
	s = A[n] + sum2(A,n+1); // s = first element + sum of the remaining elements
}
int main(){
	int A[] = {1,2,3,4,5,6,7,8,9};
	sz = sizeof(A)/sizeof(A[0]);

	cout << sum(A,sz) << endl;
	cout << sum2(A,0) << endl;
}