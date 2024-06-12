#pragma once

#include <string>
#include <iostream>

class Person
{
public:
  Person(const char *n) : m_name{n} {}

  Person(const Person &p)
      : m_name(p.m_name)
  {
    std::cout << "COPY " << m_name << '\n';
  }

  Person(Person &&p) noexcept
      : m_name(std::move(p.m_name))
  {
    std::cout << "MOVE " << m_name << '\n';
  }

  std::string getName() const
  {
    return m_name;
  }

private:
  std::string m_name{};
};
