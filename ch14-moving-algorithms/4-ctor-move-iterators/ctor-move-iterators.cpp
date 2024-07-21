#include <iostream>
#include <string>
#include <vector>
#include <list>

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
  std::vector<std::string> src{"don't", "vote", "for", "liars"};
  print("src", src);

  std::list<std::string> dest{std::make_move_iterator(src.begin()), std::make_move_iterator(src.end())};
  print("src", src);
  print("dest", dest);
}
