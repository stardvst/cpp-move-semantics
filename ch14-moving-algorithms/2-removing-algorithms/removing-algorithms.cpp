#include "email.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<Email> coll{"tom@domain.de", "jill@company.com", "sarah@domain.de", "hana@company.com"};

  auto newEnd = std::remove_if(coll.begin(), coll.end(), [](const Email &e)
                               { auto &&val = e.getValue();
                               return val.size() > 2 && val.substr(val.size()-3)==".de"; });

  std::cout << "remaining elements:\n";
  for (auto pos = coll.begin(); pos != newEnd; ++pos)
    std::cout << "  '" << *pos << "'\n";

  std::cout << "all elements:\n";
  for (const auto &elem : coll)
    std::cout << "  '" << elem << "'\n";
}
