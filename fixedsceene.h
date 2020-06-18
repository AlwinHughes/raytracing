#ifndef FIXEDSCEENE
#define FIXEDSCEENE

#include "vector3.h"
#include "ray.h"
#include "intersection.h"
#include "renderable.h"
#include "light.h"
#include "light_col.h"
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
    Intersection getClosestInter(Ray, Vector3);
    Intersection getClosestInter(Ray, Vector3,Renderable*);
    bool isInShade(Intersection);
    std::string toString();
    LightCol default_color = LightCol(0,0,0);
    LightCol getColAtInter(Intersection,Ray);
    Ray getRayFromLight(Vector3);

};
#endif
