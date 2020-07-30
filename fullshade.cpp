#include "fullshade.h"
#include <math.h>

std::string FullShade::toString() const {
  std::ostringstream ss;
  ss << "Full Shade " << color.toString(); 
  return ss.str();
};

LightCol FullShade::getColAtInter(const Intersection& inter, const Ray& ray) const { 

  /*
  if(inter.normal.Dot(ray.grad) > 0) {
    return LightCol(0,0,0);
  }
  */
  
  //we just care about the first light
  Light* lights = sceene->getLights();
  LightCol lc(0,0,0);

  for(int i = 0; i < sceene->curr_num_lights; i++) {

    Vector3 v = lights[i].pos - inter.pos;

    //std::cout << v.normalize().Dot(inter.normal) << std::endl;

    if(inter.normal.Dot(v) < 0) {
      //std::cout << "gz" << std::endl;
      continue;
    } 
    
    if(sceene->isInShade(inter, lights + i)) {
      continue;
    }
    

    lc = lc + color.reflect(lights[i].lc).scale(pow(v.normalize().Dot(inter.normal),power) * lights[i].brightness);
  }

  return lc;
};

