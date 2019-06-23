#include <bits/stdc++.h>
using namespace std;

int main() {
	int *ptr; 
	for(int i=0;i<10;++i)
		*(ptr+i) = i;

	cout << *ptr << " " << ptr << endl;
	cout << *ptr++ << " "<< ptr << endl;
	cout << *ptr << " " << ptr << endl;
	cout << ++*ptr << " " << ptr << endl;
	cout << *ptr << " " << ptr << endl;
	cout << *++ptr << " " << ptr << endl; 
	cout << *ptr << " " << ptr << endl;
}
 
/* evaluated from right to left

*ptr++ = *(ptr++)  ,ie, if ptr = x then ptr++ = x++  and *(ptr++) = value at address x
++*ptr = ++(*ptr)  ,ie, if *ptr = 2 , then ++(*ptr) = 3 

*/