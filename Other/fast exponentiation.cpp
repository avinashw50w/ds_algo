int expo(int a, int b){
  int result = 1;

  while (b){
    if (b&1)
      result *= a;

    b >>=1 ;
    a *= a;
  }

  return result;
}
