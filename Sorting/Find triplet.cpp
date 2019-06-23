#include <iostream>
using namespace std;

//  find the triplets with a give sum  // 
// time complexity : O(n2)  //

bool find triplet(int A[], int sum){
	
	sort(A, A+n);
	
	for(int i=0; i<n-2; ++i){
		int l = i+1;
		int r = n-1;
		
		while(l<r){
			if(A[i]+A[l]+A[r] == sum) return true;
			else if(A[i]+A[l]+A[r] < sum)
				l++;
			else
				r--;
		}
	}
	return false;
}
