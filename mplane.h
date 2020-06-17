#ifndef MPLANE
#define MPLANE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "plane.h"
#include <png++/png.hpp>

class MPlane : public Plane {

  public:
    MPlane(Vector3 n, float s, png::rgb_pixel pixel) : Plane(n,s, png::rgb_pixel(0,0,0)) {};
    png::rgb_pixel getColAtInter(Intersection*, Ray, FixedSceene*);

};
#endif
