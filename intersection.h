#ifndef INTERSECTION
#define INTERSECTION

#include <sstream>
#include "vector3.h"
#include "intersection.h"
#include <png++/png.hpp>

using namespace png;

class Renderable;

class Intersection {

  private:
    bool is_empty = true;

  public:
    Renderable* hit_object;
    Vector3 pos;
    Vector3 normal;
    int bounces = 0;
    Intersection() { is_empty = true; };
    Intersection(Renderable* hit, Vector3 p) {
      hit_object = hit;
      pos = p;
      is_empty = false;
    };
    Intersection(Renderable* hit, Vector3 p, Vector3 n) {
      hit_object = hit;
      pos = p;
      normal = n;
      is_empty = false;
    };
    std::string toString();
    bool isEmpty() { return is_empty; };
};
#endif
