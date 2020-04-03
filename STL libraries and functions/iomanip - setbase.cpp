// setbase example
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setbase

int main () {
  std::cout << std::setbase(16);
  std::cout << 110 << std::endl;
  return 0;
}

/*
Output:
6e
*/
