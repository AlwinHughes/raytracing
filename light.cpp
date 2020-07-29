#include "light.h"
#include <sstream>

Light::Light(Vector3 p, float b) {
  pos = p;
  brightness = b;
};

Light::Light(Vector3 p) {
  pos = p;
  lc = LightCol(1,1,1);
};

Light::Light(Vector3 p, LightCol c) {
  pos = p;
  lc = c;
};

Light::Light(Vector3 p, LightCol c, float b = 1) {
  pos = p;
  lc = c;
  brightness = b;
};

std::string Light::toString() {
  std::ostringstream ss;
  ss << "Light pos: " << pos.toString() << " brightness: " << brightness << std::endl;
  return ss.str();
};
