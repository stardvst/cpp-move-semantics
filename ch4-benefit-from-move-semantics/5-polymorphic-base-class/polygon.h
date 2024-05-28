#pragma once

#include "geoObj.h"
#include <vector>
#include <iostream>

class Polygon : public GeoObj
{
public:
  Polygon(std::string s, std::initializer_list<Coord> coords = {})
    : GeoObj{std::move(s)}, points{std::move(coords)}
  {
  }

  void draw() const override
  {
    std::cout << "polygon '" << name << "' over";
    for (auto &p : points)
    {
      std::cout << " " << p;
    }
    std::cout << "\n";
  }

protected:
  std::vector<Coord> points{};
};
