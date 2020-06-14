#include "sphere.h"
#include <sstream>
#include <math.h>


Sphere::Sphere(){};

Sphere::Sphere(Vector3 c, float ra) {
  center = c;
  r = ra;
};

Sphere::Sphere(Vector3 c, float ra, png::rgb_pixel col) {
  center = c;
  r = ra;
  pixel_col = col;
};


std::string Sphere::toString () {
  std::ostringstream ss;

  ss << "center " << center.toString() << " radius: " << r;

  return ss.str();
};


std::pair<float,float> Sphere::intersectRay(Ray ray) {
  float a = ray.grad.Dot(ray.grad);

  Vector3 one(1,1,1);

  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;

  if( descriminant < 0) {
    return std::make_pair(0.0,0.0);
  }

  descriminant = sqrt(descriminant);

  float t1 = (-b + descriminant)/(2 * a);

  float t2 = (-b - descriminant)/(2 * a);

  return std::make_pair(t1,t2);
};


Intersection* Sphere::getInter(Ray ray) {
  float a = ray.grad.Dot(ray.grad);

  Vector3 one(1,1,1);

  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;

  if( descriminant < 0) {
    return NULL;
  }

  descriminant = sqrt(descriminant);

  
  float t1 = (-b + descriminant)/(2 * a);
  if(t1 > 0) {
    return new Intersection(this, ray.pos(t1));
  } else {
    return NULL;
  }
  
}


bool Sphere::doesIntersect(Ray ray) {
  float a = ray.grad.Dot(ray.grad);

  Vector3 one(1,1,1);

  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;

  return descriminant >= 0;

}


