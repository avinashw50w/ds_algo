#include <iostream>
#include <cmath>
using namespace std;

int flipBits(int n, int k) {
    int mask = 1;
    mask = (1<<k) - 1;

    return ~n & mask;
}

int main() {

	int n = 5;

	cout << flipBits(n, ceil(log(n)));
}
