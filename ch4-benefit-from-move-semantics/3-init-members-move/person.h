#pragma once

#include <string>

class Person
{
public:
  Person(std::string f, std::string l)
      : first{std::move(f)}, last{std::move(l)}
  {
  }

private:
  std::string first;
  std::string last;
};
