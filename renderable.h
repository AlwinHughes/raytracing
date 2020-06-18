#ifndef RENDERABLE
#define RENDERABLE

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include <png++/png.hpp>
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"

class FixedSceene;

class Renderable {

  public:
    virtual std::string toString() = 0;
    virtual bool hasPositiveInter(Ray) = 0;
    virtual Intersection getPosInter(Ray) = 0;
    char char_col = '#';
    bool can_occlude = true;
    bool can_self_occulde = true;
    LightCol pixel_col;
    LightCol shade_pixel_col;
    Renderable(){};
    //std::string toString();
    virtual LightCol getColAtInter(Intersection, Ray, FixedSceene*) = 0;

};
#endif
