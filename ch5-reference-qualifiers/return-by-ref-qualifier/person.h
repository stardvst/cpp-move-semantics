#pragma once

#include <string>
#include <iostream>

class Person
{
public:
  Person(std::string n) : name(std::move(n)) {}

  std::string getName() && // when we no longer need the value of `this`
  {
    std::cout << "std::string () &&: ";
    return std::move(name); // we steal and return by value
  }

  const std::string &getName() const & // in all other cases
  {
    std::cout << "const std::string & () const &: ";
    return name; // we give access to the member
  }

private:
  std::string name{};
};
