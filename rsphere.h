#ifndef RSPHERE
#define RSPHERE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "fixedsceene.h"
#include "sphere.h"
#include <png++/png.hpp>

class RSphere : public Sphere {

  public:
    RSphere() {};

    RSphere(Vector3 c, float r) : Sphere(c, r) {};

    RSphere(Vector3 c, float r, bool occ, bool self_occ) : 
      Sphere(c,r,png::rgb_pixel(0,0,0),occ,self_occ) {};


    png::rgb_pixel getColAtInter(Intersection*, Ray, FixedSceene*);

};
#endif
