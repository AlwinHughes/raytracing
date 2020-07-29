#include "intersection.h"
#include "renderable.h"
#include <sstream>


std::string Intersection::toString() {

  std::ostringstream ss;
  ss << "Intersection| at: " << pos.toString() << " on object: " << hit_object->toString();

  return ss.str();
};
