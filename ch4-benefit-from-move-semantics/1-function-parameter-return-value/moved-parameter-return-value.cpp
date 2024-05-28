#include "customer.h"
#include <iostream>
#include <vector>

std::vector<Customer> customers;

void foo(const Customer &cust)
{
  customers.push_back(cust);
}

void foo(Customer &&cust)
{
  customers.push_back(std::move(cust));
}

Customer getCustomer()
{
  Customer cust{"TestCustomer 3"};
  return std::move(cust);

  // correct, will optimize even move!
  // return cust;
}

int main()
{
  customers.reserve(10);

  std::cout << "pass by const &\n";
  Customer cust1{"TestCustomer 1"};
  foo(cust1);
  // correct:
  // foo(std::move(cust));

  std::cout << "\npass by &&\n";
  foo(Customer{"TestCustomer 2"});

  std::cout << "\nget by move()\n";
  auto cust3 = getCustomer();
}
