#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
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
    std::cout << "l_" << i << "(x) = " << prodRes << '\n';
    sumRes+=prodRes*fa[i];
  }
  return sumRes;
}
int main(int argc, char const *argv[])
{
  int n;
  double unos;
  polinom<double> X,Y,Z,Zderiv;
  std::cout << "Unesite duzinu niza X\n";
  std::cin >> n;
  std::cout << "Unesite niz X u formatu [x0,x1,x2,x3,...,xn]\n";
  std::cin >> X;
  std::cout << "Unesite niz Y u formatu [y0,x1,x2,x3,...,xn]\n";
  std::cin >> Y;
  Z = Lagranz(n,X,Y);
  std::cout << "Lagranz od [X,Y]\n" << Z << "\n";
  Zderiv = Z.Deriv();
  std::cout << Zderiv << "\n";
  while(std::cin >> unos)
    std::cout << std::fixed << std::setprecision(6) <<  Z.eval(unos) << " " << Zderiv.eval(unos) << "\n";
  return 0;
}
