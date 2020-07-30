#ifndef FLATMAT 
#define FLATMAT 

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>

class FlatMaterial : public Material {

  public:
    FlatMaterial(LightCol c) : Material(c) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const { 
      return color; 
    };
    std::string toString() const { 
      std::ostringstream ss;
      ss << "Flat Material " << color.toString(); 
      return ss.str();
    };
};

#endif
