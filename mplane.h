#ifndef MPLANE
#define MPLANE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "plane.h"
#include "light_col.h"
#include "fixedsceene.h"
#include <png++/png.hpp>

class MPlane : public Plane {

  public:
    MPlane(Vector3 n, float s, LightCol  col) : Plane(n,s, col) {};
    LightCol getColAtInter(Intersection, Ray, FixedSceene*);

};
#endif
