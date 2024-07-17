#include <iostream>
#include <utility>
#include <vector>

class MoveOnly
{
public:
  MoveOnly() = default;
  MoveOnly(std::string d) : data(std::move(d)) {}

  // copying disabled
  MoveOnly(const MoveOnly &) = delete;
  MoveOnly &operator=(const MoveOnly &) = delete;

  // moving enabled
  MoveOnly(MoveOnly &&) noexcept = default;
  MoveOnly &operator=(MoveOnly &&) noexcept = default;

  std::string data;
};

// pass ownership to the caller
MoveOnly source()
{
  MoveOnly mo{"str"};
  // ...
  return mo;
}

int main()
{
  MoveOnly mo{source()};
  std::cout << mo.data << '\n';
}
