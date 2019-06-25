#include<iostream>
#include<iomanip>
#include<algorithm>
#include"polinom.h"
#include"interpolacija.h"
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
