#pragma once

#include <iostream>
#include <string>

class IntString
{
public:
  explicit IntString(int i = 0) : m_ival{i}, m_sval{std::to_string(i)} {}

  void setValue(int i)
  {
    m_ival = i;
    m_sval = std::to_string(i);
  }

  void dump() const
  {
    std::cout << " [" << m_ival << "/'" << m_sval << "']\n";
  }

private:
  int m_ival{};
  std::string m_sval{};
};
