#ifndef DIFUSEMAT
#define DIFUSEMAT

#include "intersection.h"
#include "ray.h"
#include "vector3.h"
#include "intersection.h"
#include "fixedsceene.h"
#include "light_col.h"
#include "material.h"
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class DifuseMat : public Material {

  private:
    float difuseion;
    int max_bounce;
    int max_difuse_rays;

  public:
    DifuseMat(LightCol c) : Material(c) {
      max_difuse_rays = 1;
      max_bounce = 3;
      difuseion = 1;
      //std::cout << "bounces " << max_bounce << std::endl;
    };
    int getMaxBounce() { return max_bounce; };
    DifuseMat(LightCol c, float d) : 
      Material(c), difuseion(d), max_bounce(2), max_difuse_rays(4) {};
    DifuseMat(LightCol c, float d, int bounce, int num_dif) : Material(c), difuseion(d), max_bounce(bounce), max_difuse_rays(num_dif) {};
    Ray getRay(const Intersection& inter, const Ray& f) const { return Ray(inter.normal, inter.normal); };
    LightCol getColAtInter(const Intersection&, const Ray&) const;
    std::string toString() const;
};
#endif
