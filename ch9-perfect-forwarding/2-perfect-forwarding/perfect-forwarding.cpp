#include <iostream>
#include <utility>

struct X
{
};

void foo(const X &)
{
  std::cout << "const X &\n";
}

void foo(X &)
{
  std::cout << "X &\n";
}

void foo(X &&)
{
  std::cout << "X &&\n";
}

/// just one caller now!

template <typename T>
void callFoo(T &&arg)
{
  foo(std::forward<T>(arg));
}

int main()
{
  X v;
  const X cv;

  foo(v);
  foo(cv);
  foo(X{});
  foo(std::move(v));
  foo(std::move(cv));

  std::cout << "---\n";

  callFoo(v);
  callFoo(cv);
  callFoo(X{});
  callFoo(std::move(v));
  callFoo(std::move(cv));
}
