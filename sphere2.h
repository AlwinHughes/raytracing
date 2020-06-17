#ifndef SPHERE2
#define SPHERE2

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "fixedsceene.h"
#include "sphere.h"
#include <png++/png.hpp>

class Sphere2 : public Sphere {

  private:
    png::rgb_pixel shade_pixel_col = png::rgb_pixel(0,0,0);

  public:
    Sphere2() {};
    Sphere2(Vector3 c, float r) : Sphere(c, r) {};
    Sphere2(Vector3 c, float r, png::rgb_pixel p) : Sphere(c, r, p) {};
    Sphere2(Vector3 c, float r, png::rgb_pixel p,bool occ, bool self_occ) : Sphere(c,r,p,occ,self_occ) {};
    png::rgb_pixel getColAtInter(Intersection*, Ray, FixedSceene*);


};
#endif
