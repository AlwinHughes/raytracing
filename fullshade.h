#ifndef FULLSHADE
#define FULLSHADE

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>

class FullShade : public Material {

  private:
    float power = 1;

  public:
    FullShade(LightCol c) : Material(c) {};
    FullShade(LightCol c, float p) : Material(c), power(p) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const;
    std::string toString() const;
};
#endif
