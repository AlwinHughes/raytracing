/*
#include "plane.h"
#include <sstream>
#include <math.h>
std::string Plane::toString() {


  std::ostringstream ss;
  ss << "Plane with normal" << normal.toString() << " d: " << d;
  return ss.str();
};

Vector3 Plane::intersectRay(Ray ray) {
  float grad_dot_normal = ray.grad.Dot(normal);

  if(grad_dot_normal == 0) {
    return Vector3(0,0,0);
  }

  float t = (d - (ray.start.Dot(normal)))/grad_dot_normal;

  return ray.pos(t);
};

bool Plane::hasPositiveInter(Ray ray) {
  float grad_dot_normal = ray.grad.Dot(normal);

  if(grad_dot_normal == 0) {
    return false;
  }

  float t = (d - (ray.start.Dot(normal)))/grad_dot_normal;

  if(t > 0) {
    return true;
  }
  return false;
}

Intersection Plane::getPosInter(Ray ray) {
  
  //std::cout << "inter? " << normal.toString() << std::endl;
  float grad_dot_normal = ray.grad.Dot(normal);
  //std::cout << "inter " << grad_dot_normal << std::endl;


  if(grad_dot_normal == 0) {
    return Intersection();
  }

  float t = (d - (ray.start.Dot(normal)))/grad_dot_normal;

  //std::cout << t << std::endl;

  if(t < 0) {
    //std::cout << "behind";
    return Intersection();
  }


  return Intersection(this, ray.pos(t), normal);
}


LightCol Plane::getColAtInter(Intersection inter, Ray insident_ray, FixedSceene* sceene) {

  if(sceene->isInShade(inter)) {
    return shade_pixel_col; } else {
    return pixel_col;
  }

}
*/
