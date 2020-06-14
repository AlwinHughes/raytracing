#include "plane.h"
#include <sstream>
#include <math.h>

std::string Plane::toString() {


  std::ostringstream ss;
  ss << "normal" << normal.toString() << " d: " << d;
  return ss.str();
}

Vector3 Plane::intersectRay(Ray ray) {
  float grad_dot_normal = ray.grad.Dot(normal);

  if(grad_dot_normal == 0) {
    return Vector3(0,0,0);
  }

  float t = (d - (ray.start.Dot(normal)))/grad_dot_normal;

  return ray.pos(t);
}
