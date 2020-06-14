#ifndef INTERSECTION
#define INTERSECTION

#include <sstream>
#include "vector3.h"
//#include "sphere.h"

class Sphere;

class Intersection {

  public:
    Sphere* hit_object;
    Vector3 pos;
    Vector3 normal;
    Intersection(Sphere* hit, Vector3 p) {
      hit_object = hit;
      pos = p;
    };
    Intersection(Sphere* hit, Vector3 p, Vector3 n) {
      hit_object = hit;
      pos = p;
      normal = n;
    };
    std::string toString();

};


#endif
