// unique algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> myvector (myints,myints+9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10

  // using predicate comparison:
  std::unique (myvector.begin(), myvector.end(), myfunction);   // (no changes)

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}


Output:
myvector contains: 10 20 30 20 10

/* Parameters
first, last
Forward iterators to the initial and final positions of the sequence of move-assignable elements. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
pred
Binary function that accepts two elements in the range as argument, and returns a value convertible to bool. The value returned indicates whether both arguments are considered equivalent (if true, they are equivalent and one of them is removed).
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.

Return value
An iterator to the element that follows the last element not removed.
The range between first and this iterator includes all the elements in the sequence that were not considered duplicates.
*/
