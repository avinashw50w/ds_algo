#include <iostream>
using namespace std;

float printAvg(float prev_avg, int x, int n) {
	return (prev_avg*n + x)/(n+1);
}

int main(){
	int x, i = 0;
    float prev_avg = 0;
	while(cin>>x) {
        prev_avg = printAvg(prev_avg, x, i++);
        cout << prev_avg;
    }
}