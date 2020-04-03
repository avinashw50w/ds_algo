#include <iostream>
#include <cmath>

using namespace std;

int check(int N) { 
	return (N & (N-1)) == 0;
}
int main() {
	
	int N = 32;
	
	cout << check(N);
}
