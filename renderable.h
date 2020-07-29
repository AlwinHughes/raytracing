#ifndef RENDERABLE
#define RENDERABLE

#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "intersectable.h"
#include "material.h"


class FixedSceene;

class Intersectable;
class Material;

class Renderable {

  public:
    bool can_occlude = true;
    bool can_self_occulde = true;
    Intersectable* geometry;
    Material* material;
    LightCol pixel_col;
    Renderable() {};
    Renderable(Intersectable* inter, Material* mat): geometry(inter), material(mat) {};
    std::string toString() const;
    //virtual LightCol getColAtInter(const Intersection&, const Ray&, const FixedSceene&) = 0;

};
#endif
