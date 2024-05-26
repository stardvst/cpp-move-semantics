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

  std::string getName() const
  {
    return m_name;
  }

  friend std::ostream &operator<<(std::ostream &strm, const Customer &cust)
  {
    strm << "[ " << cust.m_name << ": ";
    for (int val : cust.m_values)
      strm << val << ' ';
    strm << ']';
    return strm;
  }

  Customer(const Customer &cust)
      : m_name{cust.m_name}, m_values{cust.m_values}
  {
    std::cout << "COPY " << cust.m_name << '\n';
  }

  Customer(Customer &&cust) // noexcept missing
      : m_name{std::move(cust.m_name)}, m_values{std::move(cust.m_values)} // what default generated one would do
  {
    std::cout << "MOVE " << m_name << '\n';
  }

  Customer &operator=(const Customer &cust)
  {
    std::cout << "COPYASSIGN " << cust.m_name << '\n';
    if (this != &cust)
    {
      m_name = cust.m_name;
      m_values = cust.m_values;
    }
    return *this;
  }

  Customer &operator=(Customer &&cust) // noexcept missing
  {
    std::cout << "MOVEASSIGN " << cust.m_name << '\n';

    if (this != &cust)
    {
      // what default generated one would do
      m_name = std::move(cust.m_name);
      m_values = std::move(cust.m_values);
    }
    return *this;
  }

private:
  std::string m_name{};
  std::vector<int> m_values{};
};
