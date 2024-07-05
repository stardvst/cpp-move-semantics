#include <iostream>

template <typename T>
void foo(T &&arg)
{
  if constexpr(std::is_const_v<std::remove_reference_t<T>>)
  {
    std::cout << arg << " is const\n";
  }
  else
  {
    std::cout << arg << " is NOT const\n";
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
