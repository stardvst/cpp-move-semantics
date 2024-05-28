#pragma once

#include <string>
#include <ostream>

class GeoObj
{
public:
  explicit GeoObj(std::string n)
      : name{std::move(n)}
  {
  }

  virtual ~GeoObj() = default; // disables move semantics for name
  virtual void draw() const = 0;

protected:
  // enable copy and move semantics (callable only for derived classes)
  GeoObj(const GeoObj &) = default;
  GeoObj(GeoObj &&) = default;

  // disable assignment operator (due to the problem of slicing)
  GeoObj &operator=(const GeoObj &) = delete;
  GeoObj &operator=(GeoObj &&) = delete;

protected:
  std::string name{};
};

struct Coord
{
  double x{};
  double y{};

  friend std::ostream &operator<<(std::ostream &strm, Coord c)
  {
    return strm << '(' << c.x << ',' << c.y << ')';
  }
};
