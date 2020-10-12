/* check if a number can be expressed as x^y where x > 0 and y > 1 */

/* a = x^y
   log(a) = log(x^y)
   y = log(a)/log(x)
   => log(a)/log(x) > 1
   => log(a) > log(x)

   so if x > √a, then log(x) > 1/2log(a)
   log(a) > 1/2log(a)
   => 2 > 1 (contradiction)
   so x should be less than √a
*/

bool check(int a) {
    if (a == 1) return true;
    if (a <= 3) return false;

    for (int i = 2; i * i <= a; ++i) {
        float x = log(a) / log(i);
        if (x == floor(x)) return true;
    }
    return false;
}