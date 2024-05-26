#include "customer.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<Customer> customers;
  //customers.reserve(12);

  for (int i = 0; i < 12; ++i)
    customers.push_back(Customer{"TestCustomer " + std::to_string(i - 5)});

  std::cout << "---- sort():\n";
  std::sort(customers.begin(), customers.end(),
            [](const Customer &c1, const Customer &c2)
            { return c1.getName() < c2.getName(); });
}
