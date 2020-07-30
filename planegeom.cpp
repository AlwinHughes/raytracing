#include "planegeom.h"

#include <sstream>
#include <math.h>
std::string PlaneGeom::toString() const {


  std::ostringstream ss;
  ss << "Plane with normal" << normal.toString() << " d: " << d;
  return ss.str();
};


bool PlaneGeom::hasPositiveInter(const Ray& ray) const {
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

Intersection PlaneGeom::getPosInter(const Ray& ray) const {
  
  float grad_dot_normal = ray.grad.Dot(normal);

  if(grad_dot_normal == 0) {
    return Intersection();
  }

  float t = (d - (ray.start.Dot(normal)))/grad_dot_normal;


  if(t < 0) {
    return Intersection();
  }

  return Intersection(parent, ray.pos(t), normal);
}
