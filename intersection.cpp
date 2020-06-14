#include "intersection.h"
#include <sstream>


std::string Intersection::toString() {
  std::ostringstream ss;
  ss << "Intersection| at: " << pos.toString() << " on sphere: " << &sphere;
  return ss.str();
}
