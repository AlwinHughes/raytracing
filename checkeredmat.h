#ifndef CHECKEREDMAT
#define CHECKEREDMAT

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>
#include "difusemat.h"

class CheckeredMat : public DifuseMat {


  public:
    CheckeredMat(LightCol c) : DifuseMat(c) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const;
    std::string toString() const;
    CheckeredMat(LightCol c, float d) : DifuseMat(c,d) {};
    CheckeredMat(LightCol c, float d, int bounce, int num_dif) :  DifuseMat(c, d,bounce, num_dif) {};

};
#endif
