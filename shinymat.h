#ifndef SHINYMAT
#define SHINYMAT

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>
#include "difusemat.h"

class ShinyMat: public DifuseMat {

  private:
    float shiny_param;

  public:
    ShinyMat(LightCol c) : DifuseMat(c), shiny_param(20) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const;
    std::string toString() const;
    ShinyMat(LightCol c, float d) : DifuseMat(c,d), shiny_param(20) {};
    ShinyMat(LightCol c, float d, int bounce, int num_dif) :  DifuseMat(c, d,bounce, num_dif), shiny_param(20) {};
    ShinyMat(LightCol c, float d, int bounce, int num_dif, float s) :  DifuseMat(c, d,bounce, num_dif), shiny_param(s) {};

};
#endif
