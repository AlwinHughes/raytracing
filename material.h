#ifndef MATERIAL
#define MATERIAL

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "fixedsceene.h"
#include "light_col.h"

class Material {

  public:
    virtual Ray getRay(const Intersection&, const Ray&) const = 0;
    virtual LightCol getColAtInter(const Intersection&, const Ray&) const = 0;
    LightCol color;
    virtual std::string toString() = 0;
    Material(LightCol c) : color(c) {};
};
#endif
