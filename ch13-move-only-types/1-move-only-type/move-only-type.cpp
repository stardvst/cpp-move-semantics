#include <iostream>
#include <utility>
#include <vector>

class MoveOnly
{
public:
  MoveOnly(std::string d) : data(std::move(d)) {}

  // copying disabled
  MoveOnly(const MoveOnly &) = delete;
  MoveOnly &operator=(const MoveOnly &) = delete;

  // moving enabled
  MoveOnly(MoveOnly &&) noexcept = default;
  MoveOnly &operator=(MoveOnly &&) noexcept = default;

  std::string data;
};

int main()
{
  std::vector<MoveOnly> coll;

  coll.push_back(MoveOnly{"str1"});

  MoveOnly mo{"str2"};

  // coll.push_back(mo); // ERROR: can't copy mo
  coll.push_back(std::move(mo));

  mo = std::move(coll[0]);
  std::cout << "coll:\n";
  for (auto &elem : coll)
    std::cout << elem.data << '\n';
  std::cout << "mo: " << mo.data << '\n';

  // move all elements
  std::vector<MoveOnly> coll2;
  for (auto &elem : coll)
    coll2.push_back(std::move(elem));

  std::cout << "---\ncoll:\n";
  for (auto &elem : coll)
    std::cout << elem.data << '\n';

  std::cout << "---\ncoll2:\n";
  for (auto &elem : coll2)
    std::cout << elem.data << '\n';
}
