#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cout<<"Enter size of array1 and array2 :";
	int size1,size2;
	cin>>size1>>size2;
	int arr1[size1],arr2[size2];
	for(int i=0;i<size1;i++)
	cin>>arr1[i];
	for(int i=0;i<size2;i++)
	cin>>arr2[i];
	
	sort(arr1,arr1+size1);
	sort(arr2,arr2+size2,greater<int>());
	for(int i=0;i<size1;i++)
	cout<<arr1[i]<<" ";
	cout<<"\n";
	for(int i=0;i<size2;i++)
	cout<<arr2[i]<<" ";
/*
comp
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.
*/	
	// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
}
