#include "customer.h"
#include <iostream>
#include <random>
#include <utility>

int main()
{
  Customer c{"Wolfgang Amadeus Mozart"};
  for (int val : {0, 8, 15})
    c.addValue(val);
  std::cout << "c: " << c << '\n';

  std::vector<Customer> customers;
  customers.push_back(c);
  customers.push_back(std::move(c));
  std::cout << "c: " << c << '\n';

  for (const auto &cust : customers)
    std::cout << ' ' << cust << '\n';
}
