#include <iostream>

template <typename T>
void foo(T &&arg)
{
  if constexpr(std::is_lvalue_reference_v<T>)
  {
    std::cout << arg << " is lvalue reference\n";
  }
  else
  {
    std::cout << arg << " is NOT lvalue reference\n";
  }
}

int main()
{
  int v = 5;
  const int c = 6;

  foo(v);
  foo(c);
  foo(7);
  foo(std::move(v));
  foo(std::move(c));
}
