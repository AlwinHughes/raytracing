#include "mplane.h"


LightCol MPlane::getColAtInter(Intersection inter, Ray insident_ray, FixedSceene* sceene) {


  Ray reflection = Ray(
      inter.pos,
      insident_ray.grad + normal * (-2) * (insident_ray.grad.Dot(normal))
  );

  Intersection reflection_hit = sceene->getClosestInter(reflection, inter.pos, this);

  if(!reflection_hit.isEmpty()) {
    return pixel_col.reflect(sceene->getColAtInter(reflection_hit, reflection));
  } else {
    return sceene->default_color;
  }
}
