#include "checkered_plane.h"

LightCol CPlane::getColAtInter(Intersection* inter, Ray r, FixedSceene* s) {

  if((int) inter->pos.x % 2  == 0 ^ (int) inter->pos.z % 2 == 0) {
    return checkered_col;
  } else {
    return pixel_col;
  }

};
