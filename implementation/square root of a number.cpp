// N is the number and e is the required precision 
// in case of -ve numbers like -16 return 4i

string root(int N, double e) {
  bool neg = false;
  
  if(N < 0) {
    N = -N;
    neg = true;
  }
  
  double l = 0, r = N;
  double prev_mid = 0, mid = (l +r)/2.0;
  double diff = abs(mid - prev_mid);
  
  while(mid*mid != N and diff > e) {
    
    if(mid*mid > N) r = mid;
    
    else l = mid;
    
    prev_mid = mid;
    mid = (l+r)/2.0;
    
    diff = abs(mid - prev_mid);
  } 
  
  return (neg)? to_string(mid)+"i" : to_string(mid);
}
