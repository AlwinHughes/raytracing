#ifndef RAY
#define RAY

#include "vector3.h"

class Ray {

  public:
    Vector3 start;
    Vector3 grad;
    Vector3 pos(float);
    std::string toString ();
    Ray(Vector3 s, Vector3 g) {
      start = s;
      grad = g;
    };


};
#endif
