#include <iostream>
#include <string>
#include <cassert>

class Email
{
public:
  Email(std::string val) : value(std::move(val))
  {
    assert(value.find('@') != std::string::npos);
  }

  Email(const char *val)
      : Email(std::string{val})
  {
  }

  std::string getValue() const
  {
    assert(!movedFrom);
    return value;
  }

  // implement move operations to signal moved-from state
  Email(Email &&e) noexcept
      : value{std::move(e.value)}, movedFrom{e.movedFrom}
  {
    e.movedFrom = true;
  }

  Email &operator=(Email &&e) noexcept
  {
    value = std::move(e.value);
    movedFrom = e.movedFrom;
    e.movedFrom = true;
    return *this;
  }

  // enable copying
  Email(const Email &) = default;
  Email &operator=(const Email &) = default;

  // print current state
  friend std::ostream &operator<<(std::ostream &strm, const Email &e)
  {
    return strm << (e.movedFrom ? "MOVED-FROM" : e.value);
  }

private:
  std::string value;
  bool movedFrom{false};
};
