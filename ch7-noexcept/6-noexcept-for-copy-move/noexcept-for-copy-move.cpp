#include <iostream>
#include <type_traits>

struct B
{
  std::string s;
};

struct C
{
  std::string s;

  C() = default;
  C(const C &) = default;
  C &operator=(const C &) = default;
  C(C &&) = default;
  C &operator=(C &&) = default;
};

int main()
{
  std::cout << std::boolalpha;

  std::cout << std::is_nothrow_default_constructible_v<B> << '\n';
  std::cout << std::is_nothrow_copy_constructible_v<B> << '\n';
  std::cout << std::is_nothrow_copy_assignable_v<B> << '\n';
  std::cout << std::is_nothrow_move_constructible_v<B> << '\n';
  std::cout << std::is_nothrow_move_assignable_v<B> << '\n';

  std::cout << "---\n";
  std::cout << std::is_nothrow_default_constructible_v<C> << '\n';
  std::cout << std::is_nothrow_copy_constructible_v<C> << '\n';
  std::cout << std::is_nothrow_copy_assignable_v<C> << '\n';
  std::cout << std::is_nothrow_move_constructible_v<C> << '\n';
  std::cout << std::is_nothrow_move_assignable_v<C> << '\n';
}
