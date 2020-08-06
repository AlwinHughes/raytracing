#ifndef METALICMAT
#define METALICMAT

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>
#include "difusemat.h"

class MetalicMat : public Material {

  private:
    float metalic_param;
    float metal_weight;
    float shiny_weight;
    float shiny_param;

  public:
    MetalicMat(LightCol c) : 
      Material(c), metalic_param(0.2), shiny_param(20), metal_weight(0.5), shiny_weight(0.5) {};
    MetalicMat(LightCol c, float m, float s) : 
      Material(c), metalic_param(m), shiny_param(s), metal_weight(0.5), shiny_weight(0.5) {};
    MetalicMat(LightCol c, float m, float s, float m_w, float s_w) : Material(c), metalic_param(m), shiny_param(s), metal_weight(m_w), shiny_weight(s_w) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const;
    std::string toString() const;

};
#endif
