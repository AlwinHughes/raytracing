#ifndef LIGHTCOL
#define LIGHTCOL

#include "vector3.h"
#include <math.h>

struct LightCol {

  /*
   *
   * the color of an object must have red, green, blue
   * values that are between 0 and 1 for the reflection to make sense
   *
   * i think anyway . this might be wrong
   *
   *
   */

  float red,green,blue;

  inline LightCol(void) {};

  inline LightCol(const float r, const float g, const float b) {
    red = r; green = g; blue = b;
  };

  /*
  inline LightCol(const int r, const int g, const int b) {
    red = r/255.0; green = g/255.0; blue = b/255.0;
  };
  */

  inline LightCol operator + (const LightCol& L) const {
    return LightCol(red + L.red, green + L.green, blue + L.blue);
  };

  inline LightCol reflect(const LightCol& L) {
    return LightCol(red * L.red, green * L.green, blue * L.blue);
  }

  inline LightCol normalize() const {
    float inv = 1/sqrt(red*red + green*green + blue*blue);
    return LightCol(red*inv, green * inv, blue*inv);
  }

  inline LightCol scale(float s) {
    return LightCol(red * s, green * s, blue * s);
  }

};
#endif
