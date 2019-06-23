// swap strings
#include <iostream>
#include <string>

main ()
{
  std::string buyer ("money");
  std::string seller ("goods");

  std::cout << "Before the swap, buyer has " << buyer;
  std::cout << " and seller has " << seller << '\n';

  seller.swap (buyer);

  std::cout << " After the swap, buyer has " << buyer;
  std::cout << " and seller has " << seller << '\n';

  return 0;
}
Edit & Run


Output:
Before the swap, buyer has money and seller has goods
 After the swap, buyer has goods and seller has money
