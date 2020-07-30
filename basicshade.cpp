#include "basicshade.h"

std::string BasicShade::toString() const {
  std::ostringstream ss;
  ss << "Basic Shade " << color.toString() << " shade factor " << shade_factor; 
  return ss.str();
};

LightCol BasicShade::getColAtInter(const Intersection& inter, const Ray& ray) const { 
  
  //we just care about the first light
  Light* light = sceene->getLights();

  if(sceene->isInShade(inter, light)) {
    return color.scale(shade_factor);
  }

  return color;
};

