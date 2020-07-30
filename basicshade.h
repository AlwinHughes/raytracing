#ifndef BASICSHADE
#define BASICSHADE

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>

class BasicShade : public Material {

  private:
    float shade_factor;

  public:
    BasicShade(LightCol c, float f) : Material(c), shade_factor(f) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const;
    std::string toString() const;
};
#endif
