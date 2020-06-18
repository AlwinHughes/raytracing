#ifndef PLANE
#define PLANE
#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include <png++/png.hpp>
#include "light_col.h"

class Plane : public Renderable {
  protected:
    Vector3 normal;
    float d;

  public:
    Plane(Vector3 n, float s, LightCol pixel) {
      normal = n;
      d = s;
      pixel_col = pixel;
    };
    std::string toString();
    bool hasPositiveInter(Ray);
    Intersection getPosInter(Ray);
    Vector3 intersectRay(Ray);
    virtual LightCol getColAtInter(Intersection, Ray, FixedSceene*);

};
#endif
