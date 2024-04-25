#include <string>
#include <vector>

std::vector<std::string> createAndInsert()
{
  std::vector<std::string> collection;
  collection.reserve(3);

  std::string s = "data";

  collection.push_back(s); // copy: ok
  collection.push_back(s + s); // temp + copy + destroy temp: not ok
  collection.push_back(s); // copy: not ok

  return collection; // nrvo: ok
}

int main()
{
  std::vector<std::string> v;
  v = createAndInsert(); // copy: not ok
}
