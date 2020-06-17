#ifndef PLANE
#define PLANE
#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include <png++/png.hpp>

class Plane : public Renderable {
  private:
    Vector3 normal;
    float d;

  public:
    Plane(Vector3 n, float s, png::rgb_pixel pixel) {
      normal = n;
      d = s;
      pixel_col = pixel;
    };
    std::string toString();
    bool hasPositiveInter(Ray);
    Intersection* getPosInter(Ray);
    Vector3 intersectRay(Ray);
    png::rgb_pixel getColAtInter(Intersection*, Ray, FixedSceene*);

};
#endif
