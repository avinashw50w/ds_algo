/*Given a number line from -infinity to +infinity. You start at 0 and can go either to the left or to the right. 
The condition is that in ith move, you take i steps.*/
#include <iostream>
using namespace std;

int fun(int source,int dest,int steps){
	if(abs(source) > abs(dest)) return (1<<30);
	if(source==dest) return steps;
	// either move forward or move backwards
	int forward = fun(source+steps+1, dest, steps+1);

	int backword = fun(source-steps-1, dest, steps+1);

	return min(forward,backword);
}

int main(){
	cout << fun(0,9,0);
}
