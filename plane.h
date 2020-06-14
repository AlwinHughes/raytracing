
#ifndef PLANE
#define PLANE
#include "vector3.h"
#include "ray.h"

class Plane {
  private:
    Vector3 normal;
    float d;

  public:
    Plane(Vector3 n, float s) {
      normal = n;
      d = s;
    };
    std::string toString ();
    Vector3 intersectRay(Ray);

};
#endif
