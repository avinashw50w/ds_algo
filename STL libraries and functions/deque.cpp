#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){
	deque<int> Qi;
	
	vector<int> vec (2,8);
	
	Qi.push_back(1);
	Qi.push_back(2);
	Qi.push_back(3);
	Qi.push_back(4);
	
	cout<<Qi.front();
	
	deque<int>::iterator i;
	i=Qi.begin();
	Qi.insert(i,10);
//	i++;
	Qi.insert(i,20);
	Qi.insert(i,2,6);
	
	Qi.insert(i,vec.begin(),vec.end());
	
	
	for(i=Qi.begin();i!=Qi.end();i++)
	cout<<" "<<*i;
	return 0;
}
