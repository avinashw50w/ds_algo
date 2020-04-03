// O(logn)

ll modpow(ll base, ll expo,ll m){       
  ll result = 1;

  while (expo){
    if (expo&1)
      result = (result*base)%m;

    expo >>=1 ;
    base = (base*base)%m;
  }

  return result;
}

// recursive

ll modpow(ll base,ll expo,ll m){
	if(expo==0) return 1;           // if exponent is zero then return  1
	ll x = modpow(base,expo/2,m);                    //  if expo is even then return  (x^n/2)*(x^n/2)
	x = (x*x)%m;
	if(expo&1) x = (base*x)%m;
	return x;
}
