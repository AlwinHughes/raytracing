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
    Renderable* renderable_objs;
    int curr_num_obj;
    Light* lights;

  public:
    int max_num_objs;
    int max_num_lights;
    int curr_num_lights;
    FixedSceene(int, int);
    //FixedSceene(Renderable*, int, int);
    void addRenderable(Renderable);
    void addLight(Light);
    Light* getLights() { return lights; };
    bool isInShade(const Intersection&, Light*) const;
    bool hasPositiveInter(const Ray&) const;
    Intersection getClosestInter(const Ray&, Vector3) const;
    Intersection getClosestInter(const Ray&, Vector3, const Renderable*) const;
    std::string toString() const;
    LightCol default_color = LightCol(0,0,0);
    //Ray getRayFromLight(Vector3);

};
#endif
