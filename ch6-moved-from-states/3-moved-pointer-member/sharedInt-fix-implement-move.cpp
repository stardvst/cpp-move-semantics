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

  // implement move semantics
  SharedInt(SharedInt &&si)
      : m_sp{std::move(si.m_sp)}
  {
    si.m_sp = movedFromValue;
  }

  SharedInt &operator=(SharedInt &&si)
  {
    if (this != &si)
    {
      m_sp = std::move(si.m_sp);
      si.m_sp = movedFromValue;
    }
    return *this;
  }

  // and enable copy semantics, which were deleted due to user-declared move operations
  SharedInt(const SharedInt &) = default;
  SharedInt &operator=(const SharedInt &) = default;

  std::string asString() const
  {
    return std::to_string(*m_sp);
  }

private:
  std::shared_ptr<int> m_sp{};

  // special value for moved-from objects
  inline static std::shared_ptr<int> movedFromValue{std::make_shared<int>(0)};
};

int main()
{
  SharedInt si1{42};
  SharedInt si2{si1};
  std::cout << si1.asString() << '\n';

  SharedInt si3{std::move(si1)}; // uses copy
  std::cout << si1.asString() << '\n';
}
