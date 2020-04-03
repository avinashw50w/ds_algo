/* check if a number can be expressed as x^y where x > 0 and y > 1 */

/* a = x^y
   log(a) = log(x^y)
   y = log(a)/log(x) 
*/

bool check(int a) {
	if (a == 1) return true;
	if (a <= 3) return false;

	for (int i = 2; i*i <= a; ++i) {
		float x = log(a)/log(i);
		if(x == floor(x)) return true;
	}
	return false;
}