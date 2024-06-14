#include <iostream>
#include <type_traits>
#include <vector>

struct Base
{
  std::string s;
};

struct Throwing
{
  Throwing(Throwing &&) noexcept(false) = default;
};

struct Derived : Base
{
  Throwing t;

  Derived(Derived &&) noexcept(
      std::is_nothrow_move_constructible_v<Base> &&
      std::is_nothrow_move_constructible_v<Throwing>);
};

int main()
{
  std::cout << std::boolalpha;

  std::cout << std::is_nothrow_move_constructible_v<Derived> << '\n';
}
