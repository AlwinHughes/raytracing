#ifndef PLANEGEOM
#define PLANEGEOM

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "intersectable.h"

class PlaneGeom : public Intersectable {

  private:
    Vector3 normal;
    float d;

  public:
    std::string toString() const;
    PlaneGeom(Vector3 n, float dee) : normal(n), d(dee) {};
    bool hasPositiveInter(const Ray&) const;
    Intersection getPosInter(const Ray&) const;

};
#endif
