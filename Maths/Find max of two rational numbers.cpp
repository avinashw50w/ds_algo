/*find max of two rational numbers.
eg: 3/2 > 3/4

sol - find lcm of the denominators, then multiply both rational numbers by the lcm
*/

struct Rational {
	int nume, deno;
};

int lcm(int a, int b) {
	return (a*b) / __gcd(a,b);
}

Rational maxRational(Rational first, Rational second) {

	int k = lcm(first.deno, second.deno);

	int num1 = first.nume;
	int num2 = second.nume;

	num1 *= k / first.deno;
	num2 * k / second.deno;

	return (num1 > num2) ? first: second;
}

