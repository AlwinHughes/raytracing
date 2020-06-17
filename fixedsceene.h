#ifndef FIXEDSCEENE
#define FIXEDSCEENE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "light.h"
#include <png++/png.hpp>

using namespace png;

class FixedSceene {

  private:
    Renderable** renderable_objs;
    int curr_num_obj;
    Light* light;

  public:
    int max_num_objs;
    FixedSceene(int);
    FixedSceene(Renderable**, int);
    void addRenderable(Renderable*);
    void setLight(Light*);
    bool hasPositiveInter(Ray);
    Intersection* getClosestInter(Ray, Vector3);
    bool isInShade(Intersection*);
    std::string toString();
    rgb_pixel default_color = rgb_pixel(0,0,0);
    rgb_pixel getColAtInter(Intersection*,Ray);


};
#endif
