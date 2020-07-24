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
    Light* light = NULL;
    Light** lights;

  public:
    int max_num_objs;
    int max_num_lights;
    int curr_num_lights;
    FixedSceene(int, int);
    FixedSceene(Renderable**, int, int);
    void addRenderable(Renderable*);
    void addLight(Light*);
    void setLight(Light*);
    Light* getLight() { return light; };
    Light** getLights() { return lights; };
    bool isInShade(Intersection, Light*);
    bool hasPositiveInter(Ray);
    Intersection getClosestInter(Ray, Vector3);
    Intersection getClosestInter(Ray, Vector3, Renderable*);
    bool isInShade(Intersection);
    std::string toString();
    LightCol default_color = LightCol(0,0,0);
    LightCol getColAtInter(Intersection,Ray);
    Ray getRayFromLight(Vector3);

};
#endif
