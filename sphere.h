
#ifndef SPHERE
#define SPHERE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"

class Sphere {
  private:
    Vector3 center;
    float r;

  public:
    std::string toString ();
    std::pair<float,float> intersectRay(Ray);
    bool doesIntersect(Ray);
    Intersection* getInter(Ray);
    Sphere();
    Sphere(Vector3, float);
    char char_col = '#';
};
#endif
