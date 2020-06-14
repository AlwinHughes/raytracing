#include "ray.h"
#include <sstream>

Vector3 Ray::pos (float t) {
  return start + (grad * t);
};


std::string Ray::toString() {
  std::ostringstream ss;
  ss << "starting: " << start.toString() << " grad: " << grad.toString();
  return ss.str();
};

