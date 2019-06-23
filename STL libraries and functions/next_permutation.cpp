// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
/*
Edit & Run


Output:
The 3! possible permutations with 3 elements:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
After loop: 1 2 3
*/

/* Parameters
first, last
Bidirectional iterators to the initial and final positions of the sequence. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
BidirectionalIterator shall point to a type for which swap is properly defined.
comp
Binary function that accepts two arguments of the type pointed by BidirectionalIterator, and returns a value convertible to bool. The value returned indicates whether the first argument is considered to go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.

Return value
true if the function could rearrange the object as a lexicographicaly greater permutation.
Otherwise, the function returns false to indicate that the arrangement is not greater than the previous, but the lowest possible (sorted in ascending order).
*/

