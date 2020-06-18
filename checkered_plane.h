#ifndef CPLANE
#define CPLANE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "plane.h"
#include <png++/png.hpp>

class CPlane : public Plane {

  private:
    png::rgb_pixel checkered_col = png::rgb_pixel(0,0,0);

  public:
    CPlane(Vector3 n, float s, png::rgb_pixel p) : Plane(n,s, p) {};
    png::rgb_pixel getColAtInter(Intersection*, Ray, FixedSceene*);

};
#endif
