#include "rsphere.h"

png::rgb_pixel RSphere::getColAtInter(Intersection* inter, Ray insident_ray, FixedSceene* sceene) {

  //std::cout << "found rsphere" << std::endl;

  Ray reflection = Ray(
      inter->pos, 
      insident_ray.grad + inter->normal * (-2) * (insident_ray.grad.Dot(inter->normal))
      );

  Intersection* reflection_hit = sceene->getClosestInter(reflection, inter->pos, this);

  if(reflection_hit) {
    return sceene->getColAtInter(reflection_hit, reflection);
  } else {
    return sceene->default_color;
  }

  /*
  if(sceene->isInShade(inter)) {
    return shade_pixel_col;
  }

  Ray light = sceene->getRayFromLight(inter->pos);

  float m = (light.grad.normalize().invert()).Dot(inter->normal);

  return png::rgb_pixel( (int) pixel_col.red * m, (int) pixel_col.green * m, (int) pixel_col.blue * m);
  */


};

