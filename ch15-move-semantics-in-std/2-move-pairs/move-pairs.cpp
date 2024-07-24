#include <string>
#include <iostream>
#include <filesystem>

int main()
{
  std::pair<std::string, std::string> p1{"some value", "some other value"};
  auto p2{p1};
  auto p3{std::move(p1)};

  std::cout << "p1: " << p1.first << '/' << p1.second << '\n';
  std::cout << "p2: " << p2.first << '/' << p2.second << '\n';
  std::cout << "p3: " << p3.first << '/' << p3.second << '\n';

  // with universal/forwarding references
  int val = 42;
  std::string s1{"value of s1"};
  std::pair<std::string, std::string> p4{std::to_string(val), std::move(s1)};

  std::cout << "s1: " << s1 << '\n';
  std::cout << "p4: " << p4.first << '/' << p4.second << '\n';

  // type conversion
  std::pair<const char *, std::string> p5{"path", "tmp/sub"};
  std::pair<std::string, std::filesystem::path> p6{std::move(p5)};

  std::cout << "p5: " << p5.first << '/' << p5.second << '\n';
  std::cout << "p6: " << p6.first << '/' << p6.second << '\n';
}
