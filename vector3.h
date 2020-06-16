#include <sstream>

#ifndef VECTOR3
#define VECTOR3

struct Vector3 {

  float x;
  float y;
  float z;

  inline Vector3 (void) {};

  inline Vector3 (const float x1, const float y1, const float z1) {
    x = x1; y = y1; z = z1;
  };

  inline Vector3 operator + (const Vector3& A) const {
    return Vector3(x + A.x, y + A.y, z + A.z);
  };

  inline Vector3 operator + (const float A) const {
    return Vector3(x + A, y + A, z + A);
  };

  inline Vector3 operator - (const Vector3& A) const {
    return Vector3(x - A.x, y - A.y, z - A.z);
  };

  inline float Dot(const Vector3& A) const {
    return A.x * x + A.y * y + A.z * z;
  };
  
  inline Vector3 operator * (const float s) {
    return Vector3(x* s, y * s, z *s);
  };

  std::string toString() {
    std::ostringstream ss;
    ss << "(" << x << "," << y << "," << z << ")";
    return ss.str();

  };

  inline float squareDist() {
    return x*x + y*y + z*z;
  }
};

#endif
