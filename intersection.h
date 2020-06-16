#ifndef INTERSECTION
#define INTERSECTION

#include <sstream>
#include "vector3.h"
#include "intersection.h"

class Renderable;

class Intersection {

  public:
    Renderable* hit_object;
    Vector3 pos;
    Vector3 normal;
    Intersection(Renderable* hit, Vector3 p) {
      hit_object = hit;
      pos = p;
    };
    Intersection(Renderable* hit, Vector3 p, Vector3 n) {
      hit_object = hit;
      pos = p;
      normal = n;
    };
    std::string toString();

};
#endif
