
#ifndef SPHERE
#define SPHERE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include <png++/png.hpp>

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
    Sphere(Vector3, float, png::rgb_pixel);
    char char_col = '#';
    png::rgb_pixel pixel_col;
};
#endif
