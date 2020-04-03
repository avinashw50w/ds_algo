#include<bits/stdc++.h>
using namespace std;
inline bool search(vector<int> Hash[],int val){
	int Hindex = val%11;
	int l=0,r=Hash[Hindex].size()-1;	
	while(l<=r){
		int mid = (l+r)/2;
		if(val==Hash[Hindex][mid]) return true;
		else if(val<Hash[Hindex][mid]) r = mid-1;
		else l = mid+1;
	}
	return false;
}
void insert(vector<int> Hash[],int val){
	int Hindex = val%11;
	Hash[Hindex].push_back(val);
}
bool query(vector<int>Hash[],int val){
	
	if(search(Hash,val)) return true;
	else return false;
}
int main(){
	vector<int> Hash[11];
	for(int i=0;i<20;i++)
	insert(Hash,i);
	
	cout<<query(Hash,5);
	return 0;
}
