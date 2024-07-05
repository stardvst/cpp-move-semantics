#include <iostream>
#include <string>

void iterate(std::string::iterator beg, std::string::iterator end)
{
  std::cout << "do non-const stuff with passed range\n";
}

void iterate(std::string::const_iterator beg, std::string::const_iterator end)
{
  std::cout << "do const stuff with passed range\n";
}

template <typename T>
void process(T &&coll)
{
  iterate(coll.begin(), coll.end());
}

int main()
{
  std::string v{"v"};
  const std::string c{"c"};

  process(v);
  process(c);
  process(std::string{"t"});
  process(std::move(v));
  process(std::move(c));
}
