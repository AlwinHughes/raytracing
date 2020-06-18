#ifndef SPHERE
#define SPHERE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "light_col.h"
#include "fixedsceene.h"
#include <png++/png.hpp>

class Sphere : public Renderable {

  private:
    Vector3 center;
    float r;
    //used for detecting self intersection
    float epsilon = 0.0000001;

  public:
    std::string toString();
    std::pair<float,float> intersectRay(Ray);
    Intersection getPosInter(Ray);
    bool doesIntersect(Ray);
    bool hasPositiveInter(Ray);
    Intersection getInter(Ray);
    Sphere();
    Sphere(Vector3, float);
    Sphere(Vector3, float, LightCol);
    Sphere(Vector3, float, LightCol,bool, bool);
    virtual LightCol getColAtInter(Intersection, Ray, FixedSceene*);

};
#endif
