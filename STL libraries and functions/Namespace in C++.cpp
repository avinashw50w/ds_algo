/*Namespace in C++ | Set 2 (Extending namespace and Unnamed namespace)

Different ways to access namespace

In C++, there are two ways of accessing namespace variables and functions.
Normal way*/
// C++ program to demonstrate accessing of variables
// in normal way, i.e., using "::"
#include <iostream>
using namespace std;
 
namespace geek
{
    int rel = 300; 
}
 
int main()
{
    // variable ‘rel’ accessed 
    // using scope resolution operator
    cout << geek::rel << "\n";  // prints 300
 
    return 0;
}
/*
Output :

300
“using” directive
// C++ program to demonstrate accessing of variables
// in normal way, i.e., using "using" directive*/
#include <iostream>
using namespace std;
 
namespace geek
{
    int rel = 300; 
}
 
// use of ‘using’ directive
using namespace geek;
 
int main()
{
   // variable ‘rel’ accessed 
   // without using scope resolution variable
   cout << rel << "\n";        //prints 300
   
   return 0;
}
/*
Output:

300
Using namespace in header files

We can create namespace in one file and access contents using another program. This is done in the following manner.
We need to create two files. One containing the namespace and all the data members and member functions we want to use later.
And the other program can directly call the first program to use all the data members and member functions in it.
File 1 */

// file1.cpp 
#include <iostream>
using namespace std;
 
namespace foo
{
    int value() 
    { 
       return 5;    
    }
}
/*
File 2*/

// file2.cpp - Not to be executed online
#include <iostream>
#include “program1.cpp” // Including file1
using namespace std;
 
int main () 
{
    cout << foo::value();
    return 0;
}
/*
Here we can see that the namespace is created in file1.cpp and the value() of that namespace is getting called in file2.cpp.

Nested Namespaces

In C++, namespaces can also be nested i.e., one namespace inside another. The resolution of namespace variables is hierarchical.*/
// C++ program to demonstrate nesting of namespaces
#include <iostream>
using namespace std;
 
// Nested namespace
namespace out
{
  int val = 5; 
  namespace in
  {
      int val2 = val;    
  }
}
 
// Driver code
int main()
{
  cout << out::in::val2;   // prints 5
  return 0;
}
/*
OUTPUT :

5
Namespace Aliasing

In C++, you can use an alias name for your namespace name, for ease of use. Existing namespaces can be aliased with new names, with the following syntax:
namespace new_name = current_name;  */
#include <iostream>
 
namespace name1 
{
    namespace name2 
    {
         namespace name3 
         {
             int var = 42;
         }
    }
}
 
// Aliasing 
namespace alias = name1::name2::name3;
  
int main()
{
    std::cout << alias::var << '\n';
}
Run on IDE
Output :

42