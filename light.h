#ifndef LIGHT
#define LIGHT

#include <sstream>
#include "vector3.h"
#include "light_col.h"

class Light {
  public:
    float brightness = 1;
    Vector3 pos;
    LightCol lc = LightCol(1,1,1);
    Light(Vector3, float);
    Light(Vector3, LightCol);
    Light(Vector3, LightCol, float);
    Light(Vector3);
    std::string toString();
};

#endif
