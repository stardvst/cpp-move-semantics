#include <utility>
#include <iostream>
#include <string>

template <typename Func, typename ...Args>
decltype(auto) call(Func f, Args &&...args)
{
  // ...
  return f(std::forward<Args>(args)...);
}

std::string nextString()
{
  return "Let's dance";
}

std::ostream &print(std::ostream &strm, const std::string &val)
{
  return strm << "value: " << val;
}

std::string &&returnArg(std::string &&arg)
{
  return std::move(arg);
}

int main()
{
  auto s = call(nextString);

  auto &&ref = call(returnArg, std::move(s));
  std::cout << "s: " << s << '\n';
  std::cout << "ref: " << ref << '\n';

  std::cout << "---\n";
  auto str = std::move(ref);
  std::cout << "s: " << s << '\n';
  std::cout << "ref: " << ref << '\n';
  std::cout << "str: " << str << '\n';
}
