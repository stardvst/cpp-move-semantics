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

///

void callFoo(const X &arg)
{
  foo(arg);
}

void callFoo(X &arg)
{
  foo(arg);
}

void callFoo(X &&arg)
{
  foo(std::move(arg));
}

// not necessary
void callFoo(const X &&arg)
{
  foo(std::move(arg));
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
