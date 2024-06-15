#include <iostream>
#include <type_traits>
#include "is_nothrow_moveable.h"

class Base
{
public:
  virtual ~Base() = default;
  virtual void print() const = 0;

protected:
  Base(const Base &) = default;
  Base(Base &&) = default;

  Base &operator=(const Base &) = delete;
  Base &operator=(Base &&) = delete;

private:
  std::string id{};
};

class Derived : public Base
{
public:
  Derived(Derived &&) noexcept(is_nothrow_movable_v<Base>);
};

int main()
{
  std::cout << std::boolalpha;

  std::cout << std::is_nothrow_move_constructible_v<Base> << '\n';
  std::cout << is_nothrow_movable_v<Base> << '\n';

  std::cout << std::is_nothrow_move_constructible_v<Derived> << '\n';
  std::cout << is_nothrow_movable_v<Derived> << '\n';
}
