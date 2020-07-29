#include "renderable.h"
#include "intersection.h"
#include <sstream>

std::string Renderable::toString() const {
  std::ostringstream ss;
  ss << "Geom " << geometry->toString() << " Mat " << material->toString();
  return ss.str();
};
