/*Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer. */

int Solution::reverse(int A) {
    bool neg = false;
    if(A < 0) {
        A = -A;
        neg = true;
    }

   long long res = 0;
   while(A) {
       res = res*10 + A%10;
       A /= 10;
   }
   if(res > INT_MAX) return 0;
   return (neg) ? (int)res*(-1) : (int)res;
}
