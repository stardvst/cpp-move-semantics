#include <string>
#include <iostream>

struct C
{
  int o;

  // by declaring operator with &,
  // we make sure it can't be called for temporary objects
  C &operator=(const C &c) & = default;
};

C getC()
{
  return C{5};
}

int main()
{
  // getC() = C{3}; // won't compile
}
