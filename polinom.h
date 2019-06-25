#ifndef HEADER_HAS_BEEN_INCLUDED
#define HEADER_HAS_BEEN_INCLUDED
#include <vector>
#include <string>
#include <sstream>
template <class Type>
class polinom
{
private:
  std::vector<Type> koef; // prvi element uz x0
public:
  polinom() {}
  polinom(const std::vector<Type>& koef)
  {
    this->koef = koef;
  }
  polinom (const std::string& x);
  int getSize() const
  {
    return koef.size();
  }
  const Type& operator[](int i) const
  {
    return koef[i];
  }
  Type& operator[](int i)
  {
    return koef[i];
  }
  void push_back(const Type& br)
  {
    koef.push_back(br);
  }
  void pop_back()
  {
    koef.pop_back();
  }
  void clear()
  {
    koef.clear();
  }
  polinom& operator+=(const polinom& a)
  {
    int i=0;
    int minSize = std::min(this->getSize(),a.getSize());
    for(;i<minSize;i++)
    {
      this->operator[](i)+=a[i];
    }
    while(i<a.getSize())
    {
      this->push_back(a[i]);
      ++i;
    }
    return *this;
  }
  polinom& operator-=(const polinom& a)
  {
    int i=0;
    int minSize = std::min(this->getSize(),a.getSize());
    for(;i<minSize;i++)
    {
      this->operator[](i)-=a[i];
    }
    while(i<a.getSize())
    {
      this->push_back(a[i]);
      ++i;
    }
    return *this;
  }
  polinom& operator-=(const Type& br)
  {
    for (int i = 0; i < this->getSize(); i++)
    {
      this->operator[](i)-=br;
    }
  }
  polinom& operator+=(const Type& br)
  {
    for (int i = 0; i < this->getSize(); i++)
    {
      this->operator[](i)+=br;
    }
  }
  polinom& operator*=(const Type& br)
  {
    for (int i = 0; i < this->getSize(); i++)
    {
      this->operator[](i)*=br;
    }
    return *this;
  }
  polinom& operator*=(const polinom& a)
  {
    int lengthOfPoly = this->getSize() + a.getSize()-1;
    std::vector<Type> vule(lengthOfPoly);
    polinom temp(vule);
    temp.getSize();
    for(int i = 0; i < this->getSize(); i++)
    {
      for (int j = 0; j < a.getSize(); j++)
      {
        temp[i+j] += this->operator[](i)*a[j];
      }
    }
    *this = temp;
    return *this;
  }
  Type eval(Type x)
  {
    Type rez = 0;
    Type pol = 1;
    for(int i=0;i<koef.size();i++)
    {
      rez+=koef[i]*pol;
      pol*=x;
    }
    return rez;
  }
  polinom nthDeriv(int n)
  {
    polinom rez;
    if(n>koef.size())
      return polinom(std::vector<Type>(1));
    // TODO: Implement directly instead of calling Deriv n times
    else
    {
      for(int i=0;i<n;i++)
        rez = this->Deriv();
    }
  }
  polinom Deriv()
  {
    polinom rez(*this);
    for(int i=0;i<koef.size()-1;i++)
    {
      rez[i] = rez[i+1]*(i+1);
    }
    rez.pop_back();
    return rez;
  }
  //friend polinom operator+(polinom a,const polinom& b);
  //virtual ~polinom ();
};
template <class Type>
polinom<Type> operator+(polinom<Type> a,const polinom<Type>& b)
{
  a+=b;
  return a;
}
template <class Type>
polinom<Type> operator-(polinom<Type> a,const polinom<Type>& b)
{
  a-=b;
  return a;
}
template <class Type>
polinom<Type> operator*(polinom<Type> a,const polinom<Type>& b)
{
  a*=b;
  return a;
}
template <class Type>
polinom<Type> operator*(polinom<Type> a,const Type& b)
{
  a*=b;
  return a;
}
template <class Type>
polinom<Type> operator*(const Type& b,polinom<Type> a)
{
  a*=b;
  return a;
}
template <class Type>
polinom<Type> operator+(polinom<Type> a,const Type& b)
{
  a+=b;
  return a;
}
template <class Type>
polinom<Type> operator+(const Type& b,polinom<Type> a)
{
  a+=b;
  return a;
}
template <class Type>
polinom<Type> operator-(polinom<Type> a,const Type& b)
{
  a-=b;
  return a;
}
template <class Type>
polinom<Type> operator-(const Type& b,polinom<Type> a)
{
  a-=b;
  return a;
}
template <class Type>
polinom<Type>::polinom(const std::string& x) // string tipa [1,2,3,4]
{
  std::stringstream parser(x);
  Type inputNum;
  char tempC;
  /*if(x[0]!='[' || x[x.length()-1]!=']')
  {
    return polinom(std::vector<int>(1));
  }*/
  this->clear();
  while(parser >> tempC >> inputNum)
  {
    this->push_back(inputNum);
  }
  std::reverse(koef.begin(),koef.end());
}
template <class Type>
std::ostream& operator<<(std::ostream& os, const polinom<Type>& obj)
{
  // write obj to stream
  for(int i=obj.getSize()-1;i>=1;i--)
  {
    if(obj[i]==0)
      continue;
    if(obj[i]!=1)
      os << obj[i] << "x^" << i << "+";
    else
      os << "x^" << i << "+";
  }
  os << obj[0];
  return os;
}
template <class Type>
std::istream& operator>>(std::istream& is, polinom<Type>& obj)
{
  // read obj from stream
  std::string x;
  is >> x;
  obj = polinom<Type>(x);
  //if( /* no valid object of T found in stream */ ) TODO
  //  is.setstate(std::ios::failbit);

  return is;
}
#endif
