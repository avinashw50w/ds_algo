#include <iostream>
using namespace std;
int sz;
/*===========================*/
void print(int* A,int n){
	if(n==0) return;
	printf("%d ",A[sz-n]);   // print first element
	print(A,n-1);            // then print the remaining elements
}
/*=====================================*/
/*======for reverse order==============*/
void printrev(int* A,int n){
	if(n==0) return;
	printf("%d ",A[n-1]);
	printrev(A,n-1);
}
/*======================================*/
/*====do both using a single recursion====*/
void printboth(int* A,int n){
	if(n==0) return;
	printf("%d ",A[sz-n]);
	printboth(A,n-1);
	printf("%d ",A[sz-n]);
}
/*==========================================*/
int main(){
	int A[] = {1,2,3,4,5,6,7,8,9};
	sz = sizeof(A)/sizeof(A[0]);
	print(A,sz);
	cout<<endl;
	printrev(A,sz);
	cout<<endl;
	printboth(A,sz);
	cout<<endl;
}