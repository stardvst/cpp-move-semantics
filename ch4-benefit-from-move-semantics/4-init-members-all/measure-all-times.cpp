#include <chrono>
#include <iostream>
#include "person.h"

std::chrono::nanoseconds measure(int repeat)
{
  std::chrono::nanoseconds total;
  for (int i = 0; i < repeat; ++i)
  {
    std::string fname = "a firstname a bit too long for SSO";
    std::string lname = "a lastname a bit too long for SSO";

    auto t0 = std::chrono::steady_clock::now();
    Person p1{"a firstname too long for SSO", "a lastname too long for SSO"};
    Person p2{fname, lname};
    Person p3{std::move(fname), std::move(lname)};
    auto t1 = std::chrono::steady_clock::now();
    total += t1 - t0;
  }
  return total;
}

int main()
{
  int repeat = 1000;
  measure(5); // skip initial

  std::chrono::nanoseconds ns{measure(repeat)};
  std::chrono::duration<double, std::milli> ms{ns};

  std::cout << repeat << " iterations take: " << ms.count() << "ms\n";
  std::cout << "3 inits take on average: " << ns.count() / repeat << "ns\n";
}
