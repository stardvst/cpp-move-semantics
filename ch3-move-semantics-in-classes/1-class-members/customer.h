#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cassert>

class Customer
{
public:
  Customer(std::string name) : m_name(name)
  {
    assert(!m_name.empty());
  }

  void addValue(int val)
  {
    m_values.push_back(val);
  }

  friend std::ostream &operator<<(std::ostream &strm, const Customer &cust)
  {
    strm << "[ " << cust.m_name << ": ";
    for (int val : cust.m_values)
      strm << val << ' ';
    strm << ']';
    return strm;
  }

private:
  std::string m_name{};
  std::vector<int> m_values{};
};
