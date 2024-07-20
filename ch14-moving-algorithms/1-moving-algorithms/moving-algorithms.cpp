#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
void print(const std::string &name, const T &coll)
{
  std::cout << name << " (" << coll.size() << " elems): ";
  for (const auto &elem : coll)
    std::cout << " '" << elem << "'";
  std::cout << '\n';
}

int main()
{
  std::list<std::string> coll1{"love", "is", "all", "you", "need"};
  std::vector<std::string> coll2;
  coll2.resize(coll1.size());
  print("coll1", coll1);
  print("coll2", coll2);

  std::cout << "---\n";
  std::move(coll1.begin(), coll1.end(), coll2.begin());
  print("coll1", coll1);
  print("coll2", coll2);

  std::cout << "---\n";
  std::move_backward(coll2.begin(), coll2.begin() + 3, coll2.end());
  print("coll1", coll1);
  print("coll2", coll2);
}
