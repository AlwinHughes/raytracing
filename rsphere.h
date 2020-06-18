#ifndef RSPHERE
#define RSPHERE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "fixedsceene.h"
#include "sphere.h"
#include <png++/png.hpp>
#include "light_col.h"

class RSphere : public Sphere {

  public:
    RSphere() {};

    RSphere(Vector3 c, float r) : Sphere(c, r, LightCol(1,1,1)) {};
    RSphere(Vector3 c, float r, LightCol lc) : Sphere(c, r, lc) {};

    //construct perfect mirror
    RSphere(Vector3 c, float r, bool occ, bool self_occ) : 
      Sphere(c,r,LightCol(1,1,1),occ,self_occ) {};

    RSphere(Vector3 c, float r, bool occ, bool self_occ, LightCol tint_col) : 
      Sphere(c,r,tint_col,occ,self_occ) {};


    LightCol getColAtInter(Intersection*, Ray, FixedSceene*);

};
#endif
