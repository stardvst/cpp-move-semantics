#include <iostream>
#include <string>
#include <vector>
#include <chrono>

struct Str
{
  Str() : val(100, 'a') {}
  Str(const Str &) = default;

  Str(Str &&s) _NOEXCEPT
    : val{std::move(s.val)}
  {
  }

  std::string val;
};

int main()
{
  std::vector<Str> col;
  col.resize(1000000);

  auto t0 = std::chrono::steady_clock::now();
  col.reserve(col.capacity() + 1);
  auto t1 = std::chrono::steady_clock::now();

  std::chrono::duration<double, std::milli> d{t1 - t0};
  std::cout << d.count() << '\n';
}
