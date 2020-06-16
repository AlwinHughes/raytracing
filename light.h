#ifndef LIGHT
#define LIGHT

#include <sstream>
#include "vector3.h"

class Light {
  public:
    float brightness;
    Vector3 pos;
    Light(Vector3, float);
    Light(Vector3);
    std::string toString();
};

#endif
