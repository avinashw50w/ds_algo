#include <iostream>
#include <cstring>
using namespace std;
 // NOTE : Fenwick can be 0-based! Change i += i&-i to i |= i+1 and change i -= i&-i to i = (i&(i+1))-1
template<class T>
class BIT
{
      T *tree;
      int maxVal;
      public:
      BIT(int N)
      {
              tree = new T[N+1];
              memset(tree,0,sizeof(T)*(N+1));
              maxVal = N;
      }
      // add val to the number at position idx
      void update(int idx, T val)
      {
           while (idx <= maxVal)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }
      //Returns the sum in the range [1..idx]
      T getSum(int idx)                 
      {
        T sum=0;
        while (idx>0)
        {
              sum += tree[idx];
              idx -= (idx & -idx);
        }
        return sum;
      }
	// returns sum in the range [a...b] inclusive
      T query(int a,int b){ return getSum(b) - getSum(a-1);}
};
 
int main()
{
    //Initialize the size by the
    //maximum value the tree can have
    BIT<int> B(10);
          int a[]={1,2,3,4,5,6,7,8};
          for(int i=0;i<8;++i)
            B.update(i+1,a[i]);
          cout<<B.query(2,3);
          

 
}

//Remember you should never query or update on the 0th element. that gives an error because your elements are a1 , a2 , ....a[n] so be careful with that.
