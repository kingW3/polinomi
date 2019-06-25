#include <string>
#include "polinom.h"
template <class Type>
polinom<Type> Lagranz(int n,polinom<Type> a, polinom<Type> fa)
{
  polinom<Type> sumRes("[0]");
  for(int i=0;i<n;i++)
  {
    polinom<Type> prodRes("[1]");
    for(int j=0;j<n;j++)
    {
      if(j==i)
        continue;
      polinom<Type> temp(std::string("[")+std::to_string(-a[j])+std::string(",1]"));
      temp*=(1/(a[i]-a[j]));
      prodRes*=temp;
    }
    //std::cout << "l_" << i << "(x) = " << prodRes << '\n';
    sumRes+=prodRes*fa[i];
  }
  return sumRes;
}

