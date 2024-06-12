#include "person.h"
#include <iostream>
#include <vector>

int main()
{
  std::vector<Person> people{"wolfgang amadeus mozart", "johann sebastian bach", "ludwig van beethoven"};
  std::cout << "capacity: " << people.capacity() << '\n';

  // moves above 3 items during reallocation!
  people.push_back("pjotr iljitsch tschaikowski");
}
