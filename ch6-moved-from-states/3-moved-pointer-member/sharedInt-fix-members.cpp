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

  std::string asString() const
  {
    return std::to_string(*m_sp);
  }

  std::string asString_FIX1() const
  {
    return m_sp ? std::to_string(*m_sp) : std::string{};
  }

  std::string asString_FIX2() const
  {
    if (!m_sp)
      throw std::runtime_error{"No value."};
    return std::to_string(*m_sp);
  }

  std::string asString_FIX3() const
  {
    assert(!m_sp);
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

  SharedInt si3{std::move(si1)};
  // std::cout << si1.asString() << '\n'; // crash

  std::cout << si1.asString_FIX1() << '\n';
  try { std::cout << si1.asString_FIX2() << '\n'; } catch (...) {}
  //std::cout << si1.asString_FIX3() << '\n'; // assert
}
