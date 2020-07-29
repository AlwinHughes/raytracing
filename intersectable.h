#ifndef INTERSECTABLE 
#define INTERSECTABLE 

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"

class Intersectable {

  public:
    virtual std::string toString() const = 0;
    virtual bool hasPositiveInter(const Ray&) const = 0;
    virtual Intersection getPosInter(const Ray&) const = 0;
    Renderable* parent;
    float epsilon = 0.0001;
};
#endif
