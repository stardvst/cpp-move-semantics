#include <memory>
#include <string>
#include <iostream>
#include <cassert>

class SharedInt
{
public:
  explicit SharedInt(int val) : m_sp(std::make_shared<int>(val))
  {
  }

  // disable move semantics
  SharedInt(const SharedInt &) = default;
  SharedInt &operator=(const SharedInt &) = default;

  std::string asString() const
  {
    return std::to_string(*m_sp);
  }

private:
  std::shared_ptr<int> m_sp{};
};

int main()
{
  SharedInt si1{42};
  SharedInt si2{si1};
  std::cout << si1.asString() << '\n';

  SharedInt si3{std::move(si1)}; // uses copy
  std::cout << si1.asString() << '\n';
}
