/* to find a^-1(mod m) . Lets take x = a^-1(mod m) , then ax = 1(mod m). So we have to find an integer x such that ax = 1(mod m)*/
// Note that a^-1(mod m) exists iff a and m are co-prime

// method 1 : using Euler's theorem : a^phi(m) = 1(mod m)    ==> a^(phi(m)-1) = a^-1(mod m)

// if mod is prime then mmi(a) = a^(mod-2) , else mmi(a) = a^(phi(m)-1)

ll modpow(ll base,ll expo,ll m){
	if(expo==0) return 1;           // if exponent is zero then return  1
	ll x = modpow(base,expo/2,m);                    //  if expo is even then return  (x^n/2)*(x^n/2)
	x = (x*x)%m;
	if(expo&1) x = (base*x)%m;
	return x;
}

int main(){
	
	cout << modpow(12, mod-2, mod) << endl;
	cout<< inv(12, mod) << endl;
}

/////////////////////////////////////////////////////////////////////////
// or simply //

long long inv(long long a, long long m) {
    long long res = 1;
    while (a > 1) {
        res = res * (m - m / a) % m;
        a = m % a;
    }
    return res;
}

////////////////////////////////////////////////////////////////////////
// by using extended euclid
/*lets take a linear diophantine equation ax + by = c, where c = gcd(a, b)
==> ax + my = gcd(a, m)
==> ax + my = 1     		, since a and m are co-prime, so gcd(a,m) = 1
==> ax + my = 1(mod m)  	, taking mod m on both sides
==> ax = 1(mod m)  			, because my(mod m) = 0  */

tuple<ll, ll> extGCD(ll a, ll b) {
	ll x, y;
	if(b == 0) return make_tuple(1, 0);
	
	tie(x, y) = extGCD(b, a%b);
	
	return make_tuple(y, x - (a/b)*y);
}

ll inv(ll a, ll m) {
	ll x, y;
	tie(x, y) = extGCD(a%m, m);
	
	return (x + m)%m; // m is added to handle -ve x
}




