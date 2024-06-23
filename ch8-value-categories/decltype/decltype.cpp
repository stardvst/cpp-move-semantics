#include <iostream>
#include <string>

void rvFunc(std::string &&str)
{
  std::cout << std::boolalpha;
  std::cout << std::is_same_v<decltype(str), std::string> << '\n';
  std::cout << std::is_same_v<decltype(str), std::string &> << '\n';
  std::cout << std::is_same_v<decltype(str), std::string &&> << '\n';

  std::cout << std::is_reference_v<decltype(str)> << '\n';
  std::cout << std::is_lvalue_reference_v<decltype(str)> << '\n';
  std::cout << std::is_rvalue_reference_v<decltype(str)> << '\n';
}

int main()
{
  rvFunc(std::string{});
  std::cout << "---\n";

  std::string str;
  rvFunc(std::move(str));
}
