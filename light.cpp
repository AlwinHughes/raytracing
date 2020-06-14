#include "light.h"

Light::Light(Vector3 p, float b) {
  pos = p;
  brightness = b;
};
Light::Light(Vector3 p) {
  pos = p;
}

