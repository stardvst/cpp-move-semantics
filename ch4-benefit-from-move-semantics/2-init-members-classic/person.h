#pragma once

#include <string>

class Person
{
public:
  Person(const std::string &f, const std::string &l)
      : first{f}, last{l}
  {
  }

private:
  std::string first;
  std::string last;
};
