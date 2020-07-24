#ifndef CONTROLER
#define CONTROLER

#include "vector3.h"
#include "renderable.h"
#include "intersection.h"
#include "light_col.h"
#include "fixedsceene.h"
#include "ray.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class Controler {

  private:
    Vector3 cam_pos;
    Vector3 cam_direc;
    FixedSceene& sceene;
    LightCol getColAtInter(Intersection, Ray, int, int);


  public:
    std::string toString();
    void render(LightCol** raw_cols, int width, int height, float dy, float dz, int max_bounce = 1, int rays_per_pixel = 1, int difuse_rays = 0);
    void setSceene(const FixedSceene& s) { sceene = s;};
    void setCamPos(Vector3 p) { cam_pos = p;};
    void setCamDirec(Vector3 d) { cam_direc = d;};
    Controler(FixedSceene& s) : sceene(s) {};

};
#endif
