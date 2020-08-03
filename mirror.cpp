#include "mirror.h"
#include <math.h>

std::string MirrorMat::toString() const {
  std::ostringstream ss;
  ss << "Difuse mat " << color.toString(); 
  return ss.str();
};

LightCol MirrorMat::getColAtInter(const Intersection& inter, const Ray& ray) const {


  //std::cout << "mirro hit" << std::endl;

  Vector3 new_direc = ray.grad + (inter.normal * (ray.grad.Dot(inter.normal)) * (-2));
  
  Ray new_ray(inter.pos, new_direc);

  Intersection new_inter = sceene->getClosestInter(new_ray, inter.pos,this->parent);

  if(!new_inter.isEmpty()) {

    //std::cout << "mirror not empty" << std::endl;
    new_inter.bounces = inter.bounces;
    return color.reflect(new_inter.hit_object->material->getColAtInter(new_inter, new_ray));
  }
  return LightCol(0,0,0);
}
