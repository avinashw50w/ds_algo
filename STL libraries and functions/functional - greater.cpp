/*
template <class T> struct greater : binary_function <T,T,bool> {
  bool operator() (const T& x, const T& y) const {return x>y;}
};
*/

// greater example
#include <iostream>     // std::cout
#include <functional>   // std::greater
#include <algorithm>    // std::sort

int main () {
  int numbers[]={20,40,50,10,30};
  std::sort (numbers, numbers+5, std::greater<int>());
  for (int i=0; i<5; i++)
    std::cout << numbers[i] << ' ';
  std::cout << '\n';
  return 0;
}

/*
Output:

50 40 30 20 10
*/

