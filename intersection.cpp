#include "intersection.h"
#include "renderable.h"
#include <sstream>


std::string Intersection::toString() const {

  if(is_empty) {
    return "empty intersection";
  }

  std::ostringstream ss;

  ss << "Intersection| at: " << pos.toString() << " with normal " << normal.toString() << " on object: " << hit_object->toString();

  return ss.str();
};

unsigned long Intersection::num = 0;
