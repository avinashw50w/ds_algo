/*The idea is to use Bitwise OR. A bitwise OR takes two bits and returns 0 if both bits are 0, while otherwise the result is 1. So it has 75% probability that it will return 1.

Below is C++ implementation of above idea – */
// Program to print 1 with 75% probability and 0
// with 25% probability
#include <iostream>
using namespace std;
 
// Random Function to that returns 0 or 1 with
// equal probability
int rand50()
{
    // rand() function will generate odd or even
    // number with equal probability. If rand()
    // generates odd number, the function will
    // return 1 else it will return 0.
    return rand() & 1;
}
 
// Random Function to that returns 1 with 75%
// probability and 0 with 25% probability using
// Bitwise OR
bool rand75()
{
    return rand50() | rand50();
}
 
// Driver code to test above functions
int main()
{
    // Intialize random number generator
    srand(time(NULL));
 
    for(int i = 0; i < 50; i++)
        cout << rand75();
 
    return 0;
}

/*
Output:

11101111110010010110011111111101111110111100011000
*/