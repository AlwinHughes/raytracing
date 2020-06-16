#include "ray.h"
#include <sstream>

Vector3 Ray::pos (float t) {
  return start + (grad * t);
};


std::string Ray::toString() {
  std::ostringstream ss;
  ss << "Ray: starting: " << start.toString() << " grad: " << grad.toString();
  return ss.str();
};

bool Ray::containsPoint(Vector3 p) {
  p = p - start;

  if (p.Dot(grad) * p.Dot(grad) == (p.x * p.x + p.y * p.y + p.z * p.z)* (grad.x * grad.x + grad.y * grad.y + grad.z * grad.z)) {
    return true;
  };
  return false;
};

