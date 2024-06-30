#include <vector>
#include <string>
#include <iostream>

using Coll = std::vector<std::string>;

void bar(auto &&)
{
}

void fooOrdinary(Coll &&arg)
{
  Coll coll; // can't be const

  bar(std::move(arg)); // no need to forward
}

template <typename Coll>
void fooUniversal(Coll &&arg)
{
  using DecayedColl = typename std::decay<Coll>::type;
  DecayedColl coll; // This will be a non-reference, non-const-volatile type

  bar(std::forward<Coll>(arg)); // can't move, need to forward
}

int main()
{
  Coll v;
  const Coll c;

  //fooOrdinary(v);
  //fooOrdinary(c);
  fooOrdinary(Coll{});
  fooOrdinary(std::move(v));
  //fooOrdinary(std::move(c));

  ///

  std::vector<std::string> uv;
  const std::vector<std::string> uc;

  fooUniversal(uv);
  fooUniversal(uc);
  fooUniversal(Coll{});
  fooUniversal(std::move(uv));
  fooUniversal(std::move(uc));
}
