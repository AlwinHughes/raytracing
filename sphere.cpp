#include "sphere.h"
#include <sstream>
#include <math.h>


Sphere::Sphere() : Renderable() {};

Sphere::Sphere(Vector3 c, float ra) {
  center = c;
  r = ra;
};

Sphere::Sphere(Vector3 c, float ra, png::rgb_pixel col) {
  center = c;
  r = ra;
  pixel_col = col;
};

Sphere::Sphere(Vector3 c, float ra, png::rgb_pixel col, bool can_occ, bool can_self_occ) {
  center = c;
  r = ra;
  pixel_col = col;
  can_occlude = can_occ;
  can_self_occulde = can_self_occ;
};


std::string Sphere::toString () {
  std::ostringstream ss;

  ss << "Circle: center " << center.toString() << " radius: " << r;

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


Intersection* Sphere::getPosInter(Ray ray) {
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
    return new Intersection(this, ray.pos(t2));
  } else if(t1 > epsilon) {
    return new Intersection(this, ray.pos(t1));
  } else {
    return NULL;
  }
  
}

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


  //using epsilon to check for already being on the surface


  if(t2 > 0) {
    return new Intersection(this, ray.pos(t2));
  } else if(t1 > epsilon) {
    return new Intersection(this, ray.pos(t1));
  } else {
    return NULL;
  }
  
}

bool Sphere::hasPositiveInter(Ray ray) {
  float a = ray.grad.Dot(ray.grad);

  Vector3 one(1,1,1);

  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;
  float t1 = (-b + descriminant)/(2 * a);

  return descriminant > 0 && t1 > 0;
};


bool Sphere::doesIntersect(Ray ray) {
  float a = ray.grad.Dot(ray.grad);

  Vector3 one(1,1,1);

  Vector3 start_minus_center = (ray.start - center);

  float b = start_minus_center.Dot(ray.grad) * 2;

  float c = start_minus_center.Dot(start_minus_center) - r*r;


  float descriminant = b*b - 4 * a * c;

  return descriminant >= 0;

}

png::rgb_pixel Sphere::getColAtInter(Intersection* inter, Ray insident_ray, FixedSceene* sceene) {

  if(sceene->isInShade(inter)) {
    return shade_pixel_col;
  } else {
    return pixel_col;
  }


}



