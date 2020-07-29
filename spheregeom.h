#ifndef SPHEREGEOM
#define SPHEREGEOM

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "intersectable.h"

class SphereGeom : public Intersectable {

  private:
    Vector3 center;
    float r;

  public:
    std::string toString() const;
    SphereGeom(Vector3 c, float rad) : center(c), r(rad) {};
    bool hasPositiveInter(const Ray&) const;
    Intersection getPosInter(const Ray&) const;

};
#endif
