/*
#ifndef CPLANE
#define CPLANE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "plane.h"
#include "light_col.h"
#include <png++/png.hpp>

class CPlane : public Plane {

  private:
    LightCol checkered_col = LightCol(0,0,0);

  public:
    CPlane(Vector3 n, float s, LightCol c) : Plane(n,s, c) {};
    LightCol  getColAtInter(Intersection*, Ray, FixedSceene*);

};
#endif
*/
