#include "polygon.h"

int main()
{
  Polygon p1{"Poly1", {Coord{1, 1}, Coord{1, 9}, Coord{9, 9}, Coord{9, 1}}};
  Polygon p2{p1};
  Polygon p3{std::move(p1)};

  p1.draw();
  p2.draw();
  p3.draw();
}
