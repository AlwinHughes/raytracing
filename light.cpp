#include "light.h"
#include <sstream>

Light::Light(Vector3 p, float b) {
  pos = p;
  brightness = b;
};
Light::Light(Vector3 p) {
  pos = p;
};

std::string Light::toString() {
  std::ostringstream ss;
  ss << "Light pos: " << pos.toString() << " brightness: " << brightness << std::endl;
  return ss.str();
}
