#include <iostream>
#include <string>

void process(const std::string &)
{
  std::cout << "process(const std::string &)\n";
}

void process(std::string &)
{
  std::cout << "process(std::string &)\n";
}

void process(std::string &&)
{
  std::cout << "process(std::string &&)\n";
}

///

const std::string &computeConstLRef(const std::string &str)
{
  return str;
}

std::string &computeLRef(std::string &str)
{
  return str;
}

std::string &&computeRRef(std::string &&str)
{
  return std::move(str);
}

std::string computeValue(const std::string &str)
{
  return str;
}

// below two disable move semantics by return const
const std::string computeConstValue(const std::string &str)
{
  return str;
}

const std::string &&computConstRRef(std::string &&str)
{
  return std::move(str);
}

int main()
{
  std::string str{"lvalue"};

  auto &&ret1 = computeRRef("tmp");
  // ...
  process(std::forward<decltype(ret1)>(ret1));

  auto &&ret2{computeRRef(std::move(str))};
  // ...
  process(std::forward<decltype(ret2)>(ret2));

  auto &&ret3{computeValue("tmp")};
  // ...
  process(std::forward<decltype(ret3)>(ret3));
}
