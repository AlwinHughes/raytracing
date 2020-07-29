#include "spheregeom.h"

Intersection SphereGeom::getPosInter(const Ray& ray) const {
  float a = ray.grad.Dot(ray.grad);


  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;

  if( descriminant < 0) {
    return Intersection();
  }

  descriminant = sqrt(descriminant);


  float t1 = (-b + descriminant)/(2 * a);
  float t2 = (-b - descriminant)/(2 * a);

  /*
   * we know that descrimant > 0 and that a > 0
   * so we know that t1 > t2 
   * we are interested in the closest intersection 
   * to the camera meaning which means the value of t
   * that is smallest but still positive
   *
   * if t2 > 0 then it will be the closest intersection
   * if it is not then if t1 > 0 then it is the closest
   *
   * if both are less than 0 then the object is 
   * behind the camera
   *
   */

  //std::cout << "t1: " << t1 << " t2: " << t2 << std::endl;

  if(t2 > 0) {
    Vector3 p = ray.pos(t2);
    return Intersection(parent, p, (p - center).normalize());
  } else if(t1 > epsilon) {
    Vector3 p = ray.pos(t1);
    return Intersection(parent, p, (p - center).normalize());
  } else {
    return Intersection();
  }
  
};


bool SphereGeom::hasPositiveInter(const Ray& ray) const {
  float a = ray.grad.Dot(ray.grad);


  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;
  float t1 = (-b + descriminant)/(2 * a);

  return descriminant > 0 && t1 > 0;
};


/*
bool SphereGeom::doesIntersect(const Ray& ray) const {
  float a = ray.grad.Dot(ray.grad);


  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;

  return descriminant >= 0;

};
*/


std::string SphereGeom::toString() const {
  std::ostringstream ss;

  ss << "Sphere: centered " << center.toString() << " radius: " << r;

  return ss.str();
};
