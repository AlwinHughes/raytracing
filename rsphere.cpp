#include "rsphere.h"

LightCol RSphere::getColAtInter(Intersection inter, Ray insident_ray, FixedSceene* sceene) {

  //std::cout << "found rsphere" << std::endl;

  Ray reflection = Ray(
      inter.pos, 
      insident_ray.grad + inter.normal * (-2) * (insident_ray.grad.Dot(inter.normal))
      );

  Intersection reflection_hit = sceene->getClosestInter(reflection, inter.pos, this);

  if(!reflection_hit.isEmpty()) {
    return inter.hit_object->pixel_col.reflect(sceene->getColAtInter(reflection_hit, reflection));
  } else {
    return sceene->default_color;
  }

};

