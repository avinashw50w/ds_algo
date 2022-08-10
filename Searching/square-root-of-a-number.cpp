/*A Simple Solution to find floor of square root is to try all numbers starting from 1. For every tried number i,
if i*i is smaller than x, then increment i. We stop when i*i becomes more than or equal to x. */

// Returns floor of square root of x
int floorSqrt(int x)
{
  // Base cases
  if (x == 0 || x == 1)
    return x;

  // Staring from 1, try all numbers until
  // i*i is greater than or equal to x.
  int i = 1, result = 1;
  while (result <= x)
  {
    i++;
    result = i * i;
  }
  return i - 1;
}

///////////////////////////////////////////////////////////////////////
// efficient one : use binary search //

int floorSqrt(int x) {

  if (x <= 1)
    return x;

  long long start = 1, end = x, ans = 1, mid;
  while (start <= end) {

    mid = (start + end) >> 1;

    if (mid * mid <= x) {
      start = mid + 1;
      ans = mid;
    }
    else // If mid*mid is greater than x
      end = mid - 1;
  }
  return (int) ans;
}
////////////////////////////////////////////////////////////////////////////

string root(int N, double e) {
  bool neg = false;

  if (N < 0) {
    N = -N;
    neg = true;
  }

  double l = 0, r = N;
  double prev_mid = 0, mid = (l + r) / 2.0;
  double diff = abs(mid - prev_mid);

  while (mid * mid != N and diff > e) {

    if (mid * mid > N) r = mid;

    else l = mid;

    prev_mid = mid;
    mid = (l + r) / 2.0;

    diff = abs(mid - prev_mid);
  }

  return (neg) ? to_string(mid) + "i" : to_string(mid);
}


//////////////////////////////////////////////////////////////////////////

/*Babylonian method for square root
Algorithm:
This method can be derived from (but predates) Newton–Raphson method.


1 Start with an arbitrary positive start value x (the closer to the
   root, the better).
2 Initialize y = 1.
3. Do following until desired approximation is achieved.
  a) Get the next approximation for root using average of x and y
  b) Set y = n/x
Implementation:

/*Returns the square root of n. Note that the function */
float squareRoot(float n)
{
  /*We are using n itself as initial approximation
   This can definitely be improved */
  float x = n;
  float y = 1;
  /* e decides the accuracy level, eg,
  if asked for correction upto 2 decimal digits, then e = 0.001 */
  float e = 0.000001;
  while (x - y > e)
  {
    x = (x + y) / 2;
    y = n / x;
  }
  return x;
}

/*Example:

n = 4 // n itself is used for initial approximation
Initialize x = 4, y = 1
Next Approximation x = (x + y)/2 (= 2.500000),
y = n/x  (=1.600000)
Next Approximation x = 2.050000,
y = 1.951220
Next Approximation x = 2.000610,
y = 1.999390
Next Approximation x = 2.000000,
y = 2.000000
Terminate as (x - y) > e now.
If we are sure that n is a perfect square, then we can use following method. The method can go in
infinite loop for non-perfect-square numbers. For example, for 3 the below while loop will never terminate.

/*Returns the square root of n. Note that the function
  will not work for numbers which are not perfect squares*/
unsigned int squareRoot(int n)
{
  int x = n;
  int y = 1;
  while (x > y)
  {
    x = (x + y) / 2;
    y = n / x;
  }
  return x;
}

