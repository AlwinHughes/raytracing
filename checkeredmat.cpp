#include "checkeredmat.h"
#include <math.h>


std::string CheckeredMat::toString() const {
  std::ostringstream ss;
  ss << "checkered mat with " << color.toString(); 
  return ss.str();
};

LightCol CheckeredMat::getColAtInter(const Intersection& inter, const Ray& ray) const { 

  if((int)floor(inter.pos.x) % 2 == 0 ^ (int) floor(inter.pos.z)  % 2 == 0) {
    return DifuseMat::getColAtInter(inter, ray);
  } 
  return LightCol(0,0,0);


}
