#include <iostream>
using namespace std;

void TOH(int n, char from, char to, char interm){
	if(n>=1){											// if only one block then just move it to the destination
		TOH(n-1, from, interm, to);						// move all except the bottomost block to the intermediate pole
		printf("move disk no %d from %c to %c\n", n, from, to); // move the bottommost block to the destination pole
		TOH(n-1, interm, to, from);						// again move the blocks at the intermediate pole to the destination pole
	}
}

int main(){
	TOH(3,'A','C','B');
}