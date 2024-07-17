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

// takes ownership of passed argument
void sinkMe(MoveOnly arg)
{
}

// might take ownership of passed argument
void sinkMeMaybe(MoveOnly &&arg)
{
}

int main()
{
  {
    sinkMe(MoveOnly{}); // OK

    MoveOnly mo{"str"};
    // sinkMe(mo); // ERROR, can't copy mo to arg
    sinkMe(std::move(mo));
    std::cout << mo.data << '\n';

    // ensure mo's resource is no longer acquired/owned/open/running
  }

  {
    sinkMeMaybe(MoveOnly{}); // OK

    MoveOnly mo{"str"};
    // sinkMeMaybe(mo); // ERROR, can't copy mo to arg
    sinkMeMaybe(std::move(mo));
    std::cout << mo.data << '\n';

    // ensure mo's resource is no longer acquired/owned/open/running
  }
}
