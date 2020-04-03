// iota example          ;  keeps incrementing the base value by 1
#include <iostream>     // std::cout
#include <numeric>      // std::iota

int main () {
  int numbers[10];

  std::iota (numbers,numbers+10,100);

  std::cout << "numbers:";
  for (int& i:numbers) std::cout << ' ' << i;
  std::cout << '\n';

  return 0;
}

/*Output:

numbers: 100 101 102 103 104 105 106 107 108 109
*/
