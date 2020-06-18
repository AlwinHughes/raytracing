#ifndef SPHERE2
#define SPHERE2

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "fixedsceene.h"
#include "sphere.h"
#include "light_col.h"
#include <png++/png.hpp>

class Sphere2 : public Sphere {

  private:
    LightCol shade_pixel_col = LightCol(0,0,0);

  public:
    Sphere2() {};
    Sphere2(Vector3 c, float r) : Sphere(c, r) {};
    Sphere2(Vector3 c, float r, LightCol p) : Sphere(c, r, p) {};
    Sphere2(Vector3 c, float r, LightCol p,bool occ, bool self_occ) : Sphere(c,r,p,occ,self_occ) {};
    LightCol getColAtInter(Intersection*, Ray, FixedSceene*);


};
#endif
