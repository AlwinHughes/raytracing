#include "sphere2.h"

LightCol Sphere2::getColAtInter(Intersection* inter, Ray insident_ray, FixedSceene* sceene) {

  if(sceene->isInShade(inter)) {
    return shade_pixel_col;
  }

  Ray light = sceene->getRayFromLight(inter->pos);

  float m = (light.grad.normalize().invert()).Dot(inter->normal);

  return pixel_col.scale(m);//LightCol( (int) pixel_col.red * m, (int) pixel_col.green * m, (int) pixel_col.blue * m);


}

