// length of longest increasing subsequence in O(nlogn)
#include <iostream>
#include <set>
using namespace std;
/*=========================================================*/
void LIS(int a[],int n){
	multiset<int> st; multiset<int>::iterator it; st.clear();
	for(int i=0;i<n;i++){
		st.insert(a[i]); it = st.find(a[i]);
		it++; if(it != st.end()) st.erase(it);
	}
	cout << st.size();
}
/*==========================================================*/

int main() {
	int arr[] = {6, 5, 5, 7, 11, 8, 10, 13, 6};
	int n = sizeof arr/sizeof arr[0];
	LIS(arr,n);
}
