#include <iostream>

struct C
{
  void foo() &
  {
    std::cout << "foo &\n";
  }

  void foo() const &
  {
    std::cout << "foo const &\n";
  }

  void foo() &&
  {
    std::cout << "foo &&\n";
  }

  void foo() const &&
  {
    std::cout << "foo const &&\n";
  }
};

int main()
{
  C x;
  x.foo();

  C{}.foo();
  std::move(x).foo();

  const C cx;
  cx.foo();
  std::move(cx).foo();
}
