#include <bits/stdc++.h>
using namespace std;

/* Restrictions : it can only work with following parameters
	unsigned long long
	long double
	char const*
	char const*, std::size_t
	wchar_t const*, std::size_t
	char16_t const*, std::size_t
	char32_t const*, std::size_t

// return value can be of any type

*/

float operator"" _m(long double x) { return x * 1000; }
float operator"" _cm(long double x) { return x * 10; }
float operator"" _mm(long double x) { return x; }

int main() {
	
	cout << 4.0_m + 3.2_cm + 1.0_mm <<endl;

}
