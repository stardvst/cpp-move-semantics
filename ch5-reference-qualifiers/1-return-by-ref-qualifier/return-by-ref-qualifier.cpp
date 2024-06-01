#include "person.h"
#include <iostream>
#include <vector>

Person returnPersonByValue()
{
  return Person{"Alice Cook"};
}

int main()
{
  Person p{"Ben Cook"};
  std::cout << p.getName() << '\n';
  std::cout << returnPersonByValue().getName() << '\n';

  std::vector<Person> people;
  people.push_back(Person{std::string{}});
  people.push_back(Person{"person with name"});

  for (const auto &person : people)
  {
    if (person.getName().empty())
      std::cout << "found empty name.\n";
  }

  std::cout << '\n';
  for (char c : returnPersonByValue().getName())
  {
    if (c == ' ')
      std::cout << "found empty char in name.\n";
  }
}
